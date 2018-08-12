/* 
* ComwithDisplay.cpp
*
* Created: 2018/8/7 15:03:52
* Author: Vulcan
*/


#include "ComwithDisplay.h"

#include "SoftwareSerial.h"

SoftwareSerial mySerial(10,11);//TX RX

ComwithDisplay::ComwithDisplay()
{
	
} //ComwithDisplay

void ComwithDisplay::systemInit()
{
	mySerial.begin(9600);
	
	displayMsg("System");
}

void ComwithDisplay::displayMotors(bool l1,bool l2,bool r1,bool r2)
{
	mySerial.begin(9600);
	String _str = "MOTORS:";
	if (l1)
	{
		_str+="L1 ";
	}
	if (l2)
	{
		_str+="L2 ";
	}
	if (r1)
	{
		_str+="R1 ";
	}
	if (r2)
	{
		_str+="R2 ";
	}
	//displayMsg("Sys");
	mySerial.println(_str);
}

void ComwithDisplay::displaySHOT(bool sright)
{
	String _str = "SHOT:";
	if (sright)
	{
		_str += "ON";
	}
	else
	{
		_str += "OFF";
	}
	mySerial.println(_str);
}

void ComwithDisplay::displayPOS(bool pright)
{
	String _str = "POS:";
	if (pright)
	{
		_str += "ON";
	}
	else
	{
		_str += "OFF";
	}
	mySerial.println(_str);
}
 
void ComwithDisplay::displayXYP(double x,double y,double p)
{
	String _str = "XYP:";
	_str += "x:";
	_str += x;
	_str += "y:";
	_str += y;
	_str += "p:";
	_str += p;
	
	mySerial.println(_str);
}

void ComwithDisplay::displayMsg(String str)
{
	String _str = "Msg:";
	_str += str;
	
	mySerial.println(_str);
}
