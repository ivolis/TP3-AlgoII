#ifndef DATOS_EDIFICIO_H
#define DATOS_EDIFICIO_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;


class Datos_edificio {

    
private:
    string nombre;
    double costo_piedra;
    double costo_madera;
    double costo_metal;
    int maximos_permitidos;
   

public:
    // Metodos

    // pre: - 
    // pos: Constructor clase Datos_Edificio por defecto
    Datos_edificio();

    // pre: -
    // pos: Constructor clase Datos_Edificio por parametro
    Datos_edificio(string nombre, double costo_piedra, double costo_madera, double costo_metal, int maximos_permitidos);

    // pre: - 
    // pos: Destructor clase Datos_Edificio
    ~Datos_edificio(){};

    // pre: Objeto previamente creado
    // pos: Devuelve string nombre del edificio
    string obtener_nombre_edificio();

    // pre: Objeto previamente creado
    // pos: Devuelve el costo de piedra del edificio
    double obtener_costo_piedra();

    // pre: Objeto previamente creado
    // pos: Devuelve el costo de madera del edificio
    double obtener_costo_madera();

    // pre: Objeto previamente creado
    // pos: Devuelve el costo de metal del edificio
    double obtener_costo_metal();

    // pre: Objeto previamente creado
    // pos: Devuelve cantidad maxima de edificios edificio
    int obtener_maximos_permitidos();

    // pre: Objeto previamente creado
    // pos: Modifica el costo de piedra del edificio segun la cantidad ingresada
    double modificar_costo_piedra( int cantidad);

    // pre: Objeto previamente creado
    // pos: Modifica el costo de madera del edificio segun la cantidad ingresada
    double modificar_costo_madera(int cantidad);

    // pre: Objeto previamente creado
    // pos: Modifica el costo de metal del edificio segun la cantidad ingresada
    double modificar_costo_metal(int cantidad);

    // pre: Objeto previamente creado
    // pos: Imprime por consola los atributos del objeto
    void mostrar_informacion();

    // pre: Objeto previamente creado
    // pos: Imprime en un archivo los atributos del objeto
    void guardar_informacion(fstream& archivo);
    

};

#endif // DATOS_EDIFICIO_H