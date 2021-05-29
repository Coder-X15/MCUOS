#ifndef Subroutine_Scheduler_h
#define Subroutine_Schdeuler_h

#include "Arduino.h"
#include "apps/apps.h"

class Subroutine_Scheduler
{
	/*
	A subroutine scheduler, runs subroutines according to order.
	The code for the OS (as in OS.h) loads the standard subroutines by default. 
	The ones for data inquisition by apps have to be loaded by the apps. 
	*/

	private:
		Subroutine *loaded_chunks[10]; // list of subroutines
	public:
		void add_chunk(Subroutine &chunk, int priority){
			loaded_chunks[priority] = &chunk; //passes the address of the subroutine
			// (let's call it a 'chunk' for simplicity) to the list.
		}
		void swap_address(int chunk_order_a, int chunk_order_b)
		{
			//to swap the orders of the chunks
			Subroutine *temp = loaded_chunks[chunk_order_a];
			loaded_chunks[chunk_order_a] = loaded_chunks[chunk_order_b];
			loaded_chunks[chunk_order_b] = temp;
		} 
		void run_list(){
			//runs all the chunks in sequence
			for(int i = 0; i < 10; i++){
				if(loaded_chunks[i] != NULL){
					loaded_chunks[i]->run();
				}
			}
		}
}sub_scheduler;  

#endif
		
