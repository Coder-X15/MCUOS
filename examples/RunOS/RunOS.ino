
#include <MCUOS.h>

void setup() {
  Serial.begin(9600);
  os.load(); //loading the OS
  
}

void loop() {
  // put your main code here, to run repeatedly:
  os.run(); //running it
} 
