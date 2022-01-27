#include <iostream>
#include "madera.h"


// ------------------------------------------------------------------------------------------------------------


Madera::Madera(double cantidad) : Material(cantidad) {

    this -> identificador = IDENTIF_MADERA;
    
}


// ------------------------------------------------------------------------------------------------------------


string Madera::obtener_nombre_material(){

    return STR_MADERA;

}
