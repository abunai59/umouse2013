#ifndef DECIDE_H
#define DECIDE_H
#include "maze.h"
#include "mouse.h"

// protos and macros for decide.c
#define L_TURN  0
#define R_TURN  1
#define U_TURN  2
#define NO_TURN 3

// choose an algorithm
#define R_WALL  0
#define L_WALL  1
#define TREMAUX 2
#define FLOOD   3
#define	TEST	4

int r_wall(void);

int l_wall(void);

int tremaux(Maze * maze, Mouse * mouse);

// flood from start points x,y and return turn
int flood(Maze * maze, Mouse * mouse, int x, int y);
#endif
