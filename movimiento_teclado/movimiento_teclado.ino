#include <Movimiento.h>


Motor motor('A');


void setup()  
{  
	// Iniciacion comunicacion Serial
	Serial.begin(9600);
} 


/* Bucle */
void loop()  
{  
	if (Serial.available() > 0)
	{
		int inByte = Serial.read();
		motor.move(inByte);
	}
}  
