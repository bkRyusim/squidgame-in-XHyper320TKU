//-------| src/dot.c |-------//
#include "dot.h"

static unsigned short dot_o[MAX_DOT] = {
	0x7F, 0x41, 0x41, 0x41, 0x7F};

static unsigned short dot_x[MAX_DOT] = {
	0x63, 0x14, 0x08, 0x14, 0x63};

static short *dot[MAX_DOT];

void init_dot(short *address[])
{
	int i;
	for (i = 0; i < MAX_DOT; i++)
	{
		dot[i] = address[i];
	}
}

void dot_clear()
{
	int i;
	for (i = 0; i < MAX_DOT; i++)
	{
		*dot[i] = 0;
	}
	usleep(0); // for Ximulator
}

void dot_print_o()
{
	int i;
	for (i = 0; i < MAX_DOT; i++)
	{
		*dot[i] = dot_o[i];
	}
}

void dot_print_x()
{
	int i;
	for (i = 0; i < MAX_DOT; i++)
	{
		*dot[i] = dot_x[i];
	}
}
