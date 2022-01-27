#include <iostream>
#include "terreno.h"


Terreno::Terreno(char identificador) : Superficie(identificador) {

    this -> color = "verde";
    this -> transitable = false;
    this -> construible = true;
    this -> accesible = true;
    costo_energia_jugador[JUGADOR_UNO] = 25;
    costo_energia_jugador[JUGADOR_DOS] = 25;
    
}