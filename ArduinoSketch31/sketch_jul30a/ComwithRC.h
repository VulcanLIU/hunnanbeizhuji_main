/* 
* ComwithRC.h
*
* Created: 2018/8/3 20:24:36
* Author: Vulcan
*/


#ifndef __COMWITHRC_H__
#define __COMWITHRC_H__

#include <stdint-gcc.h>
#include "WString.h"

class ComwithRC
{
public:
	ComwithRC();
	
	void recived(String);
		
	String str_VX = "";
	String str_VY = "";
	String str_VZ = "";
	String str_shot = "";

	double VX = 0;
	double VY = 0;
	double VZ = 0;
	int shot = 0;
	
}; //ComwithRC

#endif //__COMWITHRC_H__
