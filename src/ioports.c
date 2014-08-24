/*
 *  UselOS
 *  By M-374 LX <http://m374lx.users.sourceforge.net/>
 *  
 *  ioports.c - Definitios related to CPU I/O ports and functions to access them
 */

#include "ioports.h"

u8 inb(u16 port)
{
	u8 ret_val;

	__asm__ __volatile__("inb %1,%0"
		: "=a"(ret_val)
		: "d"(port));
	return ret_val;
}

void outb(u16 port, u8 val)
{
	__asm__ __volatile__("outb %b0,%w1"
		:
		: "a"(val), "d"(port));
}

