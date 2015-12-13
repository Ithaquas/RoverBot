/*
  Movimiento.cpp - Biblioteca para el movimietno del RoverBot.
  Created by Ithaquas, December, 2015.
  Released into the public domain.
*/


// Este es el source file


#include "Arduino.h"
#include "Movimiento.h"


/*
	CONSTRUCTOR
	Indica lo que debe suceder cuando alguien crea
	una instancia de la clase
*/
// Motor:: indica que la función es parte de la clase Motor(::)
Motor::Motor(char conf)
{
	/* Distintas configuraciones de pines */
	switch (conf)
	{
		case 'A':	// Configuración A
			_pinConfig[0] = 13; // IN1
			_pinConfig[1] = 12;	// IN2
			_pinConfig[2] = 11;	// ENA
			_pinConfig[3] = 9;	// IN3
			_pinConfig[4] = 8;	// IN4
			_pinConfig[5] = 10;	// ENB
			break;

		default:
			break;
	}

	_M1_MV1 = _pinConfig[0];
	_M1_MV2 = _pinConfig[1];
	_M1_PWM = _pinConfig[2];
	_M2_MV1 = _pinConfig[3];
	_M2_MV2 = _pinConfig[4];
	_M1_PWM = _pinConfig[5];

	_motorDirForward = 0;
	_motorDirBackward = 1;

	pinMode(_M1_MV1, OUTPUT);
	pinMode(_M2_MV1, OUTPUT);
	pinMode(_M1_MV2, OUTPUT);
	pinMode(_M2_MV2, OUTPUT); 
	pinMode(_M1_PWM, OUTPUT);
	pinMode(_M2_PWM, OUTPUT);  
}


/* FUNCIONES */

// Permite variar la velocidad mediate lasprimary salidas PWM 
// Rango 0-255
// TODO_p. Variacion de 0-100, con tope
void Motor::setSpeed(char _motorName, char _motorSpeed)  
{  
	// Asigna el motor que se controla  
	 if (_motorName == 1)  
	 {  
		analogWrite(_M1_PWM, _motorSpeed);  
	 }     
	 else  
	 {  
		analogWrite(_M2_PWM, _motorSpeed);  
	 }  
}


// Basicas del motor
// Hacia delante o hacia atrás, cada lado
void Motor::motorStart(char _motorName, char _direction)  
{  
	// Asigna el motor que se controla  
	if (_motorName == 1)  
	{ 
		_pinMv1 = _M1_MV1;  
		_pinMv2 = _M1_MV2;  
	}     
	else if(_motorName == 2)  
	{  
		_pinMv1 = _M2_MV1;
		Serial.println(_pinMv1);
		Serial.println(_pinMv2);
		_pinMv2 = _M2_MV2;  
	}  
	else
	{
		Serial.print("Kaput");
	}
		
	switch (_direction)  
	{  
		case (0):  
		{  
			digitalWrite(_pinMv1, HIGH);  
			digitalWrite(_pinMv2, LOW);            
		}  
		break;   

		case (1):  
		{  
			digitalWrite(_pinMv1, LOW);  
			digitalWrite(_pinMv2, HIGH);            
		}  
		break;           
	} 	
}


// Para el motor
void Motor::motorStop(char _motorName)  
{
	setSpeed(_motorName, 0);  
	if (_motorName == 1)
	{
		digitalWrite(_M1_MV1, HIGH);  
		digitalWrite(_M1_MV2, HIGH);       
	}  
	else  
	{
		digitalWrite(_M2_MV1, HIGH);  
		digitalWrite(_M2_MV2, HIGH);       
	}
}


// Movimientos compuestos
void Motor::move(char _direction)
{
	switch(_direction)
	{
		case 'w':
		{
			motorStart(1, _motorDirForward);    
			setSpeed(1, 220);  
			motorStart(2, _motorDirForward);        
			setSpeed(2, 220);
		}
		break;

		case 's':
		{
			motorStart(1, _motorDirBackward);    
			setSpeed(1, 220);  
			motorStart(2, _motorDirBackward);        
			setSpeed(2, 220);
		}
		break;

		case 'a':
		{
			motorStart(1, _motorDirBackward);    
			setSpeed(1, 180);  
			motorStart(2, _motorDirForward);        
			setSpeed(2, 180);

		}
		break;

		case 'd':
		{
			motorStart(1, _motorDirForward);    
			setSpeed(1, 180);  
			motorStart(2, _motorDirBackward);        
			setSpeed(2, 180);
		}
		break;
	
		case 'q':
		{
			motorStop(1);
			motorStop(2);
		}
		break;
	}
}
