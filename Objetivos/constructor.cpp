#include <iostream>
#include "constructor.h"


// ------------------------------------------------------------------------------------------------------------


Constructor::Constructor() : Objetivo(OBJ_CONSTRUCTOR, false){}


// ------------------------------------------------------------------------------------------------------------


string  Constructor::obtener_condiciones(){
    return CONDICIONES_CONSTRUCTOR;
}


// ------------------------------------------------------------------------------------------------------------


void Constructor::actualizar_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas){

    if(this -> cumplido) // Si el objetivo ya se cumplió no hace falta actualizar el cumplimiento.
        return;

    if(mis_edificios.obtener_cantidad() == CANTIDAD_EDIFICIOS_OBJETIVO){
        this -> cumplido = true;
    } else this -> cumplido = false;
    
}


// ------------------------------------------------------------------------------------------------------------


string Constructor::obtener_progreso( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas){
    
    if(this -> cumplido)
        return OBJ_CUMPLIDO;

    stringstream sstream;
    sstream << "Falta/n construir " << CANTIDAD_EDIFICIOS_OBJETIVO - mis_edificios.obtener_cantidad() << " tipo/s de edificio";

    return sstream.str();
   
}
