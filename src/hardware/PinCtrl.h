#ifndef PinCtrl_h
#define PinCtrl_H

#include "Arduino.h"

struct Pin
{
	// structure to declare I/O pins
	bool in_use = false; // tells if the pin is in use or not
	int pin_number; //number of the pin
};

class DigitalPins
{
	private:
		struct Pin digital_pins[14]; // set of digital pins
		int pwm_pins[6] = {3, 5, 6, 9, 10, 11}; //set of PWM pins
	public:
		void init_pins(){
			// to initailize pins
			for(int i = 0; i < 14; i++){
				digital_pins[i].pin_number = i;
			}
		}
		void set_state(int pin, bool is_in_use){
			// sets the 'in_use' state of the pin
			digital_pins[pin].in_use = is_in_use;	
		}
		void init_pin(int pin, int pin_type){
			//executes the pinMode function for the pin
			if(digital_pins[pin].in_use == false){
				pinMode(pin, pin_type);
				digital_pins[pin].in_use = true;
			} else {
				Serial.println("Pin in use ! Use anpther pin");
			}
		}
		void set_pin_state(int pin, int state){
			//executes the digitalRead function using the pin
			if(digital_pins[pin].in_use == false){
				digitalWrite(pin, state);
			} else {
				Serial.println("Pin in use ! Use anpther pin");
			}
		}
		void setPWMpin_state(int pin, int value){
			//checks if the pin given as input 
			for(int i = 0; i < sizeof(pwm_pins)/sizeof(int); i++){
				if(pin == pwm_pins[i]){
					analogWrite(pin, value);
				} else {
					if(i == 5){
						Serial.println("Invalid pin");
					}
				}
			}
		}
				
			 
		int read_from_pin(int pin){
			// reads from digital pin
			return(digitalRead(pin));
			
		}
}digital_pinset;

class AnalogPins
{
	private:
		struct Pin analog_pins[6];
	public:
		void init_pins(){
			//initialize pins
			int analogs[6] = {A0, A1, A2, A3, A4, A5};
			for(int i = 0; i < 14; i++){
				analog_pins[i].pin_number = analogs[i];
			}
		}
		void set_state(int pin, int is_in_use){
			// sets the 'in_use' state of the pin
			analog_pins[pin].in_use = is_in_use;	
		}
		int read_from_pin(int pin){
			//reads from pin
			return(analogRead(pin));
		}
}analog_pinset;

#endif
