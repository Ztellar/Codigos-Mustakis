#include <KnightRoboticsLibs_Iroh.h>

int li, lc, ld, irDer, irIzq, contador;

void setup() {
  inicializarSensores();
  inicializarMovimiento();
  inicializarPantalla();
  botonInicio();
}

void loop() {
  borrarPantalla();
  li = leerSensorLineaIzquierdo();
  lc = leerSensorLineaCentral();
  ld = leerSensorLineaDerecho();
  irDer = leerSensorObstaculoDerecho();
  irIzq = leerSensorObstaculoIzquierdo();

  if (irDer == 0 || irIzq == 0) {
    contador++;
    while (irDer == 0 || irIzq == 0) {
      irDer = leerSensorObstaculoDerecho();
      irIzq = leerSensorObstaculoIzquierdo();
    }
  }
  escribirPantalla(5, 0, contador);

  if (li <= 500 && lc >= 500 && ld <= 500) {
    avanzar(100);
  } else if (li >= 500 && lc <= 500 && ld <= 500) {
    avanzar(40, 100);
  } else if (li <= 500 && lc <= 500 && ld >= 500) {
    avanzar(100, 40);
  }
}