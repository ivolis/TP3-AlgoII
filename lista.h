#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include "nodo.h"

using namespace std;

template <typename Tipo>
class Lista {
    
private:
    // Atributos
    Nodo<Tipo>* primero;
    int cantidad;
    
public:
    // Metodos
    
    // pre: -
    // pos: CONSTRUCTOR de la lista
    Lista();

    // pre: posicion menor al largo de la lista (cantidad)
    // pos: da de alta un dato en un posicion en particular
    void alta(Tipo d, int pos);

    // pre: posicion menor al largo de la lista (cantidad)
    // pos: da de alta un dato en un posicion en particular
    void modificar(Tipo valor, int pos);

    // pre: posicion menor al largo de la lista (cantidad)
    // pre: devuelve el dato contenido en el nodo de una posicion en particular
    Tipo consulta(int pos);

    // pre: posicion menor al largo de la lista (cantidad)
    // pre: devuelve el dato contenido en el nodo de una posicion en particular
    int obtener_posicion(Tipo dato);

    // pre: posicion menor al largo de la lista (cantidad)
    // pre: devuelve el dato contenido en el nodo de una posicion en particular
    Tipo consulta_const(int pos) const;

    // pre: posicion menor al largo de la lista (cantidad)
    // pos: da de baja un nodo de una posicion en particualr
    void baja(int pos);

    // pre: -
    // pos: chequea que no este vacia la lista
    bool vacia();

    // pre: -
    // pos: DESTRUCTOR de la lista
    ~Lista();

    // pre: -
    // pos: devuelve la cantidad de nodos que hay en la lista
    int obtener_cantidad() const;


private:
    // pre: posicion menor al largo de la lista (cantidad)
    // pos: obtiene el nodo de una posicion en particular
    Nodo<Tipo>* obtener_nodo(int pos);

    // pre: posicion menor al largo de la lista (cantidad)
    // pos: obtiene el nodo de una posicion en particular
    Nodo<Tipo>* obtener_nodo_const(int pos) const;

};


// -----------------------------------------------------------------------------------------


template <typename Tipo>
Lista<Tipo>::Lista() {
    primero = nullptr;
    cantidad = 0;
}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
bool Lista<Tipo>::vacia() {
    return (cantidad == 0);
}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
void Lista<Tipo>::alta(Tipo d, int pos) {

    // cheq que pos < cantidad

    Nodo<Tipo>* nuevo_nodo = new Nodo<Tipo>(d);
    Nodo<Tipo>* ptr_siguiente_nodo_en_lista = primero;

    if (pos == 0) {
        primero = nuevo_nodo;
    } else {
        // Apunto el nuevo nodo
        Nodo<Tipo>* ptr_anterior_nodo_en_lista = obtener_nodo(pos-1);
        ptr_siguiente_nodo_en_lista = ptr_anterior_nodo_en_lista -> obtener_siguiente();
        ptr_anterior_nodo_en_lista -> cambiar_siguiente(nuevo_nodo);
    }

    nuevo_nodo->cambiar_siguiente(ptr_siguiente_nodo_en_lista);
    cantidad++;

}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
void Lista<Tipo>::baja(int pos) {
    
    Nodo<Tipo>* ptr_nodo_a_bajar = primero;
    // y si cantidad == 1?
    if (pos == 0)
        primero = ptr_nodo_a_bajar -> obtener_siguiente();
    else {
        Nodo<Tipo>* anterior_nodo_en_lista = obtener_nodo(pos-1);
        ptr_nodo_a_bajar = anterior_nodo_en_lista->obtener_siguiente();
        anterior_nodo_en_lista -> cambiar_siguiente(ptr_nodo_a_bajar -> obtener_siguiente());
    }

    cantidad--;
    delete ptr_nodo_a_bajar;
}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
Tipo Lista<Tipo>::consulta(int pos) {
    Nodo<Tipo>* aux = obtener_nodo(pos);
    return aux -> obtener_dato();
}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
void Lista<Tipo>::modificar( Tipo valor, int pos) {
    Nodo<Tipo>* aux = primero;
    for (int i = 0; i < pos; i++)
        aux = aux->obtener_siguiente_const();

    aux->cambiar_dato(valor);
}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
int Lista<Tipo>::obtener_posicion( Tipo dato) {
    Nodo<Tipo>* aux = primero;
    int i;
    for (i = 0; aux->obtener_dato_const() != dato ; i++)
        aux = aux->obtener_siguiente();

    return i;
}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
Tipo Lista<Tipo>::consulta_const(int pos) const{
    Nodo<Tipo>* aux = obtener_nodo_const(pos);
    return aux -> obtener_dato_const();
}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
Lista<Tipo>::~Lista() {
    while (! vacia())
        baja(0);
}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
Nodo<Tipo>* Lista<Tipo>::obtener_nodo(int pos) {

    Nodo<Tipo>* aux = primero;
    for (int i = 0; i < pos; i++)
        aux = aux->obtener_siguiente();

    return aux;

}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
Nodo<Tipo>* Lista<Tipo>::obtener_nodo_const(int pos) const{

    Nodo<Tipo>* aux = primero;
    for (int i = 0; i < pos; i++)
        aux = aux->obtener_siguiente_const();

    return aux;

}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
int Lista<Tipo>::obtener_cantidad() const{
    return cantidad;
}



#endif // LISTA_H