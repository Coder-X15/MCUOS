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

void print(char *text){
	//prints the text on the display device
	lcd_display.show(text);
}

template <typename print_type>
void print_other( print_type text){
	//prints the text of types other than char on the display device
	lcd_display.lcd.print(text);
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

void set_digital_pin(int pin, int ptype){
	//sets up a digital interface pin for use
	digital_pinset.init_pin(pin, ptype);
}	

void sys_loop(){
	//runs subroutines in the schedulers
	sub_scheduler.run_list();
	app_scheduler.run_list(); 
}

void write_digital_pin(int pin, int state){
	//sets digital pin 'pin' to HIGH or LOW
	digital_pinset.set_pin_state(pin,state);
}

#endif

 
		
