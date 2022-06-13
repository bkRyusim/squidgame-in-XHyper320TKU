//-------| lib/fnd.h |-------//
#ifndef	FND_H
#define	FND_H 


#include <unistd.h> // usleep()

#define MAX_FND 8



void init_fnd(short * address[]);
void fnd_clear();
void fnd_all();
void fnd_print_route(int answer[8], int stage);
void fnd_print_square(int position, int answer);

#endif
