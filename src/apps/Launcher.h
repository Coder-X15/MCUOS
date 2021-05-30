#ifndef Launcher_h
#define Launcher_h

//Standard libraries to import

#include "Arduino.h"
#include "apps.h"
#include "kernel/kernel.h"
#include "constants.h"
#include "general_functions.h"
 
//App headers
#include "Torch.h"
#include "Sample_App.h"

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
			app_tray.add_app(torch_app, torch_app.priority, torch_app.name);
		}
		void run(){
			exit_launcher = false;
			int app_number = 0;
			while(exit_launcher == false){
				clrscr();
				reset_screen();
				print("Home Screen");
				newline();
				print(app_tray.getName(app_number));
				sys_loop();
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
			}
			app_tray.run_app(app_number);
		}
}launcher;

#endif	
