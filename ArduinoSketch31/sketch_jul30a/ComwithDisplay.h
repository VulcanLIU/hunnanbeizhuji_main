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
	
	void systemInit();//ϵͳ��ʼ��
	
	void displayMotors(bool,bool,bool,bool);//������ʾ��һ�����������
	
	void displaySHOT(bool);//��ʾ����ģ��Ĺ���״̬
	
	void displayPOS(bool);//��ʾ��λģ��Ĺ���״̬
	
	void displayXYP(double,double,double);//��ʾXYP
	
	void displayMsg(String);//��ʾ״̬��Ϣ
	
private:
	
}; //ComwithDisplay

#endif //__COMWITHDISPLAY_H__
