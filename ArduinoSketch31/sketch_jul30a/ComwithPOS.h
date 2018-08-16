/* 
* ComwithPOS.h
*
* Created: 2018/8/14 3:10:57
* Author: Vulcan
*/


#ifndef __COMWITHPOS_H__
#define __COMWITHPOS_H__


class ComwithPOS
{
public:
	const int address  = 6;
	
	ComwithPOS();
	void begin();
	void check();
	void getPOS();
	
	bool connected = false;
	double X = 0;
	double Y = 0;
	double P = 0;
	
}; //ComwithPOS

#endif //__COMWITHPOS_H__
