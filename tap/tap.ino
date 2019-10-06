#include "Servo.h"

Servo subida0; // objetos servos
Servo subida1;
Servo caida0;
Servo caida1;

int pos0 = 180; // var posicion servos subida
int rep = 0;    // var repeticiones, no modifcar valor aqui

void setup() {

  pinMode(12, INPUT_PULLUP); // modo pin digital 12 input con resistencia pullup
  
  caida0.attach(4); // asignar salidas digitales servos
  caida1.attach(5);
  subida0.attach(7);
  subida1.attach(8);

  caida0.write(0); // servos posicion inicial
  caida1.write(0);
  subida0.write(180);
  subida1.write(180);
}

void loop() {
    if (digitalRead(12) == LOW) { // valor low = boton pulsado
      for (rep = 0; rep < 100 ; rep++) { // contador de repeticiones, modificar valor aqui
       for (pos0 = 180; pos0 >= 140; pos0 -= 2) { // subir desde posicion inicial
          subida0.write(pos0);
          subida1.write(pos0);
          delay(40);
       }
       caida0.write(90); // bloquear plataforma tap arriba
       caida1.write(90);
       for (pos0 = 140; pos0 <= 180; pos0 += 2) { // bajar servos
        subida0.write(pos0);
        subida1.write(pos0);
        delay(40);
       }
       delay(100);
       caida0.write(0); // espera 0,1 segundo y hace caer plataforma
       caida1.write(0);
       delay(300); // tiempo antes de repetir la subida 0,3 s
      }
 }
    delay(20);
}
