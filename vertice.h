#ifndef VERTICE_H
#define VERTICE_H

const int INFINITO = 99999999;

#include "lista.h"

class Vertice{

private:
    // Atributos
    int indice;
    int pos_x;
    int pos_y;
    int cantidad_conexiones;
    Lista<int> lista_conexiones;
    Lista<int> lista_pesos;

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR del vertice por default
    Vertice();

    // pre: -
    // pos: CONSTRUCTOR del vertice por parametros
    Vertice(int indice, int pos_x, int pos_y);

    // pre: -
    // pos: DESTRUCTOR del vertice (deberia llamar nomas a los destructores de lista)
    ~Vertice(){};

    // pre: -
    // pos: devuelve el indice del vertice
    int obtener_indice();

    // pre: -
    // pos: devuelve la posicion en x del vertice (en funcion del mapa)
    int obtener_posx();

    // pre: -
    // pos: devuelve la posicion en y del vertice (en funcion del mapa)
    int obtener_posy();

    // pre: - 
    // pos: devuelve cuantas conexines tiene el vertice
    int obtener_cantidad_conexiones();

    // pre: - 
    // pos: devuelve el indice del vertice al que esta conectado
    int obtener_elemento_de_lista_conexiones(int posicion);

    // pre: - 
    // pos: devuelve los pesos de la arista
    int obtener_elemento_de_lista_pesos(int posicion);

    // pre: -
    // pos: conecta el vertice con otro (basicamente crea un camino/arista)
    void conectar_vertice(int indice, int peso);



};





#endif // VERTICE_H