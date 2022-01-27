#include <iostream>
#include "comprar_andypolis.h"


// ------------------------------------------------------------------------------------------------------------


Comprar_andypolis::Comprar_andypolis() : Objetivo(OBJ_COMPRAR_ANDYNOPOLIS, false){}


// ------------------------------------------------------------------------------------------------------------


string Comprar_andypolis::obtener_condiciones(){
    return CONDICIONES_COMPRAR_ANDYPOLIS;
}


// ------------------------------------------------------------------------------------------------------------


void Comprar_andypolis::actualizar_cumplimiento(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas){
    
    if(this -> cumplido) // Si el objetivo ya se cumplió no hace falta actualizar el cumplimiento.
        return;

    double total = ( (double) inventario.obtener_andycoins_gastadas() ) + inventario.obtener_cantidad_de_andycoins();
    this -> cumplido = ( total >= CANT_ANDYCOINS_OBJETIVO);

}


// ------------------------------------------------------------------------------------------------------------


string Comprar_andypolis::obtener_progreso( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas){
      
    if(this -> cumplido)
        return OBJ_CUMPLIDO;
  
    double total = ( (double) inventario.obtener_andycoins_gastadas() ) + inventario.obtener_cantidad_de_andycoins();

    stringstream sstream;
    sstream << "Faltan obtener " << CANT_ANDYCOINS_OBJETIVO - total << " andycoins";

    return sstream.str();
   
}
