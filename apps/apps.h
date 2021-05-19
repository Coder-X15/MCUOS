#ifndef apps_h
#define apps_h

#include "Arduino.h"
#include "Subroutine.h"
#include "general_functions.h"

//Library to develop apps and subroutines with

class App
{
	public:
		virtual void load() = 0; // virtual function to set up the app
		virtual void run() = 0; // virtual function to run it
};

class AppTray{
	private:
		App *apps[10]; // space to load apps into
		char *app_names[10]; //app names
	public:
		void add_app(App &app, int priority, char app_name[]){
			//adds app into the list
			apps[priority] = &app;
			app_names[priority] = app_name;
		}
		void swap_address(int app_addr_a, int app_addr_b)
		{
			//to swap the orders of the apps
			App *temp = apps[app_addr_a];
			apps[app_addr_a] = apps[app_addr_b];
			apps[app_addr_b] = temp;
		} 
		void load_app(int index){
			//loads the app at 'index'
			if(apps[index] != NULL){
				apps[index]->load();
			}
		}
		void run_app(int index){
			//runs the app at 'index'
			if(apps[index] != NULL){
				apps[index]->run();
			}
		}
		char* getName(int index){
			//returns name of the app
			if(apps[index] != NULL){
				return(app_names[index]);
			}
		}
}app_tray;

#endif