#include "lcd.h"

int LCDInit()
{
	long i;
	int j;
	RS = 0;
	// send 0x3 3 times
	for (j = 0; j < 3; j++)
	{
		D4 = 1;
		D5 = 1;
		D6 = 0;
		D7 = 0;
		E = 1;
		for (i = 0; i < 1000; i++);
		E = 0;
	}
	// enable 4 bit mode
	D4 = 0;
	D5 = 1;
	D6 = 0;
	D7 = 0;
	E = 1;
	for (i = 0; i < 1000; i++);
	E = 0;
	for (i = 0; i < 1000; i++);
	LCDSendCmd(0x28);	// set interface
	LCDSendCmd(0x08);	// turn off LCD
	LCDSendCmd(0x01);	// clear lcd, return home
	LCDSendCmd(0x06);	// set cursor direction to right
	LCDSendCmd(0x0C);	// turn on display, no cursor
	return 0;
}

int LCDSendCmd(int cmd)
{
	long i;

	// use command mode (RS=0)
	RS = 0;
	for (i = 0; i < 500; i++);

	// upper nibble
	D4 = cmd >> 4 & 0x1;
	D5 = cmd >> 5 & 0x1;
	D6 = cmd >> 6 & 0x1;
	D7 = cmd >> 7 & 0x1;
	// send and wait
	E = 1;
	for (i = 0; i < 100; i++);
	E = 0;
	for (i = 0; i < 100; i++);

	// lower nibble
	D4 = cmd & 0x1;
	D5 = cmd >> 1 & 0x1;
	D6 = cmd >> 2 & 0x1;
	D7 = cmd >> 3 & 0x1;
	// send and wait
	E = 1;
	for (i = 0; i < 100; i++);
	E = 0;
	for (i = 0; i < 100; i++);

	return 0;
}

int LCDSendData(int data)
{
	long i;

	// use data mode (RS=1)
	RS = 1;
	for (i = 0; i < 500; i++);

	// upper nibble
	D4 = data >> 4 & 0x1;
	D5 = data >> 5 & 0x1;
	D6 = data >> 6 & 0x1;
	D7 = data >> 7 & 0x1;
	// send and wait
	E = 1;
	for (i = 0; i < 100; i++);
	E = 0;
	for (i = 0; i < 100; i++);

	// lower nibble
	D4 = data & 0x1;
	D5 = data >> 1 & 0x1;
	D6 = data >> 2 & 0x1;
	D7 = data >> 3 & 0x1;

	// send and wait
	E = 1;
	for (i = 0; i < 100; i++);
	E = 0;
	for (i = 0; i < 100; i++);
	LCDSendCmd(0x06);
	return 0;
}

int LCDPuts(char *str)
{
	int i = 0;

	while (str[i] != 0)
	{
		// move to next line on newline char
		if (str[i] == '\n') { i++; LCDSendCmd(0xC0);}
		LCDSendData((int)str[i]);
		i++;
	}
	return i;
}

int LCDCls()
{
	LCDSendCmd(0x01);	// clear and home command
	return 0;
}
