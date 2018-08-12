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
	Wire.println("begin:");//���͸�����ģ���ʱ�� ����ģ�鸴λ Ħ���ֵ������
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
