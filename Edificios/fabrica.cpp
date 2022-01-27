#include "fabrica.h"


// ------------------------------------------------------------------------------------------------------------


Fabrica::Fabrica(char identificador, Jugador_t creador, double deposito) : Edificio(identificador, creador, deposito) {

    this -> identificador_material_brindado = IDENTIF_METAL;
    this -> cantidad_material_brindado = CANTIDAD_METAL_BRINDADA;
}


// ------------------------------------------------------------------------------------------------------------


string Fabrica::obtener_tipo_edificio(){
    return STR_FABRICA;
}


// ------------------------------------------------------------------------------------------------------------


char Fabrica::obtener_identificador_recurso(){

    return this -> identificador_material_brindado;
}


// ------------------------------------------------------------------------------------------------------------


void Fabrica::depositar_recurso(){
    
    this -> deposito += cantidad_material_brindado;

}