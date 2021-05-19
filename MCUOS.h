#ifndef OS_h
#define OS_h

#include "Arduino.h"
#include "hardware/hardware.h"
#include "apps/apps.h"
#include "kernel/kernel.h"
#include "std_subroutines.h"
#include "apps/Launcher.h"

class OperatingSystem 
{
	public:
		void load(){
			lcd_display.initialize_display();  //initializing display 
			sub_scheduler.add_chunk(button_read, button_read.priority);
			sub_scheduler.add_chunk(button_check, button_check.priority);
			app_tray.add_app(launcher, launcher.priority, launcher.name); //adding the launcher to the app tray
		}
		void run(){
			home(); //loading the launcher andrunning it
		}
}os;


#endif