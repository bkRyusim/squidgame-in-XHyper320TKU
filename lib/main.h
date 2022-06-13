//-------| lib/main.h |-------//
#ifndef	MAIN_H
#define	MAIN_H 

#define EASY 8
#define NORMAL 4
#define HARD 1

#include <stdio.h>		// printf(), scanf(), fprintf()
#include <fcntl.h>		// open()
#include <unistd.h>		// close(), off_t , usleep()
#include <sys/mman.h>	// mmap(), munmap()
#include <stdlib.h> 	// exit()
#include <string.h>		// strlen()

#include "ieb.h"
#include "led.h"
#include "dot.h"
#include "fnd.h"
#include "clcd.h"
#include "keypad.h"
#include "game.h"

typedef enum {
	FALSE = 0,
	TRUE  = 1
} truth_t;

typedef enum {
	ERROR	= -1,
	SUCCESS	= 0
} error_t;

int main();
short * mapper(off_t offset);
void unmapper();
void emergency_closer();
truth_t input_mode();

#endif
