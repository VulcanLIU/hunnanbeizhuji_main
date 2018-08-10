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
	
	//私有成员的封装
	int getVX() const { return VX; }
	void setVX(int8_t val) { VX = val; }
		
	int getVY() const { return VY; }
	void setVY(int8_t val) { VY = val; }
		
	int getVZ() const { return VZ; }
	void setVZ(int8_t val) { VZ = val; }
		
	String str_VX = "";
	String str_VY = "";
	String str_VZ = "";
protected:
private:
	int VX = 0;
	int VY = 0;
	int VZ = 0;
	
}; //ComwithRC

#endif //__COMWITHRC_H__
