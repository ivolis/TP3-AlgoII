#include <iostream>
#include "metal.h"


// ------------------------------------------------------------------------------------------------------------


Metal::Metal(double cantidad) : Material(cantidad) {

    this -> identificador = IDENTIF_METAL;

}


// ------------------------------------------------------------------------------------------------------------


string Metal::obtener_nombre_material(){

    return STR_METAL;

}
