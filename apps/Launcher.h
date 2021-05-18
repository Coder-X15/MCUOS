#ifndef Launcher_h
#define Launcher_h

#include "Arduino.h"
#include "apps.h"
#include "kernel/kernel.h"
#include "Sample_App.h"
#include "constants.h"
#include "hardware/hardware.h"

// Launcher of my OS!

class Launcher : public App
{
	public:
		int priority = 0;
		bool exit_launcher = false;
		void load(){
			//at index 1 in the app tray is the sample app we made (even if it isn't empty)
			app_tray.add_app(sample_app, sample_app.priority);
		}
		void run(){
			int app_number = 0;
			lcd_display.clear_screen();
			lcd_display.lcd.home();
			lcd_display.show("UP/DOWN/SELECT");
			lcd_display.lcd.setCursor(0,2);
			lcd_display.show("to toggle app no");
			while(exit_launcher == false){
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
				Serial.println(app_number);
				delay(1000);
			}
			app_tray.run_app(app_number);
		}
}launcher;

#endif	
