/* 
* DisplayBuff.h
*
* Created: 2018/8/3 22:55:07
* Author: Vulcan
*/


#ifndef __DISPLAYBUFF_H__
#define __DISPLAYBUFF_H__

#include "WString.h"
#include "Print.h"
#include <avr/pgmspace.h>
class DisplayBuff:public Print
{
public:
	DisplayBuff();
	const String buff = "RRRDDDDDDDDDssssssssssssssssssssssssDDDDDDDDDDDDDDDDDDDDddddddd";
	size_t write(char);
	size_t write(uint8_t c){write(char(c));};
	void flush(){};
private:
	
}; //DisplayBuff

#endif //__DISPLAYBUFF_H__
