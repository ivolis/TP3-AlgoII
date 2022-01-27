#include <iostream>
#include "extremista.h"


// ------------------------------------------------------------------------------------------------------------


Extremista::Extremista() : Objetivo(OBJ_EXTREMISTA, false){}


// ------------------------------------------------------------------------------------------------------------


string Extremista::obtener_condiciones(){
    return CONDICIONES_EXTREMISTA;
}


// ------------------------------------------------------------------------------------------------------------


void Extremista::actualizar_cumplimiento(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas){

    if(this -> cumplido) // Si el objetivo ya se cumplió no hace falta actualizar el cumplimiento.
        return;

    this -> cumplido = (inventario.obtener_bombas_compradas() >= CANT_BOMBAS_COMPRADAS_OBJETIVO);

}


// ------------------------------------------------------------------------------------------------------------


string Extremista::obtener_progreso( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas){
    
    if(this -> cumplido)
        return OBJ_CUMPLIDO;


    stringstream sstream;
    sstream << "Falta/n comprar " << CANT_BOMBAS_COMPRADAS_OBJETIVO  - inventario.obtener_bombas_compradas() << " bomba/s";

    return sstream.str();

}
