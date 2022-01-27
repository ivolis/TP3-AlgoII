#include <iostream>
#include "andycoins.h"


// ------------------------------------------------------------------------------------------------------------


Andycoins::Andycoins(double cantidad) : Material(cantidad) {

    this -> identificador = IDENTIF_ANDYCOINS;
    
}


// ------------------------------------------------------------------------------------------------------------


string Andycoins::obtener_nombre_material(){

    return STR_ANDYCOINS;

}
