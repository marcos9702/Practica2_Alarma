>Creado por:  Flores Bonilla José Marcos; 

>Contacto:    marcos9702@gmail.com;

#### OBJETIVO:
  -Desarrollar una alarma para cuando algun individuo entre sin autorizacion esta se active y solo podra ser desactivada por el encargado

  - Reducir el consumo de energía al mínimo. Mientras la alarma no esté sonando el arduino deberá consumir la mínima cantidad de         energía. Cuando la puerta se cierre esta deberá de dejar de sonar y regresar al estado de bajo consumo energético. Para ello se utilizaran
interrupciones.



#### HERRAMIENTAS DE DESARROLLO:
  - Arduino IDE
  - Fritzing


#### MATERIALES:
  - Arduino UNO
  - Protoboard
  - Reed switch
  - Buzzer
  - Led
  - Resistencias (1K, 220 ohms)
  - Imán
  - Cables
  - Jumpers


# Diagrama circuito

![alt tag](https://github.com/marcos9702/Practica2_Alarma/blob/master/diagrama.png)

# Diagrama en protoboard

![alt tag](https://github.com/marcos9702/Practica2_Alarma/blob/master/dise%C3%B1o.png)

# Procedimiento

 El programa consiste en que la alarma estara apagada hasta que un individuo (iman) se aproxime esta comenzara a zonar mediante una
 interrupcion y solo sera desactivada por el administrador (pushBoton) mediante otra interrupcion y de este modo se lograra el consumo minimo
 de energia ya que solo estara activado la alarma cuando se ejecuten las interrupciones y no siempre.

# Resultados

 Imagen del circuito apagado

![alt tag](https://github.com/marcos9702/Practica2_Alarma/blob/master/apagado.jpg)

 Imagen del circuito encendido

![alt tag](https://github.com/marcos9702/Practica2_Alarma/blob/master/encendido.jpg)

[![ver video de resultados](https://github.com/marcos9702/Practica2_Alarma/blob/master/video.mp4)

