#include <iostream>
#include "lago.h"


Lago::Lago(char identificador) : Superficie(identificador) {

    this -> color = "azul";
    this -> transitable = false;
    this -> construible = false;
    this -> accesible = false;
    costo_energia_jugador[JUGADOR_UNO] = 2;
    costo_energia_jugador[JUGADOR_DOS] = 5;
    
}

