#ifndef std_subroutines_h
#define std_subroutines_h

#include "Arduino.h"
#include "apps/apps.h"
#include "hardware/hardware.h"
#include "constants.h"

//Here we declare the standard subroutines for the OS
/*Global variables
-----------------------------*/
int  button_value; //for the button-reading subroutine and the button-interpreting subroutine; 
// can also be used in your own sketches for other purposes 
int button_type; //for the button-interpreting subroutine only; an indicator of the button pressed

/* Subroutines 
-----------------------------*/
class ButtonRead_Subroutine : public Subroutine
{
	//a button-reading subroutine; reads buttons on the LCD shield via analogue interface A0;
	public:
		int priotrity = 0;
		void run()
		{
			int temp = analog_pinset.read_from_pin(A0);
			button_value = temp;
		}
		
}button_read;

class ButtonCheck_Subroutine : public Subroutine
{
	//identifies the buttons based on the value of 'button_vale'
	public:
		int priority = 1;
		void run()
		{
			button_type = BT_TEMP;
			switch(button_value){
				case UP:
					button_type = BT_UP;
					break;
				case DOWN:
					button_type = BT_DOWN;
			 		break;
				case RIGHT:
					button_type = BT_RIGHT;
					break;
				case LEFT:
					button_type = BT_LEFT;
					break;
				case SELECT:
					button_type = BT_SELECT;
					break;
			}
		}
}button_check;

#endif