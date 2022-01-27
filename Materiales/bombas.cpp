#include <iostream>
#include "bombas.h"


// ------------------------------------------------------------------------------------------------------------


Bombas::Bombas(double cantidad) : Material(cantidad) {

    this -> identificador = IDENTIF_BOMBA;

}


// ------------------------------------------------------------------------------------------------------------


string Bombas::obtener_nombre_material(){

    return STR_BOMBAS;

}
