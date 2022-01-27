#include <iostream>
#include "casillero.h"


// ------------------------------------------------------------------------------------------------------------


Casillero::Casillero(Superficie* superficie, int coord_x, int coord_y, bool ocupado, Jugador_t jugador){

    this -> superficie = superficie;
    this -> coord_x = coord_x;
    this -> coord_y = coord_y;
    this -> ocupado = ocupado;
    this -> jugador_en_casillero = jugador;

}


// ------------------------------------------------------------------------------------------------------------


Casillero::Casillero(){

    this -> coord_x = -1; // 0,0 ES una posicion valida en el mapa.
    this -> coord_y = -1;
    this -> ocupado = false;
    this -> jugador_en_casillero = NADIE;

}


// ------------------------------------------------------------------------------------------------------------

Casillero::~Casillero(){
    
    if(superficie!=nullptr){
        delete superficie;
        superficie=nullptr;
    }
}


// ------------------------------------------------------------------------------------------------------------


int Casillero::obtener_coordenada_x(){

    return coord_x;

}


// ------------------------------------------------------------------------------------------------------------


int Casillero::obtener_coordenada_y(){

    return coord_y;

}


// ------------------------------------------------------------------------------------------------------------


int Casillero::obtener_peso(Jugador_t jugador){

    int peso = 0;

    if(esta_ocupado()){
        if(hay_jugador() || es_casillero_construible()){
            peso = INFINITO;
        } else peso = superficie -> obtener_peso(jugador); 
    } else peso = superficie -> obtener_peso(jugador); 

    return peso;

}


// ------------------------------------------------------------------------------------------------------------


bool Casillero::esta_ocupado(){

    return this -> ocupado;

}


// ------------------------------------------------------------------------------------------------------------


bool Casillero::es_casillero_transitable(){

    return superficie -> es_transitable();

}


// ------------------------------------------------------------------------------------------------------------


bool Casillero::es_casillero_construible(){

    return superficie -> es_construible();

}


// ------------------------------------------------------------------------------------------------------------


bool Casillero::es_casillero_accesible(){

    return superficie -> es_accesible();

}


// ------------------------------------------------------------------------------------------------------------


bool Casillero::hay_jugador(){

    if(jugador_en_casillero != NADIE)
        return true;
    return false;

}


// ------------------------------------------------------------------------------------------------------------


void Casillero::posicionar_jugador(Jugador_t jugador){
    
    this -> ocupado = true;
    this -> jugador_en_casillero = jugador;

}


// ------------------------------------------------------------------------------------------------------------


void Casillero::eliminar_jugador( ){
    
    this -> ocupado = false;
    this -> jugador_en_casillero = NADIE;

}