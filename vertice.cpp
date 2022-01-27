#include <iostream>
#include "vertice.h"


// ------------------------------------------------------------------------------------------------------------

Vertice::Vertice(int indice, int pos_x, int pos_y){

    this -> indice = indice;
    this -> pos_x = pos_x;
    this -> pos_y = pos_y;
    this -> cantidad_conexiones = 0;

}

// ------------------------------------------------------------------------------------------------------------

Vertice::Vertice(){

    this -> indice = -1;
    this -> pos_x = -1;
    this -> pos_y = -1;
    this -> cantidad_conexiones = 0;

}


// ------------------------------------------------------------------------------------------------------------


int Vertice::obtener_indice(){

    return this -> indice;

}


// ------------------------------------------------------------------------------------------------------------


int Vertice::obtener_posx(){

    return this -> pos_x;

}


// ------------------------------------------------------------------------------------------------------------


int Vertice::obtener_posy(){
    
    return this -> pos_y;

}


// ------------------------------------------------------------------------------------------------------------


int Vertice::obtener_cantidad_conexiones(){
    
    return this -> cantidad_conexiones;

}

// ------------------------------------------------------------------------------------------------------------

int Vertice::obtener_elemento_de_lista_conexiones(int posicion){

    return this -> lista_conexiones.consulta(posicion);

}


// ------------------------------------------------------------------------------------------------------------


int Vertice::obtener_elemento_de_lista_pesos(int posicion){

    return this -> lista_pesos.consulta(posicion);

}


// ------------------------------------------------------------------------------------------------------------


void Vertice::conectar_vertice(int indice, int peso){

    // ME LO EVITO USANDO PILA/COLA EN VEZ DE LISTA... 
    //std::cout << "Conexion (" << this->indice << "->" << indice<< "): // Nº" << cantidad_conexiones << std::endl;
    this -> lista_conexiones.alta(indice, cantidad_conexiones);
    this -> lista_pesos.alta(peso, cantidad_conexiones);

    this -> cantidad_conexiones++;

}