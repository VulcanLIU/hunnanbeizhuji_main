/* 
* ComwithShot.cpp
*
* Created: 2018/8/12 17:55:28
* Author: Vulcan
*/


#include "ComwithShot.h"
#include "HardwareSerial.h"

// default constructor
ComwithShot::ComwithShot()
{
	
} //ComwithShot

void ComwithShot::begin()
{
	Wire.begin();
	Serial.println("ComwithShot begin!");
	
	Wire.beginTransmission(5);
	Wire.println("begin:");//发送给射球模块的时候 射球模块复位 摩擦轮电机启动
	Wire.endTransmission();
}

void ComwithShot::check()
{
	Serial.println("ComwithShot check!");
	
	Wire.begin();
	Wire.requestFrom(5,1);
	if(Wire.available())
	{
		int c = Wire.read();
		return c;
	}
}
