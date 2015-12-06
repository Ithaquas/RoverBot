/*
  Movimiento.h - Biblioteca para el movimietno del RoverBot.
  Created by Ithaquas, December, 2015.
  Released into the public domain.
*/


// Este es el header file


#ifndef Movimiento_h // Evita problemas si alguien importa dos veces
#define Movimiento_h // Evita problemas si alguien importa dos veces

#include "Arduino.h" // Acceso a los tipos de datos y constantes de Arduino


/*
	Clase de la instancia que se llamara desde el sketch
*/
class Motor
{
	public:
		// Instancia Motor, en el se indica la configuración de pines
		Motor(char conf);

		void setSpeed(char motorName, char motorSpeed);
		void motorStart(char motorName, char direction);
		void motorStop(char motorName);
		void move(char direction);

	private:
		int _pinConfig[6];

		// Motor 1 (Izquierda)
		int _M1_MV1; // IN1
		int _M1_MV2; // IN2
		int _M1_PWM;  // ENA

		// Motor 2 (Derecha)
		int _M2_MV1; // IN3
		int _M2_MV2; // IN4
		int _M2_PWM;  // ENB

		int _motorDirForward;	_motorDirForward = 0; 
		int _motorDirBackward;	_motorDirBackward = 1;

		// cons las hace read-only

		int _speed; // Velocidad (0-255) 
};


#endif // Evita problemas si alguien importa dos veces
