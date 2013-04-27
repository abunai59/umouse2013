#ifndef WALLS_H
#define WALLS_H

// macros and prototypes for walls.c
#include <stdbool.h>

#define RF_THRESHOLD	1700
#define LF_THRESHOLD	1700
#define RIGHT_THRESHOLD	1700
#define LEFT_THRESHOLD	1700

bool left_wall(void);
bool front_wall(void);
bool right_wall(void);
#endif