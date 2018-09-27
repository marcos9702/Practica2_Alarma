#include <LowPower.h>

/* Flores Bonilla José Marcos
 * Instituto Tecnologico de León
 * Ingeniería en Sistemas Computacionales
 * Sistemas Programables 
 * 
 * Alarma notificadora de seguridad
 */
 #include "LowPower.h" 

//delcaramos de constantes 
const int intervaloTiempo = 250; // intervalo de tiempo para controlar ruido
const int pinSensor = 2;         // pin del Reed Switch
const int pinSalida = 12;        // pin de salida para led y buzzer
const int pinBoton = 3;          // pin para pushBoton

//declaracion de variables
volatile int ISRContador = 0;    // contabilizar el tiempo de ejecucion de Reed Switch
volatile int enciende;       // encender o apagar la Reed Switch

//variables para calcular tiempo
int contadorReal = 0;            // mostrar en monitor el tiempo de ejecucion acumulable
long contaTiempo1 = 0;           // tiempo de ejecucion de Reed Switch
long contaTiempo2 = 0;           // tiempo de ejecucion de pushBoton

void setup(){
  pinMode(pinSensor, INPUT_PULLUP);
  pinMode(pinBoton , INPUT_PULLUP);
  pinMode(pinSalida,OUTPUT);
  Serial.begin(9600);
  enciende=LOW; 
  //interrupcion de Reed Switch cuando esta apagado a encendido
  attachInterrupt(0, interrupcionEncendido,RISING);
  //interrupcion de PushBoton cuando es presionado
  attachInterrupt(1, interrupcionAPagado,FALLING);
}

void loop(){
  //ahorro de energia durmiendo el arduino hasta que se use
  LowPower.powerDown(SLEEP_FOREVER,ADC_OFF,BOD_OFF);
  if (enciende==LOW)
        digitalWrite(pinSalida,LOW);
  else{
    contadorReal = ISRContador; //guardamos tiempo de ejecucion de reed y mostramos
    Serial.println(contadorReal);
    digitalWrite(pinSalida,HIGH);  
  }
}

//interrupcion que funciona cuando el switch cambia de estado
void interrupcionEncendido(){ 
  //verificamos si no es un efecto rebote y cambiamos de estado "enciende"
  if (millis() > contaTiempo1 + intervaloTiempo){
    ISRContador++;
    contaTiempo1 = millis();
    enciende=HIGH; 
  }
}

//interrupcion que funciona cuando el pushBoton es presionado
void interrupcionAPagado(){ 
    //verificamos si no es un efecto rebote de pushBoton y cambiamos de estado "enciende"
  if (millis() > contaTiempo2 + intervaloTiempo){
    contaTiempo2 = millis();
    enciende=LOW; 
  }
}
