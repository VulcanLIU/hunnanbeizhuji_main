/* 
* ComwithMotor.h
*
* Created: 2018/7/29 9:57:39
* Author: Vulcan
*/


#ifndef __COMWITHMOTOR_H__
#define __COMWITHMOTOR_H__
#include "Wire.h"

class ComwithMotor
{
public:
	enum Motor{L1,L2,R1,R2};
	int A[4] = {};
	int B[4] = {};
	double kp = 0;
	double ki = 0;
	double kd = 0;
	
	ComwithMotor();
	void begin();
	int ReadBfrom(Motor);
	void SendAtoALL();
	void SendKtoALL(double,double,double);
	
private:
	void getK();
	void SendAto(Motor,int);
	void SendKto(Motor,double,double,double);
}; //ComwithMotor

#endif //__COMWITHMOTOR_H__
