/* 
* ComwithMotor.cpp
*
* Created: 2018/7/29 9:57:39
* Author: Vulcan
*/


#include "ComwithMotor.h"

// default constructor
ComwithMotor::ComwithMotor()
{
	//使用eeprom 读取K值
	//载入到 kp ki kd里面
	kp = 1.0;
	ki = 1.0;
	kd = 1.0;
} //ComwithMotor

void ComwithMotor::begin()
{
	while(1)
	{
		//上电给下面的板发送K值
		SendKtoALL(kp,ki,kd);
		//等待下面的板发送接收确认信号	
		int a = ReadBfrom(L1);
		if (a == 6)
		{
			return ;
		}
	}
}

int ComwithMotor::ReadBfrom(Motor m)
{
	Wire.begin();
	Wire.requestFrom(L1,1);
	if(Wire.available())
	{
		int c = Wire.read();
		return c;
	}
}

void ComwithMotor::SendAtoALL()
{
	SendAto(L1,A[0]);
	SendAto(L2,A[1]);
	SendAto(R1,A[2]);
	SendAto(R2,A[3]);
}

void ComwithMotor::SendKtoALL(double,double,double)
{
	
}

void ComwithMotor::SendAto(Motor m,int speed)
{
	Wire.begin();
	Wire.beginTransmission(m);
	Wire.print("A:");
	Wire.println(speed);
	Wire.endTransmission();
}

void ComwithMotor::SendKto(Motor m,double _kp,double _ki,double _kd)
{
	String str = "kp:";
	
	Wire.begin();
	Wire.beginTransmission(m);
	Wire.println(str);
	Wire.endTransmission();
}

void ComwithMotor::getK()
{
	
}
