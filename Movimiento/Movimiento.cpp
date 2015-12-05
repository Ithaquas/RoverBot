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
	swicht (conf)
	{
		case 'A':	// Configuración A
			_pinConfig = {9, 8, 10, 13, 12, 11};
			break;

		default:
			break:
	}

	_M1_MV1 = _pinConfig[0];		_M2_MV1 = _pinConfig[3];
	_M1_MV2 = _pinConfig[1];		_M2_MV1 = _pinConfig[4];
	_M1_PWM = _pinConfig[2];		_M1_PWM = _pinConfig[5];

	_motorDirForward = 0;
	_motorDirBackward = 1;

	pinMode(_M1_MV1, OUTPUT);		pinMode(_M2_MV1, OUTPUT);
	pinMode(_M1_MV2, OUTPUT);		pinMode(_M2_MV2, OUTPUT); 
	pinMode(_M1_PWM, OUTPUT);		pinMode(_M2_PWM, OUTPUT);  
}


/* FUNCIONES */

// Permite variar la velocidad mediate las salidas PWM 
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
	char _pinMv1;  
	char _pinMv2;  
	 
	// Asigna el motor que se controla  
	if (_motorName == 1)  
	{ 
		_pin_mv1 = _M1_MV1;  
		_pin_mv2 = _M1_MV2;  
	}     
	else  
	{  
		_pin_mv1 = _M2_MV1;  
		_pin_mv2 = _M2_MV2;  
	}  
		
	switch (_direction)  
	{  
		case _motorDirForward:  
		{  
			digitalWrite(_pin_mv1, HIGH);  
			digitalWrite(_pin_mv2, LOW);            
		}  
		break;   

		case _motorDirBackward:  
		{  
			digitalWrite(_pin_mv1, LOW);  
			digitalWrite(_pin_mv2, HIGH);            
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

		case 'd':
		{
			motorStart(1, _motorDirBackward);    
			setSpeed(1, 180);  
			motorStart(2, _motorDirForward);        
			setSpeed(2, 180);

		}
		break;

		case 'a':
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
