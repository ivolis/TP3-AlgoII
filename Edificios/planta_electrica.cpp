#include "planta_electrica.h"


// ------------------------------------------------------------------------------------------------------------


Planta_electrica::Planta_electrica(char identificador, Jugador_t creador, double deposito) : Edificio(identificador, creador, deposito){

    this -> cantidad_energia_brindada = CANTIDAD_ENERGIA_BRINDADA;
}


// ------------------------------------------------------------------------------------------------------------


string Planta_electrica::obtener_tipo_edificio(){

    return STR_P_ELECTRICA;
}


// ------------------------------------------------------------------------------------------------------------


void Planta_electrica::depositar_recurso(){

    this -> deposito += cantidad_energia_brindada;

}