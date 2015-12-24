/*
  SensoresRoverBot.h - Biblioteca para el uso de los sensores de RoverBot.
  Created by Ithaquas, December, 2015.
  Released into the public domain.
*/


// Este es el header file

#ifndef SensoresRoverBot_h // Evita problemas si alguien importa dos veces
#define SensoresRoverBot_h // Evita problemas si alguien importa dos veces

#include "Arduino.h" // Acceso a los tipos de datos y constantes de Arduino


/*
	Clase de la instancia que se llamara desde el sketch
*/
class Ultrasonido
{
	public:
		// Instancia Ultrasonido, en el se indica la configuracion de pines
		Ultrasonido(int Trig, int Echo);

		int distancia();

	private:
		int _Trig;
		int _Echo;

		long _distancia;
		long _durancion;
};


#endif // Evita problemas si alguien importa dos veces
