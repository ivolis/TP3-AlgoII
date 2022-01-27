#include <iostream>
#include "letrado.h"


// ------------------------------------------------------------------------------------------------------------


Letrado::Letrado() : Objetivo(OBJ_LETRADO, false){}


// ------------------------------------------------------------------------------------------------------------


string Letrado::obtener_condiciones(){
    return CONDICIONES_LETRADO;
}



// ------------------------------------------------------------------------------------------------------------


void Letrado::actualizar_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas){
    
    if(this -> cumplido) // Si el objetivo ya se cumplió no hace falta actualizar el cumplimiento.
        return;

    int cantidad_construidos = 0;

    for(int i=0; i < mis_edificios.obtener_cantidad(); i++){
        if( mis_edificios.consulta_const(i) -> obtener_nombre() == STR_ESCUELA ) 
           cantidad_construidos =  mis_edificios.consulta_const(i) -> obtener_cantidad_construidos();
    }

    this -> cumplido = (cantidad_construidos == cant_maxima_escuelas);
}


// ------------------------------------------------------------------------------------------------------------


string Letrado::obtener_progreso( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas){
      
    if(this -> cumplido)
        return OBJ_CUMPLIDO;

    int cantidad_construidos = 0;

    for(int i=0; i < mis_edificios.obtener_cantidad(); i++){
        if( mis_edificios.consulta_const(i) -> obtener_nombre() == STR_ESCUELA ) 
           cantidad_construidos =  mis_edificios.consulta_const(i) -> obtener_cantidad_construidos();
    }

    stringstream sstream;
    sstream << "Falta/n construir " << cant_maxima_escuelas - cantidad_construidos << " escuelas";

    return sstream.str();
}
