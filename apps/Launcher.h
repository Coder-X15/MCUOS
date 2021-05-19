#ifndef Launcher_h
#define Launcher_h

#include "Arduino.h"
#include "apps.h"
#include "kernel/kernel.h"
#include "Sample_App.h"
#include "constants.h"
#include "general_functions.h"

// Launcher of my OS!

class Launcher : public App
{
	public:
		int priority = 0;
		bool exit_launcher = false;
		char *name = "Launcher";
		void load(){
			//at index 1 in the app tray is the sample app we made (even if it isn't empty)
			app_tray.add_app(sample_app, sample_app.priority, sample_app.name);
		}
		void run(){
			exit_launcher = false;
			int app_number = 0;
			lcd_display.clear_screen();
			lcd_display.lcd.home();
			while(exit_launcher == false){
				print("Home Screen");
				newline();
				print(app_tray.getName(app_number));
				sub_scheduler.run_list();
				if(button_type == BT_DOWN){
					app_number++;
				}
				if(button_type == BT_UP){
					app_number--;
				}
				if(button_type == BT_SELECT){
					app_tray.load_app(app_number);
					exit_launcher = true;
				}
				delay(100);
				clrscr();
			}
			app_tray.run_app(app_number);
		}
}launcher;

#endif	
