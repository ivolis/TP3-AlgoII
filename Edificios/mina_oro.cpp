#include "mina_oro.h"

Mina_oro::Mina_oro(char identificador, Jugador_t creador, double deposito) : Edificio(identificador, creador, deposito){

    this -> identificador_material_brindado = IDENTIF_ANDYCOINS;
    this -> cantidad_material_brindado = CANTIDAD_ANDYCOINS_BRINDADAS_MINA_ORO;
}


// ------------------------------------------------------------------------------------------------------------


string Mina_oro::obtener_tipo_edificio(){

    return STR_MINA_ORO;
}


// ------------------------------------------------------------------------------------------------------------


char Mina_oro::obtener_identificador_recurso(){

    return this -> identificador_material_brindado;
}


// ------------------------------------------------------------------------------------------------------------


void Mina_oro::depositar_recurso(){

    this -> deposito += cantidad_material_brindado;

}