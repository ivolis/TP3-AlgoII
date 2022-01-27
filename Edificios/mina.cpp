#include "mina.h"


// ------------------------------------------------------------------------------------------------------------


Mina::Mina(char identificador, Jugador_t creador, double deposito) : Edificio(identificador, creador, deposito) {

    this -> identificador_material_brindado = IDENTIF_PIEDRA;
    this -> cantidad_material_brindado = CANTIDAD_PIEDRA_BRINDADA;
}


// ------------------------------------------------------------------------------------------------------------


string Mina::obtener_tipo_edificio(){
    return STR_MINA;
}


// ------------------------------------------------------------------------------------------------------------


char Mina::obtener_identificador_recurso(){
    return this -> identificador_material_brindado;
}


// ------------------------------------------------------------------------------------------------------------


void Mina::depositar_recurso(){

    this -> deposito += cantidad_material_brindado;

}
