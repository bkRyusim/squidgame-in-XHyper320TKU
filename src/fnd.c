//-------| src/fnd.c |-------//
#include "fnd.h"

static unsigned short fnd_upper_square = 0x63; // 0110 0011
static unsigned short fnd_down_square = 0x5C;  // 0101 1100

static short *fnd[MAX_FND];

void init_fnd(short *address[])
{
	int i;
	for (i = 0; i < MAX_FND; i++)
	{
		fnd[i] = address[i];
	}
}

void fnd_clear()
{
	int i;
	for (i = 0; i < MAX_FND; i++)
	{
		*fnd[i] = 0;
	}
}

void fnd_all()
{
	int i;
	for (i = 0; i < MAX_FND; i++)
	{
		*fnd[i] = 0xFF;
	}
}

void fnd_print_route(int answer[8], int stage)
{
	int i;

	for (i = 0; i < stage; i++)
	{
		fnd_print_square(7 - i, answer[i]);
	}
}

void fnd_print_square(int position, int answer)
{
	if (answer == 0)
	{ // upper square
		*fnd[position] = fnd_upper_square;
	}
	else
	{
		*fnd[position] = fnd_down_square;
	}
}
