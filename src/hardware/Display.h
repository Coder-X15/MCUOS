#ifndef Display_h
#define Display_h

#include "Arduino.h"
#include "LiquidCrystal.h"
#include "PinCtrl.h"
#include "src/constants.h"

class Display
{
	public:
		bool in_use = false; //specifies of the display is in use
		int pin_config[6] = {RS, EN, D4, D5, D6, D7}; //display pin configuration; change according to your device
		int lcd_grid[2] = {16, 2}; // LCD grid configuration (to determine the no. of cells) - here 2 rows 
			    // and 16 columns
		LiquidCrystal lcd = LiquidCrystal(0,0,0,0,0,0);
		bool isBlink = false;
	
		void initialize_display(){
			//starts up the display
			int rs = pin_config[0];
			int en = pin_config[1];
			int d4 = pin_config[2];
			int d5 = pin_config[3];
			int d6 = pin_config[4];
			int d7 = pin_config[5];
			for(int pin_number = 0; pin_number < 6; pin_number++){
				// setting 'in_use' to true so that we don't accidentally use them
				digital_pinset.set_state(pin_config[pin_number], true);
			} 
			lcd = LiquidCrystal(RS, EN, D4, D5, D6, D7);
			lcd.begin(lcd_grid[0], lcd_grid[1]);
	 		lcd.clear();
			lcd.home();
		}
		void show(char text[]){
			//displays text
			lcd.print(text);
		}
		void clear_screen(){
			//clears display
			lcd.clear();
		}
		void toggle_blink(){
			// toggles blinking of the cursor; b=false by default
			isBlink = !isBlink;
			if(isBlink == true){
				lcd.blink();
			} else {
				lcd.noBlink();
			}
		}
}lcd_display;

#endif
		 
