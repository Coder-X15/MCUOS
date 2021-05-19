#ifndef general_functions_h
#define general_functions_h

#include "Arduino.h"
#include "apps.h"
#include "hardware/hardware.h"

//list of frequently usable functions, just to simplify the making of the app

void reset_screen(){
	//returns cursor to the top left corner of the screen, without erasing data
	lcd_display.lcd.home();
}

void print(char text[]){
	//prints the text on the display device
	lcd_display.show(text);
}

void newline(){
	//goes to the next line
	lcd_display.lcd.setCursor(0,2);
}

void clrscr(){
	//clears the screen
	lcd_display.clear_screen();
}

void home(){
	//returns to the launcher
	app_tray.load_app(0); 
	app_tray.run_app(0);
}

#endif

 
		
