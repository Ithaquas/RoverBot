/* Asignacion de los pines */

// TODO_p: Funcion que asigne los pines. Crear biblioteca

// Con HIGH. 1,3 delante. 2,4 detras.



// Motor 1 - Izquierda
const int MOTOR1_MV1 = 9;     // IN1
const int MOTOR1_MV2 = 8;     // IN2
const int MOTOR1_PWM = 10;    // ENA

// Motor 2 - Derecha
const int MOTOR2_MV1 = 13;    // IN3
const int MOTOR2_MV2 = 12;    // IN4
const int MOTOR2_PWM = 11;    // ENB

const int MOTOR_DIR_FORWARD = 0;  
const int MOTOR_DIR_BACKWARD = 1;

// cons las hace read-only

// Velocidad
int spd = 200; // TODO. Variacion de 0-100, con tope.

// Comunicacion BT
char valorBT; // Valor enviado mediante Bluetooth
char ultimoValor; // Almacena el ultimo estado del dispositivo


/* Bloque de inicio */

void setup()  
{  
  // Iniciacion comunicacion Serial
  Serial.begin(9600);

  // Configuracion de los pines para el motor 1  
  pinMode(MOTOR1_MV1,OUTPUT);  
  pinMode(MOTOR1_MV2,OUTPUT);  
  pinMode(MOTOR1_PWM,OUTPUT);  
     
  // Configuracion de los pines para el motor 2
  pinMode(MOTOR2_MV1,OUTPUT);  
  pinMode(MOTOR2_MV2,OUTPUT);  
  pinMode(MOTOR2_PWM,OUTPUT);     
} 



/* --------------------------------- */
/*            Funciones              */
/* --------------------------------- */

// TODO_p. Empaquetar funciones en una biblioteca.


/* Variación de la velocidad */
/* Permite variar la velocidad mediate las salidas PWM */
/* Rango 0-255 */
// TODO_p. Variacion de 0-100, con tope.
void setSpeed(char motor_name, char motor_speed)  
{  
   if (motor_name == 1)  
   {  
      analogWrite(MOTOR1_PWM, motor_speed);  
   }     
   else  
   {  
      analogWrite(MOTOR2_PWM, motor_speed);  
   }  
}  


/* Básicas del motor */
/* Hacia delante o hacia atrás, cada lado */
// TODO_p. Movimientos complejos. Delante y atras juntas.
// TODO_p. Explicar char, byte...
// TODO_p. Explicar switch.
void motorStart(char motor_name, byte direction)  
{  
  char pin_mv1;  
  char pin_mv2;  
   
  // Asigna el motor que se controla  
  if (motor_name == 1)  
  { 
    pin_mv1 = MOTOR1_MV1;  
    pin_mv2 = MOTOR1_MV2;  
  }     
  else  
  {  
    pin_mv1 = MOTOR2_MV1;  
    pin_mv2 = MOTOR2_MV2;        
  }  
    
  switch (direction)  
  {  
    case MOTOR_DIR_FORWARD:  
    {  
      digitalWrite(pin_mv1,HIGH);  
      digitalWrite(pin_mv2,LOW);            
    }  
    break;   
            
    case MOTOR_DIR_BACKWARD:  
    {  
      digitalWrite(pin_mv1,LOW);  
      digitalWrite(pin_mv2,HIGH);            
    }  
    break;           
  }  
}


/* Parar motor */
/* Para el motor, por lados */  
void motorStop(char motor_name)  
{
  setSpeed(motor_name, 0);  
  if (motor_name == 1)
  {
    digitalWrite(MOTOR1_MV1,HIGH);  
    digitalWrite(MOTOR1_MV2,HIGH);       
  }  
  else  
  {
    digitalWrite(MOTOR2_MV1,HIGH);  
    digitalWrite(MOTOR2_MV2,HIGH);       
  }  
}


/* Movimientos compuestos */
/* Delante, atras, derecha, izquierda */
void move(char dir)
{
  switch(dir)
  {
    case 'w':
    {
      motorStart(1, MOTOR_DIR_FORWARD);    
      setSpeed(1, 200);  
      motorStart(2, MOTOR_DIR_FORWARD);        
      setSpeed(2, 200);
    }
    break;

    case 's':
    {
      motorStart(1, MOTOR_DIR_BACKWARD);    
      setSpeed(1, 200);  
      motorStart(2, MOTOR_DIR_BACKWARD);        
      setSpeed(2, 200);
    }
    break;

    case 'd':
    {
      motorStart(1, MOTOR_DIR_BACKWARD);    
      setSpeed(1, 240);  
      motorStart(2, MOTOR_DIR_FORWARD);        
      setSpeed(2, 240);

    }
    break;

    case 'a':
    {
      motorStart(1, MOTOR_DIR_FORWARD);    
      setSpeed(1, 240);  
      motorStart(2, MOTOR_DIR_BACKWARD);        
      setSpeed(2, 240);
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


/* Bucle */
// TODO_p. Pasar de teclado a autonomo.
// TODO_p. Control por teclado sin enter.

void loop()  
{  
  if (Serial.available() > 0)
  {
    valorBT = Serial.read();
    move(valorBT);
    delay(100);
  }
}  


