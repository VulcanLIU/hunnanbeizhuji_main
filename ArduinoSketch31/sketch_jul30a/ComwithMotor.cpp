/* 
* ComwithMotor.cpp
*
* Created: 2018/7/29 9:57:39
* Author: Vulcan
*/


#include "ComwithMotor.h"
#include "HardwareSerial.h"
// default constructor
ComwithMotor::ComwithMotor()
{
	//ʹ��eeprom ��ȡKֵ
	//���뵽 kp ki kd����
	kp = 1.0;
	ki = 1.0;
	kd = 1.0;//111111111
} //ComwithMotor

void ComwithMotor::begin()
{
	Wire.begin();
	Serial.println("IN");
	for (int i=0;i<=5;i++)
	{
			//�ϵ������İ巢��Kֵ
			SendKtoALL(kp,ki,kd);
			Serial.println("IN2");
			//�ȴ�����İ巢�ͽ���ȷ���ź�
			int a = ReadBfrom(L1);
			int b = ReadBfrom(L2);
			int c = ReadBfrom(R1);
			int d = ReadBfrom(R2);
			if (a == L1 && b== L2 && c==R1 && d == R2)
			{
				connected = true;
			}
			else
			{
				connected = false;
			}
			
			//�ֱ��ĸ�����Ƿ���������
			if (a == L1){connectedL1 = true;}
			if (b == L2){connectedL2 = true;}
			if (c == R1){connectedR1 = true;}
			if (d == R2){connectedR2 = true;}
	}
	Serial.println("OUT");
}

void ComwithMotor::check()
{
	Serial.println("IN2");
	//�ȴ�����İ巢�ͽ���ȷ���ź�
	int a = ReadBfrom(L1);
	int b = ReadBfrom(L2);
	int c = ReadBfrom(R1);
	int d = ReadBfrom(R2);
	if (a == L1 && b== L2 && c==R1 && d == R2)
	{
		connected = true;
	}
	else
	{
		connected = false;
	}
			
	//�ֱ��ĸ�����Ƿ���������
	if (a == L1){connectedL1 = true;}
	if (b == L2){connectedL2 = true;}
	if (c == R1){connectedR1 = true;}
	if (d == R2){connectedR2 = true;}
}

int ComwithMotor::ReadBfrom(Motor m)
{
	Wire.begin();
	Wire.requestFrom(m,1);
	if(Wire.available())
	{
		int c = Wire.read();
		return c;
	}
}

void ComwithMotor::SendAtoALL(int rpm1,int rpm2,int rpm3,int rpm4)
{
	SendAto(L1,rpm1);
	SendAto(L2,rpm2);
	SendAto(R1,rpm3);
	SendAto(R2,rpm4);
}

void ComwithMotor::SendKtoALL(double _kp,double _ki,double _kd)
{
	SendKto(L1,kp,ki,kd);
	SendKto(L2,kp,ki,kd);
	SendKto(R1,kp,ki,kd);
	SendKto(R2,kp,ki,kd);
}

bool ComwithMotor::connectedRight()
{
	return connected;
}

bool ComwithMotor::connectedtoL1Right()
{
	return connectedL1;
}

bool ComwithMotor::connectedtoL2Right()
{
	return connectedL2;
}

bool ComwithMotor::connectedtoR1Right()
{
	return connectedR1;
}

bool ComwithMotor::connectedtoR2Right()
{
	return connectedR2;
}

void ComwithMotor::SendAto(Motor m,int speed)
{
	
	Wire.beginTransmission(m);
	Wire.print("A:");
	Wire.println(speed);
	Wire.endTransmission();
}

void ComwithMotor::SendKto(Motor m,double _kp,double _ki,double _kd)
{	
	Wire.beginTransmission(m);
	Wire.print("kp:");
	Wire.print(_kp);
	Wire.print("ki:");
	Wire.print(_ki);
	Wire.print("kd:");
	Wire.print(_kd);
	Wire.println();
	Wire.endTransmission();
}

void ComwithMotor::getK()
{
	
}
