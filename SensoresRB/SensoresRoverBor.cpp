/*
  SensoresRB.cpp - Biblioteca para el uso de los sensores de RoverBot.
  Created by Ithaquas, December, 2015.
  Released into the public domain.
*/


// Este es el source file


#include "Arduino.h"
#include "SensoresRB.h"


/*
	CONSTRUCTOR
	Indica lo que debe suceder cuando alguien crea
	una instancia de la clase
*/
Ultrasonido::Ultrasonido(int Trig, int Echo)
{
	_Trig = Trig;
	_Echo = Echo;

	pinMode(_Trig, OUTPUT);
  pinMode(_Echo, INPUT);
}



/* FUNCIONES DE ULTRASONIDO */

// Devuelve distancia en cm
int Ultrasonido::distancia()
{
  digitalWrite(_Trig, LOW); // Estabiliza el pulso y apaga el disparador
  delayMicroseconds(5);
  
  digitalWrite(_Trig, HIGH); // Manda un pulso durante 10 microsegundos
  delayMicroseconds(10);
  digitalWrite(_Trig ,LOW); // Se interrumpe el pulso 
  
  _duracion = pulseIn(Echo, HIGH); // Cuenta el tiempo que transcurre hasta la recepcion
  _distancia = (duracion/2)/29.1;	// Factor de converisón para obtener distancia en cm

  return(_distancia);
}
