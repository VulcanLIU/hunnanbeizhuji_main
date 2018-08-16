/* 
* ComwithPOS.cpp
*
* Created: 2018/8/14 3:10:57
* Author: Vulcan
*/


#include "ComwithPOS.h"
#include "HardwareSerial.h"
#include "Wire.h"

// default constructor
ComwithPOS::ComwithPOS()
{

} //ComwithPOS

void ComwithPOS::begin()
{
	Wire.begin();
	Serial.println("ComwithPOS begin!");
	
	Wire.beginTransmission(address);
	Wire.println("begin:");//发送给射球模块的时候 射球模块复位 摩擦轮电机启动
	Wire.endTransmission();
}

void ComwithPOS::check()
{
	Serial.println("ComwithPOS check!");
	
	Wire.begin();
	Wire.requestFrom(address,1);
	int c = -1;
	if(Wire.available())
	{
		c = Wire.read();
	}
	
	if ( c== address)
	{
		connected = true;
	}
	else
	{
		connected = false;
	}
}

void ComwithPOS::getPOS()
{
	Wire.begin();
	Wire.
}

