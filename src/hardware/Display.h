#ifndef Display_h
#define Display_h

#include "Arduino.h"
#include "LiquidCrystal.h"
#include "PinCtrl.h"
#include "constants.h"

class Display
{
	public:
		bool in_use = false; //specifies of the display is in use
		int pin_config[6] = {RS, EN, D4, D5, D6, D7}; //display pin configuration; change according to your device
		int lcd_grid[2] = {16, 2}; // LCD grid configuration (to determine the no. of cells) - here 2 rows 
			    // and 16 columns
		LiquidCrystal lcd = LiquidCrystal(0,0,0,0,0,0);
		bool isBlink = false;
	
		void initialize_display();
		void show(char text[]);
		void clear_screen();
		void toggle_blink();
}lcd_display;

#endif
		 
