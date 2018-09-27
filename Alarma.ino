const int pinSensor = 2;
const int pinSalida = 12;
volatile boolean enciende;

void setup(){
  pinMode(pinSnesor, INPUT_PULLUP);
  pinMode(pinSalida,OUTPUT);
  enciende=false;
  attachInterrupt(0, interrupcion,CHANGE);
}

void loop(){
  if (enciende==true){
    digitalWrite(pinSalida,HIGH);
  }else{
    digitalWrite(pinSalida,LOW);}
}

void interrupcion(){ 
  enciende=!enciende; 
}
