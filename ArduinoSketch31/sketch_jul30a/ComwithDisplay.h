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
	
	void systemInit();//ϵͳ��ʼ��
	
	void displaySTR(String);//��ʾ�ַ��������ϵ��Լ�
	
	void systemInfo();//��ʾϵͳ��Ϣ
	
	void displayWKST(bool,bool,bool);//��ʾ���������Ĺ���״̬
	
	void displayXYP(double,double,double);//��ʾXYP
	
	void dispyMsg(String);//��ʾ״̬��Ϣ
	
	void systemOK();//ϵͳOJBK;
private:
	
}; //ComwithDisplay

#endif //__COMWITHDISPLAY_H__
