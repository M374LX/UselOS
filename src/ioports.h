/*
 *  UselOS
 *  By M-374 LX <http://m374lx.users.sourceforge.net/>
 *  
 *  ioports.h - Definitios related to CPU I/O ports and functions to access them
 */

#ifndef USELOS_IOPORTS
#define USELOS_IOPORTS

#include "types.h"

#define PS2_STATUS_PORT	0x64
#define PS2_DATA_PORT	0x60

#define PS2_OUTPUT_FULL	1
#define PS2_INPUT_FULL	2

#define CPU_REBOOT 0xFE

u8 inb(u16 port);
void outb(u16 port, u8 val);

#endif

