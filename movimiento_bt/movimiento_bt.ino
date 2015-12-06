#include <Movimiento.h>


Motor motor('A');


/* Bloque de inicio */
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
    move(Serial.read());
    delay(100);
  }
}  
