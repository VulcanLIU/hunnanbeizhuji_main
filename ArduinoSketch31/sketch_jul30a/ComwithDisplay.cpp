/* 
* ComwithDisplay.cpp
*
* Created: 2018/8/7 15:03:52
* Author: Vulcan
*/


#include "ComwithDisplay.h"

SoftwareSerial mySerial(10, 11); // RX, TX

// default constructor
ComwithDisplay::ComwithDisplay()
{
	mySerial.begin(9600);
} //ComwithDisplay

void ComwithDisplay::systemInit()
{
	mySerial.begin(9600);
	mySerial.println("initing");
}

void ComwithDisplay::displaySTR(String str)
{
	str = "STR:"+str;
	mySerial.println(str);
}

void ComwithDisplay::systemInfo()
{
	mySerial.println("information");
}

void ComwithDisplay::displayWKST(bool _shot,bool _motors,bool _locate)
{
	String str_ = "WKST:";
	if (_shot){str_+="|A:SHOT OK|";}else{str_+="|A:SHOT ERROR|";}
	if (_motors){str_+="|B:MOTOR OK|";}else{str_+="|B:MOTOR ERROR|";}
	if (_shot){str_+="|C:LOCATE OK|";}else{str_+="|C:LOCATE ERROR|";}
		
	mySerial.println(str_);
}

void ComwithDisplay::displayXYP(double _X,double _Y,double _P)
{
	String str_ = "XYP:";
	str_ += "X:";
	str_ += _X;
	str_ += "Y:";
	str_ += _Y;
	str_ += "P:";
	str_ += _P;
	
	mySerial.println(str_);
}

void ComwithDisplay::systemOK()
{
	mySerial.println("OK");
}

void ComwithDisplay::displayMsg(String str)
{
	str = "Msg:"+str;
	this->displaySTR(str);
}

