#include <iostream>
#include "minero.h"


// ------------------------------------------------------------------------------------------------------------


Minero::Minero():Objetivo( OBJ_MINERO, false){}


// ------------------------------------------------------------------------------------------------------------


string Minero::obtener_condiciones(){
    return CONDICIONES_MINERO;
}



// ------------------------------------------------------------------------------------------------------------


void Minero::actualizar_cumplimiento(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuela){

    if(this -> cumplido) // Si el objetivo ya se cumplió no hace falta actualizar el cumplimiento.
        return;
        
    int contador = 0;

    for(int i = 0 ; i < mis_edificios.obtener_cantidad() ; ++i){
        if(mis_edificios.consulta_const(i) -> obtener_nombre() == STR_MINA || mis_edificios.consulta_const(i) -> obtener_nombre() == STR_MINA_ORO)
            contador++;
    }

    this -> cumplido = (contador == CANT_MINAS_OBJETIVO);
}


// ------------------------------------------------------------------------------------------------------------


string Minero::obtener_progreso(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuela){
        
    if(this -> cumplido)
        return OBJ_CUMPLIDO;

    
    int contador = 0;

    for(int i = 0 ; i < mis_edificios.obtener_cantidad() ; ++i){
        if(mis_edificios.consulta_const(i) -> obtener_nombre() == STR_MINA || mis_edificios.consulta_const(i) -> obtener_nombre() == STR_MINA_ORO)
            contador++;
    }

    stringstream sstream;
    sstream << "Falta/n construir " << CANT_MINAS_OBJETIVO - contador << " tipo/s de mina";

    return sstream.str();
   
}
