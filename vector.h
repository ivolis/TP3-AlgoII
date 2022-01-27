#ifndef VECTOR_H
#define VECTOR_H

const int VECTOR_TAMANIO_INICIAL = 2;


template <typename D>
class Vector{
    
private:
    // Atributos
    D** datos;
    int longitud;
    int capacidad;

    // Metodos privados

    // pre: nuevo_tam > 0
    // pos: Redimensiona el vector.
    void redimensionar(int nuevo_tam);

public:
    // Metodos

    // pre: -
    // pos: Construye un vector vacio de capacidad  = VECTOR_TAMANIO_INICIAL y datos vacios
    Vector();

    // pre: tam > 0
    // pos: Construye un vector de longitud tam y datos vacios
    Vector(int tam);

    // Constructor de copia
    Vector(const Vector <D> &);

    // pre: dato tiene que ser un Dato valido
    // pos: Inserta el dato, en la ultima posicion
    void insertar(D* dato);

    // pre: 0 <= pos < longitud, dato tiene que ser un Dato valido
    // pos: Inserta el dato, en la posicion "pos", la primera es la 0.
    void insertar_en_posicion( D* dato, int pos);

    // pre: 0 <= pos < longitud, y que el dato exista
    // pos: devuelve el dato que esta en pos
    D* consultar(int pos);

    // pre: 0 <= pos < longitud, y que el dato exista
    // pos: devuelve el dato que esta en pos
    D* consultar_const(int pos) const;

    // pre: -
    // pos: Devuelve la longitud del vector
    int obtener_longitud() const;

    // pre: -
    // pos: Libera recursos utilizados
    ~Vector();

};


// -----------------------------------------------------------------------------------------


template <typename D>
Vector<D>::Vector(){

    this -> longitud = 0;
    this -> capacidad = VECTOR_TAMANIO_INICIAL;
    datos = new D * [VECTOR_TAMANIO_INICIAL];

    for(int i = 0; i < longitud; ++i)
        datos[i] = NULL;
}


// -----------------------------------------------------------------------------------------


template <typename D>
Vector<D>::Vector(int tam){
    
    this -> longitud = 0;
    this -> capacidad = tam;
    datos = new D * [tam];

    for(int i = 0; i < tam; ++i)
        datos[i] = NULL;
}


// -----------------------------------------------------------------------------------------


template <typename D>
Vector<D>::Vector(const Vector <D> & vector)
{
	this ->longitud = vector.longitud;

	datos = new D*[vector.capacidad];

	for (int i=0; i < longitud ; i++)
	   this -> datos[i] = vector.datos[i];	
}


// -----------------------------------------------------------------------------------------


template <typename D>
Vector<D>::~Vector(){

    if(datos != NULL){
        for(int i = 0; i < longitud; ++i){

            if(datos[i] != NULL)
                delete datos[i];
        }

        delete[] datos;
    }
        
}


// -----------------------------------------------------------------------------------------


template <typename D>
void Vector<D>::redimensionar(int nuevo_tam){

    D** aux;
    aux = new D * [nuevo_tam];

    for(int i = 0; i < nuevo_tam ; ++i){
        if(i < capacidad )
            aux[i] = datos[i];
        else
            aux[i] = NULL;
    }

    delete[] datos;

    capacidad = nuevo_tam;

    datos = aux;
}


// -----------------------------------------------------------------------------------------


template <typename D>
void Vector<D>::insertar(D* dato){

    if(longitud == capacidad)
        this -> redimensionar(capacidad+1);
    
    datos[longitud] = dato;
    longitud++;
}


// -----------------------------------------------------------------------------------------


template <typename D>
void Vector<D>::insertar_en_posicion( D* dato, int pos){
    
    D* aux = new D;
    aux = dato;
    delete datos[pos];
    datos[pos] = aux;
}


// -----------------------------------------------------------------------------------------


template <typename D>
D* Vector<D>::consultar(int pos){

    return datos[pos];
}


// -----------------------------------------------------------------------------------------


template <typename D>
D* Vector<D>::consultar_const(int pos) const{
    return datos[pos];
}


// -----------------------------------------------------------------------------------------


template <typename D>
int Vector<D>::obtener_longitud() const{

    return this -> longitud;
}


#endif //VECTOR_H