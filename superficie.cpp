#include <iostream>
#include "superficie.h"


// ------------------------------------------------------------------------------------------------------------


Superficie::Superficie(char identificador){

    this -> identificador = identificador;

}


// ------------------------------------------------------------------------------------------------------------


Superficie::Superficie(){

    this -> identificador = ' ';

}


// ------------------------------------------------------------------------------------------------------------


char Superficie::obtener_identificador(){

    return identificador;

}


// ------------------------------------------------------------------------------------------------------------


string Superficie::obtener_color(){

    return color;

}


// ------------------------------------------------------------------------------------------------------------


int Superficie::obtener_peso(Jugador_t jugador){

    return costo_energia_jugador[jugador];

}


// ------------------------------------------------------------------------------------------------------------


bool Superficie::es_transitable(){

    return transitable;

}


// ------------------------------------------------------------------------------------------------------------


bool Superficie::es_construible(){

    return construible;

}


// ------------------------------------------------------------------------------------------------------------


bool Superficie::es_accesible(){

    return accesible;

}