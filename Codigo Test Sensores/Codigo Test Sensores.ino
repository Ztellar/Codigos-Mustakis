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
  ultra = leerDistanciaSonar();
  boton = leerBoton();

  borrarPantalla();
  escribirPantalla(0, 0, li);
  escribirPantalla(6, 0, lc);
  escribirPantalla(13, 0, ld);
  escribirPantalla(0, 1, iri);
  escribirPantalla(5, 1, ultra);
  escribirPantalla(10, 1, boton);
  escribirPantalla(15, 1, ird);
  delay(50);
}