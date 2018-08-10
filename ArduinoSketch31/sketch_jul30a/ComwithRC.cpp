/* 
* ComwithRC.cpp
*
* Created: 2018/8/3 20:24:35
* Author: Vulcan
*/


#include "ComwithRC.h"
#include "WString.h"
#include "Arduino.h"
// default constructor
ComwithRC::ComwithRC()
{
	pinMode(2,OUTPUT);
	digitalWrite(2,HIGH);
} //ComwithRC

void ComwithRC::recived(String str)
{
	str.toUpperCase();
		
	int pos_VX = str.indexOf("X:");
	int pos_VY = str.indexOf("Y:");
	int pos_VZ = str.indexOf("P:");
	
	str_VX = str.substring(pos_VX+2,pos_VY);
	str_VY = str.substring(pos_VY+2,pos_VZ);
	str_VZ= str.substring(pos_VZ+2);
	
	VX = str_VX.toDouble();
	VY = str_VY.toDouble();
	VZ = str_VZ.toDouble();
	

}

