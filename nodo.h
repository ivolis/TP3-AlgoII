#ifndef NODO_H
#define NODO_H

template <typename Tipo>
class Nodo {

private:
    //Atributos
    Tipo dato;
    Nodo* siguiente;
    //Nodo* anterior;


public:
    //Metodos

    
    //PRE:
    //POS: CONSTRUCTOR de nodo
    Nodo(Tipo d);

    //PRE:
    //POS: cambia el dato contenido en el nodo
    void cambiar_dato(Tipo d);

    //PRE: -
    //POS: cambia hacia adonde apunta siguiente el nodo
    void cambiar_siguiente(Nodo* pn);

    //PRE: -
    //POS: obtiene el dato contenido en el nodo
    Tipo obtener_dato();

    //PRE: -
    //POS: obtiene el dato contenido en el nodo
    Tipo obtener_dato_const() const;

    //PRE: -
    //POS: obtiene la direccion del nodo siguiente hacia el que esta apuntando el nodo
    Nodo* obtener_siguiente();

    //PRE: -
    //POS: obtiene la direccion del nodo siguiente hacia el que esta apuntando el nodo
    Nodo* obtener_siguiente_const() const;


};


// -----------------------------------------------------------------------------------------


template <typename Tipo>
Nodo<Tipo>::Nodo(Tipo d) {
    dato = d;
    siguiente = nullptr;
    //anterior = nullptr;
}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
void Nodo<Tipo>::cambiar_dato(Tipo d) {
    dato = d;
}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
void Nodo<Tipo>::cambiar_siguiente(Nodo* pn) {
    siguiente = pn;
}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
Tipo Nodo<Tipo>::obtener_dato() {
    return dato;
}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
Tipo Nodo<Tipo>::obtener_dato_const() const{
    return dato;
}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
Nodo<Tipo>* Nodo<Tipo>::obtener_siguiente() {
    return siguiente;
}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
Nodo<Tipo>* Nodo<Tipo>::obtener_siguiente_const() const{
    return siguiente;
}


// -----------------------------------------------------------------------------------------


#endif // NODO_H
