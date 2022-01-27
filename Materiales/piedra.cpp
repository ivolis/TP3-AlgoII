#include <iostream>
#include "piedra.h"


// ------------------------------------------------------------------------------------------------------------


Piedra::Piedra(double cantidad) : Material(cantidad) {

    this -> identificador = IDENTIF_PIEDRA;

}


// ------------------------------------------------------------------------------------------------------------


string Piedra::obtener_nombre_material(){

    return STR_PIEDRA;
    
}
