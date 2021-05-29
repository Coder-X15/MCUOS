#ifndef AppDev_h
#define AppDev_h

#include "Arduino.h"

class Subroutine
{
	//subroutines to be used in apps
	//this is an abstract class made to create multiple instances
	public:
		int priority; //priority of the task
		int status; //status of the task
		virtual void run() = 0; //runs the subroutine
};

#endif 
