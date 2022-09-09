#include <KnightRoboticsLibs_Iroh.h>

int ld, lc, li, ultra, boton, ird, iri;

void setup() {
  inicializarSensores();
  inicializarPantalla();
}

void loop() {
  ld = leerSensorLineaDerecho();
  li = leerSensorLineaIzquierdo();
  lc = leerSensorLineaCentral();
  ird = leerSensorObstaculoDerecho();
  iri = leerSensorObstaculoIzquierdo();
  ultra =
  boton =
}