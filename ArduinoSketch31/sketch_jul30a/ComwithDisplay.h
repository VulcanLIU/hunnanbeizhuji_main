/* 
* ComwithDisplay.h
*
* Created: 2018/8/7 15:03:53
* Author: Vulcan
*/


#ifndef __COMWITHDISPLAY_H__
#define __COMWITHDISPLAY_H__

#include "SoftwareSerial.h"
#include "WString.h"


class ComwithDisplay
{
public:
	ComwithDisplay();
	
	void systemInit();//系统初始化
	
	void displaySTR(String);//显示字符串——上电自检
	
	void systemInfo();//显示系统信息
	
	void displayWKST(bool,bool,bool);//显示三个部件的工作状态
	
	void displayXYP(double,double,double);//显示XYP
	
	void dispyMsg(String);//显示状态信息
	
	void systemOK();//系统OJBK;
private:
	
}; //ComwithDisplay

#endif //__COMWITHDISPLAY_H__
