#ifndef Sample_App_h
#define Sample_App_h

#include "Arduino.h"
#include "apps.h"
#include "kernel/kernel.h"
#include "constants.h"
#include "general_functions.h"

// Sample app to test the functionality of the app-development system

class RunDuties : public Subroutine
{
	public:
		int priority = 0;
		bool exit_state = false; 
		int status = 0;
		void run(){
			button_type = BT_TEMP; //clearing previously read button
			sub_scheduler.run_list();  //running the list of subroutines
			delay(100);
 			if(button_type == BT_SELECT){
				clrscr();
				print("App closed.");
				exit_state = true;
				delay(1000);
			} else {
				clrscr();
				reset_screen();
				print("Awaiting input..");
				newline();
				print_other<int>(button_type);
			}			
		}
}run_duties;

class TestApp: public App
{
	public:
		int priority = 1;
		char *name = "Sample app";
		void load(){
			app_scheduler.add_chunk(run_duties, run_duties.priority); 
			app_scheduler.set_status(0, 1);
		}
		void run(){
			run_duties.exit_state = false;  //setting default state of switch
			while(run_duties.exit_state == false){
				app_scheduler.run_list();
			}
			app_scheduler.set_status(0, 0);
			home();
		}
}sample_app;

#endif	
