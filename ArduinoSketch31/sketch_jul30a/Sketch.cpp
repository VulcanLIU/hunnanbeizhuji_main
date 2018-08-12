/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
#include <Wire.h>
#include "ComwithMotor.h"//电机
#include "ComwithRC.h"//遥控器
#include "ComwithDisplay.h"//显示器
#include "Kinematics.h"
/*End of auto generated code by Atmel studio */

//#define OLED_RESET 4

//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio
ComwithMotor CM;
ComwithRC RC;
ComwithDisplay CD;
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
	CD.systemInit();//和显示器通信开始
	delay(100);
	CM.begin();
	CD.displayMotors(CM.connectedtoL1Right(),CM.connectedtoL2Right(),CM.connectedtoR1Right(),CM.connectedtoR2Right());
	delay(1000);
}

void loop() {
  //// put your main code here, to run repeatedly:
	//pinMode(13,OUTPUT);
	//digitalWrite(13,i);
	//i=!i;
	////动力学部分
	Kinematics::output rpm;
	rpm = kin.getRPM(linear_vel_x, linear_vel_y, angular_vel_z);
	
	CM.SendAtoALL(rpm.motor1,rpm.motor2,rpm.motor3,rpm.motor4);
	
	if (refresh_cout>500)
	{
		CM.check();//检查电机是否在线
		
		String _str = "";
		_str += millis();
		CD.displayPOS(true);
		CD.displaySHOT(false);
		CD.displayMotors(true,true,false,true);
		CD.displayMsg(_str);
		refresh_cout = 0;
		Serial.println(millis());
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
			linear_vel_x = RC.getVX();
			linear_vel_y = RC.getVY();
			angular_vel_z = RC.getVZ();
			str1 = "";
		}
		else 
		{
			str1 +=c;
		}
	}
}