#include <KnightRoboticsLibs_Iroh.h>

int lc, ld, li;
int ir_der;
int ir_izq;
int var_estado = 0;
int ultra;

void setup() {
  inicializarMovimientoRobot();
  inicializarSensoresRobot();
  inicializarPantallaRobot();
  moverServoGolpe(0);
  borrarPantalla();
  botonInicio();
}

void loop() {
  ir_der = leerSensorObstaculoDerecho();
  ir_izq = leerSensorObstaculoIzquierdo();
  lc = leerSensorLineaCentral();
  li = leerSensorLineaIzquierdo();
  ld = leerSensorLineaDerecho();

  if (var_estado == 1) {
    if (ir_der == 0 && ir_izq == 0) {
      girarDerecha(50);
      delay(300);
      var_estado = 0;
    } else if (ir_der == 0) {
      avanzar(100);
      delay(100);
      var_estado = 0;
    } else if (ir_izq == 0) {
      girarIzquierda(50);
      delay(300);
      var_estado = 0;
    }
  } else if (var_estado == 0) {
    if (li <= 700 && lc >= 700 && ld <= 700) {  //Blanco Negro Blanco
      avanzar(100);
    } else if (li >= 700 && lc <= 700 && ld <= 700) {  // Negro Blanco Blanco
      mover(40, 100);
    } else if (li <= 700 && lc <= 700 && ld >= 700) {  //Blanco Blanco Negro
      mover(100, 40);
    } else if (li >= 700 && lc >= 700 && ld >= 700) {  //Negro x3
      detenerse();
      var_estado == 1;
    }
  }
}