#ifndef Sample_App_h
#define Sample_App_h

#include "Arduino.h"
#include "apps.h"
#include "kernel/kernel.h"
#include "constants.h"

// Sample app to test the functionality of the app-development system

class RunDuties : public Subroutine
{
	public:
		int priority = 0;
		bool exit_state = false; 
		void run(){
			button_type = BT_TEMP; //clearing previously read button
			sub_scheduler.run_list(); //running the list of subroutines
			delay(1000);
 			if(button_type == BT_SELECT){
				lcd_display.clear_screen();
				lcd_display.show("You have quit the app");
				exit_state = true;
				delay(1000);
			} else {
				lcd_display.clear_screen();
				lcd_display.show("Waiting for input..."); 
			}			
		}
}run_duties;

class TestApp: public App
{
	public:
		int priority = 1;
		void load(){
			app_scheduler.add_chunk(run_duties, run_duties.priority); 
		}
		void run(){
			run_duties.exit_state = false;  //setting default state of switch
			while(run_duties.exit_state == false){
				app_scheduler.run_list();
			}
			app_tray.load_app(0);
			app_tray.run_app(0);
		}
}sample_app;

#endif	
