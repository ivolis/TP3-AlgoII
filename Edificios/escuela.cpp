#include "escuela.h"


// ------------------------------------------------------------------------------------------------------------


Escuela::Escuela(char identificador, Jugador_t creador, double deposito) : Edificio(identificador, creador, deposito){

    this -> identificador_material_brindado = IDENTIF_ANDYCOINS;
    this -> cantidad_material_brindado = CANTIDAD_ANDYCOINS_BRINDADAS_ESCUELA;
}


// ------------------------------------------------------------------------------------------------------------


string Escuela::obtener_tipo_edificio(){

    return STR_ESCUELA;
}


// ------------------------------------------------------------------------------------------------------------


char Escuela::obtener_identificador_recurso(){

    return this -> identificador_material_brindado;
}


// ------------------------------------------------------------------------------------------------------------


void Escuela::depositar_recurso(){

    this -> deposito += cantidad_material_brindado;

}