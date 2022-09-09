#include <KnightRoboticsLibs_Iroh.h>

int li, lc, ld, cont;

void setup() {
  inicializarMovimiento();
  inicializarSensores();
  botonInicio();
}

void loop() {
  li = leerSensorLineaIzquierdo();
  lc = leerSensorLineaCentral();
  ld = leerSensorLineaDerecho();

  if (li >= 500 && lc >= 500 && ld >= 500 && cont < 2) {  //Negro Full
    detenerse();
    delay(1000);
    avanzar(100);
    delay(100);
    cont++;
  } else if (li >= 500 && lc >= 500 && ld >= 500 && cont >= 3) {  //Negro Full >= 3
    detenerse();
  } else if (li <= 500 && lc <= 500 && ld <= 500) {  //Blanco Full
    avanzar(100);
    delay(400);
  } else if (li <= 500 && lc >= 500 && ld <= 500) {  //BNB
    avanzar(100);
  } else if (li >= 500 && lc <= 500 && ld <= 500) {  //NBB
    mover(40, 100);
  } else if (li <= 500 && lc <= 500 && ld >= 500) {  //BBN
    mover(100, 40);
  }
}