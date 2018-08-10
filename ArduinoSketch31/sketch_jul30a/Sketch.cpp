/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
#include <Wire.h>
#include "ComwithMotor.h"
#include "ComwithRC.h"
#include "ComwithDisplay.h"
#include "Kinematics.h"
/*End of auto generated code by Atmel studio */


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
void setup() {
	Serial.begin(9600);
	
	//显示器初始化
	CD.systemInit();
	
	//电机上电自检
	CD.displaySTR("initing:");
	
	CM.begin();
	if (CM.connectedRight())
	{
			CD.displaySTR("|Links to Motors done!|");
			Serial.println("|Links to Motors done!|");
	}
	else
	{
			whichdisconnected();
			CD.displaySTR("|Links to Motors done!|");
	}
	delay(1000);
}

void loop() {
  //// put your main code here, to run repeatedly:
	pinMode(13,OUTPUT);
	digitalWrite(13,i);
	i=!i;
	////动力学部分
	Kinematics::output rpm;
	rpm = kin.getRPM(linear_vel_x, linear_vel_y, angular_vel_z);
	
	CM.SendAtoALL(rpm.motor1,rpm.motor2,rpm.motor3,rpm.motor4);
	
	//Serial.print(rpm.motor1);
	//Serial.print("	");
	//Serial.print(rpm.motor2);
	//Serial.print("	");
	//Serial.print(rpm.motor3);
	//Serial.print("	");
	//Serial.println(rpm.motor4);
	CD.systemInfo();
	CD.displayWKST(true,true,true);
	delay(10);
	CD.displayXYP(5,5,5);
	delay(10);
	CD.displaySTR("SHOT");
	delay(10);
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

void whichdisconnected()
{
	if (!CM.connectedtoL1Right())
	{
		CD.displaySTR("L1 disconnect");
	}
	if (!CM.connectedtoL2Right())
	{
		CD.displaySTR("L2 disconnect");
	}
	if (!CM.connectedtoR1Right())
	{
		CD.displaySTR("R1 disconnect");
	}
	if (!CM.connectedtoR2Right())
	{
		CD.displaySTR("R2 disconnect");
	}
}