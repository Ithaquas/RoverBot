int echo = 13;
int trig = 12;

void setup() {
  Serial.begin(9600); //Objeto serial.funcion que vas a utlizar(velocidad de comunicacion)
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  long distancia;
  long duracion; //tambien valdria long distancia,duracion
  
  digitalWrite(trig,LOW); //estabilizar el pulso y se apaga el sensor primero
  delayMicroseconds(5);
  
  digitalWrite(trig,HIGH); //manda un pulso en 10 microsegundos
  delayMicroseconds(10);
  digitalWrite(trig,LOW); //se comienza a mandar el pulso 
  
  duracion = pulseIn(echo,HIGH); // la duracion deja de contar
  distancia = (duracion/2)/29.1;
  Serial.println(distancia); //entre dos porque va y viene y 29.1 porque es la distancia del sonido

  delay(5000);
};
