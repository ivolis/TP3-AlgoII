#ifndef ABB_H
#define ABB_H

#include "ABB_Nodo.h"
#include <iostream>
#include <fstream>

template <typename T, typename C>
class ABB
{
private:
    // Atributos:
    ABBNodo<T,C>* raiz;

    // Metodos:

    // Estos metodos son privados, porque manejan los nodos.
    ABBNodo<T,C>* insertar(ABBNodo<T,C>* nodo, T* dato, C clave);
    void imprimir_en_orden(ABBNodo<T,C>* nodo);
    void guardar_en_archivo(ABBNodo<T,C>* nodo, fstream& archivo);
    ABBNodo<T,C>* buscar(ABBNodo<T,C>* nodo, C clave);
    ABBNodo<T,C>* buscar_const(ABBNodo<T,C>* nodo, C clave) const;
    C buscar_minimo(ABBNodo<T,C>* nodo);
    C buscar_maximo(ABBNodo<T,C>* nodo);
    C sucesor(ABBNodo<T,C>* nodo);
    C predecesor(ABBNodo<T,C>* nodo);
    ABBNodo<T,C>* remover(ABBNodo<T,C>* nodo, C clave);
    void remover_todo(ABBNodo<T,C>* nodo);

    

public:

    // Metodos:

    // pre: -
    // pos: Constructor clase ABB
    ABB();
    
    // pre: ABB previemnte creado
    // pos: Nodo inserrado en el orden correspondiente segun la clave
    void insertar(T* dato, C clave);

    // pre: Este metodo solo se puede usar si el arbol tiene como dato estructuras complejas, y ademas debe tener un metodo llamado mostrar_informacion()
    // pos: 
    void imprimir_en_orden();

    // pre: Este metodo solo se puede usar si el arbol tiene como dato estructuras complejas, y ademas debe tener un metodo llamado guardar_informacion()
    // pos:
    void guardar_en_archivo(fstream& archivo);

    // pre: ABB previamnete creado
    // pos: Devuelve booleano verdadero si se encuentra el nodo que contiene la clave
    bool buscar(C clave);

    // pre: ABB previamnete creado
    // pos: Devuelve el nodo que contiene la clave
    ABBNodo<T,C>* consultar(C clave);

    // pre: ABB previamnete creado
    // pos: Devuelve el nodo que contiene la clave en modo const
    ABBNodo<T,C>* consultar_const(C clave) const;

    // pre: ABB previamnete creado
    // pos: Devuelve la clave de menor valor que se encuentra en el arbol
    C buscar_minimo();

    // pre: ABB previamnete creado
    // pos: Devuelve la clave de mayor valor que se encuentra en el arbol
    C buscar_maximo();

    // pre: ABB previamnete creado
    // pos: Devuelve la clave del siguiente nodo en orden que corresponde en el arbol
    C sucesor(C clave);

    // pre: ABB previamnete creado
    // pos: Devuelve la clave del nodo previo en orden que corresponde en el arbol
    C predecesor(C clave);

    // pre: ABB previamnete creado
    // pos: Remueve un nodo del arbol buscado por clave
    void remover(C clave);

    // pre: ABB previamnete creado
    // pos: Devuelve el nodo raiz del arbol
    ABBNodo<T,C>* obtener_raiz();

    // pre: 
    // pos: Bolleano verdadera en caso de no existir raiz en el arbol
    bool vacio();

    // pre: ABB previamnete creado
    // pos: Remueve todo los nodos del arbol
    void remover_todo();

    // pre: ABB previamnete creado
    // pos: Destructor de la clase ABB
    ~ABB<T,C>();

};


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
ABB<T,C>::ABB(){

    this -> raiz = NULL;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
ABBNodo<T,C>* ABB<T,C>::insertar(ABBNodo<T,C>* nodo, T* dato, C clave) {

    if(nodo == NULL){
        nodo = new ABBNodo<T,C>(dato, clave);
    }

    else if (clave > nodo -> obtener_clave()){
        nodo -> colocar_derecha(insertar(nodo -> obtener_derecha(), dato, clave), nodo);
    }

    else {
        nodo -> colocar_izquierda(insertar(nodo -> obtener_izquierda(), dato, clave), nodo);
    }

    return nodo;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
void ABB<T,C>::insertar(T* dato, C clave){

    this -> raiz = insertar(this -> raiz, dato, clave);
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
void ABB<T,C>::imprimir_en_orden(ABBNodo<T,C>* nodo){

    if (nodo != NULL){
        imprimir_en_orden(nodo -> obtener_izquierda());
        nodo -> obtener_dato() -> mostrar_informacion();
        imprimir_en_orden(nodo -> obtener_derecha());
    }
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
void ABB<T,C>::imprimir_en_orden(){
    
    this -> imprimir_en_orden(this -> raiz);
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
void ABB<T,C>::guardar_en_archivo(ABBNodo<T,C>* nodo, fstream& archivo){

    if (nodo != NULL){
        guardar_en_archivo(nodo -> obtener_izquierda(), archivo);
        nodo -> obtener_dato() -> guardar_informacion(archivo);
        guardar_en_archivo(nodo -> obtener_derecha(), archivo);
    }
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
void ABB<T,C>::guardar_en_archivo(fstream& archivo){
    
    this -> guardar_en_archivo(this -> raiz, archivo);
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
ABBNodo<T,C>* ABB<T,C>::buscar(ABBNodo<T,C>* nodo, C clave){

    if (nodo == NULL || nodo -> obtener_clave() == clave){
        return nodo;
    }

    if (clave > nodo -> obtener_clave())
        return buscar(nodo -> obtener_derecha(), clave);
    
    return buscar(nodo -> obtener_izquierda(), clave);
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
ABBNodo<T,C>* ABB<T,C>::buscar_const(ABBNodo<T,C>* nodo, C clave) const{

    if (nodo == NULL || nodo -> obtener_clave() == clave){
        return nodo;
    }

    if (clave > nodo -> obtener_clave())
        return buscar_const(nodo -> obtener_derecha(), clave);
    
    return buscar_const(nodo -> obtener_izquierda(), clave);
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
bool ABB<T,C>::buscar(C clave){

    ABBNodo<T,C>* resultado = buscar(this -> raiz, clave);

    return resultado != NULL;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
ABBNodo<T,C>* ABB<T,C>::consultar(C clave){

    ABBNodo<T,C>* resultado = buscar(this -> raiz, clave);

    return resultado;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
ABBNodo<T,C>* ABB<T,C>::consultar_const(C clave) const{

    ABBNodo<T,C>* resultado = buscar_const(this -> raiz, clave);

    return resultado;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
C ABB<T,C>::buscar_minimo(ABBNodo<T,C>* nodo){

    if(nodo == NULL)
        return "?"; // Antes habia un '-1'

    else if(nodo -> obtener_izquierda() == NULL)
        return nodo -> obtener_clave();

    else
        return buscar_minimo(nodo -> obtener_izquierda());
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
C ABB<T,C>::buscar_minimo(){
    return buscar_minimo(this -> raiz);
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
C ABB<T,C>::buscar_maximo(ABBNodo<T,C>* nodo){

    if(nodo == NULL)
        return "?"; //Antes habia un '-1'
    
    else if(nodo -> obtener_derecha() == NULL)
        return nodo -> obtener_clave();

    else
        return buscar_maximo(nodo -> obtener_derecha());
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
C ABB<T,C>::buscar_maximo(){
    return buscar_maximo(this -> raiz);
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
C ABB<T,C>::sucesor(ABBNodo<T,C>* nodo){

    if(nodo -> obtener_derecha() != NULL){

        return buscar_minimo(nodo -> obtener_derecha());
    }

    ABBNodo<T,C>* sucesor = NULL;
    ABBNodo<T,C>* ancestro = this -> raiz;
    while(ancestro != nodo){
        if(nodo -> obtener_clave() < ancestro -> obtener_clave()){
            sucesor = ancestro;
            ancestro = ancestro -> obtener_izquierda();
        }
        else
            ancestro = ancestro -> obtener_derecha();
    }

    return sucesor -> obtener_clave();
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
C ABB<T,C>::sucesor(C clave){

    ABBNodo<T,C>* nodo_clave = this -> buscar(this -> raiz, clave);

    if(nodo_clave == NULL)
        return "?"; // Antes habia un '-1'
    
    else return sucesor(nodo_clave);
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
C ABB<T,C>::predecesor(ABBNodo<T,C>* nodo)
{
    if (nodo -> obtener_izquierda() != NULL)
    {
        return buscar_maximo(nodo -> obtener_izquierda());
    }

    ABBNodo<T,C>* sucesor = NULL;
    ABBNodo<T,C>* ancestro = this -> raiz;
    while(ancestro != nodo){
        if(nodo -> obtener_clave() < ancestro -> obtener_clave()){
            sucesor = ancestro;
            ancestro = ancestro -> obtener_derecha();
        }
        else
            ancestro = ancestro -> obtener_izquierda();
    }

    return sucesor -> obtener_clave();
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
C ABB<T,C>::predecesor(C clave)
{
    ABBNodo<T,C>* nodo_clave = this -> buscar(this -> raiz, clave);

    if(nodo_clave == NULL)
        return "?"; // Antes habia un '-1'
    
    else return predecesor(nodo_clave);
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
ABBNodo<T,C>* ABB<T,C>::remover(ABBNodo<T,C>* nodo, C clave){

    if(nodo == NULL)
        return NULL;

    if(nodo -> obtener_clave() == clave){

        if(nodo -> es_hoja())
            delete nodo;
        
        else if(nodo -> tiene_solo_hijo_derecho()){

            nodo -> obtener_derecha() -> colocar_padre(nodo -> obtener_padre());

            ABBNodo<T,C>* aux = nodo;
            nodo = nodo -> obtener_derecha();
            delete aux;
        }

        else if(nodo -> tiene_solo_hijo_izquierdo()){

            nodo -> obtener_izquierda() -> colocar_padre(nodo -> obtener_padre());

            ABBNodo<T,C>* aux = nodo;
            nodo = nodo -> obtener_izquierda();
            delete aux;
        }

        else{

            C clave_sucesor = this -> sucesor(clave);

            T* dato_sucesor = this -> consultar(clave_sucesor) -> obtener_dato();

            nodo -> colocar_dato(dato_sucesor);

            nodo -> colocar_derecha(remover(nodo -> obtener_derecha(), clave_sucesor));
        }
    }

    else if(nodo -> obtener_clave() < clave)
        nodo -> colocar_derecha(remover(nodo -> obtener_derecha(), clave));

    else
        nodo -> colocar_izquierda(remover(nodo -> obtener_izquierda(), clave));

    return nodo;    
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
void ABB<T,C>::remover(C clave){

    this -> raiz = remover(this -> raiz, clave);
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
ABBNodo<T,C>* ABB<T,C>::obtener_raiz(){

    return this -> raiz;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
bool ABB<T,C>::vacio(){

    return this -> raiz == NULL;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
void ABB<T,C>::remover_todo(ABBNodo<T,C>* nodo){

    if(nodo == NULL)
        return;
    this -> remover_todo(nodo -> obtener_izquierda());
    this -> remover_todo(nodo -> obtener_derecha());
    delete nodo;
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
void ABB<T,C>::remover_todo(){

    this -> remover_todo(this -> raiz);
}


// -----------------------------------------------------------------------------------------


template <typename T, typename C>
ABB<T,C>::~ABB<T,C>(){

    this -> remover_todo();
}


#endif // ABB_H