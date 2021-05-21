#ifndef  Torch_h
#define Torch_h

#include "Arduino.h"
#include "apps.h"
#include "kernel/kernel.h"
#include "constants.h"
#include "general_functions.h"

#define TORCH_PIN 10

class Torch : public App
{
	public:
		int priority = 2;
		char *name = "Flashlight";
		bool app_exit = false;
		void load(){
			set_digital_pin(TORCH_PIN, OUTPUT);
		}	
		void run(){
			clrscr();
			app_exit = false;
			char *state = "Off";
			while(app_exit == false){
				clrscr();
				reset_screen();
				print("Torch state"); 
				newline();
				sys_loop();
				if(button_type == BT_UP){
					state = "On";
					write_digital_pin(TORCH_PIN, HIGH);
				} else if(button_type == BT_DOWN){
					state = "Off";
					write_digital_pin(TORCH_PIN, LOW);
				} else if(button_type == BT_SELECT){
					app_exit = true;
					write_digital_pin(TORCH_PIN, LOW);
				} else {
					//do nothing
				}
				print(state);
				delay(100);
			}
			home();
		}
}torch_app;

#endif	
