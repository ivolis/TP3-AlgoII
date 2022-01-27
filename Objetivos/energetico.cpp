#include <iostream>
#include "energetico.h"


// ------------------------------------------------------------------------------------------------------------


Energetico::Energetico() : Objetivo(OBJ_ENERGETICO, false){}


// ------------------------------------------------------------------------------------------------------------


string Energetico::obtener_condiciones(){
    return CONDICIONES_ENERGETICO;
}


// ------------------------------------------------------------------------------------------------------------


void Energetico::actualizar_cumplimiento(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas){
    
    if(this -> cumplido) // Si el objetivo ya se cumplió no hace falta actualizar el cumplimiento.
        return;

    this -> cumplido = (cant_energia == CANT_ENERGIA_MAXIMA);

}


// ------------------------------------------------------------------------------------------------------------


string Energetico::obtener_progreso(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas){
    
    if(this -> cumplido)
        return OBJ_CUMPLIDO;

    stringstream sstream;
    sstream << "Tenes " << cant_energia << " de energia";

    return sstream.str();
   
}
