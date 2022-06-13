//-------| lib/game.h |-------//
#ifndef	GAME_H
#define	GAME_H

#include "dot.h"
#include "clcd.h"
#include "led.h"
#include "fnd.h"
#include <stdlib.h>
#include <time.h>

void set_answer();
int game_check(int input);
void game_set_chance(int num);
void game_end(int result);

#endif
