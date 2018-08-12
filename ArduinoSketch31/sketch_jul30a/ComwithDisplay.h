/* 
* ComwithDisplay.h
*
* Created: 2018/8/7 15:03:53
* Author: Vulcan
*/


#ifndef __COMWITHDISPLAY_H__
#define __COMWITHDISPLAY_H__

#include "WString.h"
class ComwithDisplay
{
public:
	ComwithDisplay();
	
	void systemInit();//系统初始化
	
	void displayMotors(bool,bool,bool,bool);//用来显示哪一个电机掉线了
	
	void displaySHOT(bool);//显示射球模块的工作状态
	
	void displayPOS(bool);//显示定位模块的工作状态
	
	void displayXYP(double,double,double);//显示XYP
	
	void displayMsg(String);//显示状态信息
	
private:
	
}; //ComwithDisplay

#endif //__COMWITHDISPLAY_H__
