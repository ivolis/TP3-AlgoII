#include <iostream>
#include "camino.h"


Camino::Camino(char identificador) : Superficie(identificador) {

    this -> color = "gris";
    this -> transitable = true;
    this -> construible = false;
    this -> accesible = true;
    costo_energia_jugador[JUGADOR_UNO] = 4;
    costo_energia_jugador[JUGADOR_DOS] = 4;
    
}