#ifndef constants_h
#define constants_h

/* This file is where you pu the system constants (especially the configuratiosn of the hardware, etc.).
You can edit this file to match your system's requirements */

//LCD pin configuration

#define RS 8
#define EN 9
#define D4 4
#define D5 5
#define D6 6
#define D7 7 

//Button values

#define UP 143
#define DOWN 329
#define LEFT 505
#define RIGHT 0
#define SELECT 742

//Respective button ID's

#define BT_UP 0
#define BT_DOWN 1
#define BT_LEFT 2
#define BT_RIGHT 3
#define BT_SELECT 4

//A template button value in case the button is not recognised (in order to avoid button value clashes)
#define BT_TEMP 5

#endif
