/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
#include <Wire.h>
#include "ComwithMotor.h"	//电机
#include "ComwithRC.h"		//遥控器
#include "ComwithDisplay.h"	//显示器
#include "ComwithShot.h"	//射击模块
#include "ComwithPOS.h"		//定位模块
#include "Kinematics.h"

/*End of auto generated code by Atmel studio */

//#define OLED_RESET 4

//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio
ComwithMotor CM;
ComwithRC RC;
ComwithDisplay CD;
ComwithShot CS;
ComwithPOS CP;

Kinematics kin(90,0.068,0.4,8);

void whichdisconnected();

float linear_vel_x = 0;
float linear_vel_y = 0;
float angular_vel_z = 0;
 
 bool i = true;
 String str1 = "";
 String main_str = "";
 int refresh_cout = 0;
 
void setup() {
	Serial.begin(9600);
	delay(1000);
	Serial.println("Begin");
	//开始和显示器通信
	CD.systemInit();
	
	delay(100);
	//开始和电机通信
	CM.begin();
	CD.displayMotors(CM.connectedtoL1Right(),CM.connectedtoL2Right(),CM.connectedtoR1Right(),CM.connectedtoR2Right());//显示器显示电机在线状态
	
	//开始和射球通信
	CS.begin();
	CD.displaySHOT(CS.connected);
	
	//开始和定位模块通信
	CP.begin();
	CD.displayPOS(CP.connected);
	
	delay(1000);
}

void loop() {
	//运动信息：遥控器->中枢->四个电机
	Kinematics::output rpm;
	rpm = kin.getRPM(RC.VX, RC.VY, angular_vel_z);
	CM.SendAtoALL(rpm.motor1,rpm.motor2,rpm.motor3,rpm.motor4);
	
	//定位信息：定位模块->中枢
	CP.getPOS();
	
	//射击信息：遥控器->中枢->射球模块
	if (RC.shot)
	{
		CS.SendXYPandSHOT(CP.X,CP.Y,CP.P);
		RC.shot = 0;
	}

	//自检信息：中枢->串口显示器
	if (refresh_cout>500)
	{
		CM.check();//检查电机
		CD.displayMotors(CM.connectedL1,CM.connectedL2,CM.connectedR1,CM.connectedR2);
		
		CP.check();//检查定位&显示坐标
		CD.displayPOS(CP.connected);
		CD.displayXYP(CP.X,CP.Y,CP.P);
		
		CS.check();//检查射球
		CD.displaySHOT(CS.connected);
		
		String _str = "";//显示Msg
		_str += millis();
		CD.displayMsg(_str);
		
		refresh_cout = 0;
	}
	refresh_cout++;
}

void serialEvent()
{
	while(Serial.available())
	{
		char c = Serial.read();
		if (c == '\n')
		{	
			Serial.println(str1);
			RC.recived(str1);
			str1 = "";
		}
		else 
		{
			str1 +=c;
		}
	}
}