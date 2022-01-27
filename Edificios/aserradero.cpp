#include "aserradero.h"



// ------------------------------------------------------------------------------------------------------------


Aserradero::Aserradero(char identificador, Jugador_t creador, double deposito) : Edificio(identificador, creador, deposito) {
    this -> identificador_material_brindado = IDENTIF_MADERA;
    this -> cantidad_material_brindado = CANTIDAD_MADERA_BRINDADA;
}


// ------------------------------------------------------------------------------------------------------------


string Aserradero::obtener_tipo_edificio(){
    
    return STR_ASERRADERO;
}


// ------------------------------------------------------------------------------------------------------------


char Aserradero::obtener_identificador_recurso(){

    return this -> identificador_material_brindado;
}


// ------------------------------------------------------------------------------------------------------------


void Aserradero::depositar_recurso(){

    this -> deposito+= cantidad_material_brindado ;
    
}
