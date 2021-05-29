#ifndef App_Scheduler_h
#define App_Schdeuler_h

#include "Arduino.h"
#include "src/apps/apps.h"

class App_Scheduler
{
	/*
	An app-specific single-run subroutine scheduler, runs app-specific subroutines according to order.
	The code for the OS (as in OS.h) loads the subroutines for the. 
	The ones for data inquisition by apps have to be loaded by the apps. 
	*/
	private:
		Subroutine *app_chunks[10];
	public:
		void add_chunk(Subroutine &chunk, int priority){
			// adds the chunks as per the priority
			app_chunks[priority] = &chunk;
		}
		void swap_address(int chunk_order_a, int chunk_order_b)
		{
			//to swap the orders of the chunks
			Subroutine *temp = app_chunks[chunk_order_a];
			app_chunks[chunk_order_a] = app_chunks[chunk_order_b];
			app_chunks[chunk_order_b] = temp;
		} 
		void set_status(int index, int status){
			//sets status of the subroutine
			app_chunks[index]->status = status;
		}
		void run_list(){
			// runs the chunks in the order of their priority
			for(int i = 0; i < 10; i++){
				if(app_chunks[i] != NULL){
					if(app_chunks[i]->status != 0){
						app_chunks[i]->run();	
					}
				}
			}
		}
}app_scheduler;  

#endif
		
		
