#include "datos_edificio.h"


Datos_edificio::Datos_edificio(){

    this -> nombre = " ";
    this -> costo_piedra = 0;
    this -> costo_madera = 0;
    this -> costo_metal = 0;
    this -> maximos_permitidos = 0;
}


// ------------------------------------------------------------------------------------------------------------


Datos_edificio::Datos_edificio(string nombre, double costo_piedra, double costo_madera, double costo_metal, int maximos_permitidos){

    this -> nombre = nombre;
    this -> costo_piedra = costo_piedra;
    this -> costo_madera = costo_madera;
    this -> costo_metal = costo_metal;
    this -> maximos_permitidos = maximos_permitidos;
}


// ------------------------------------------------------------------------------------------------------------


string Datos_edificio::obtener_nombre_edificio(){

    return this -> nombre;
}


// ------------------------------------------------------------------------------------------------------------


double Datos_edificio::obtener_costo_piedra(){

    return this -> costo_piedra;
}


// ------------------------------------------------------------------------------------------------------------


double Datos_edificio::obtener_costo_madera(){

    return this -> costo_madera;
}


// ------------------------------------------------------------------------------------------------------------


double Datos_edificio::obtener_costo_metal(){

    return this -> costo_metal;
}

// ------------------------------------------------------------------------------------------------------------


double Datos_edificio::modificar_costo_piedra( int cantidad){

    return this -> costo_piedra = cantidad;
}


// ------------------------------------------------------------------------------------------------------------


double Datos_edificio::modificar_costo_madera(int cantidad){

    return this -> costo_madera = cantidad;
}


// ------------------------------------------------------------------------------------------------------------


double Datos_edificio::modificar_costo_metal(int cantidad){

    return this -> costo_metal = cantidad;
}


// ------------------------------------------------------------------------------------------------------------


int Datos_edificio::obtener_maximos_permitidos(){

    return this -> maximos_permitidos;
}


// ------------------------------------------------------------------------------------------------------------


void Datos_edificio::mostrar_informacion(){

    cout
        << left
        << setw(30)
        << this -> nombre
        << left
        << setw(24)
        << this -> costo_piedra
        << left
        << setw(24)
        << this -> costo_madera
        << left
        << setw(24)
        << this -> costo_metal
        << left
        << setw(24)
        << this -> maximos_permitidos
        << endl;
}


// ------------------------------------------------------------------------------------------------------------


void Datos_edificio::guardar_informacion(fstream& archivo){

    archivo 
            << this -> nombre << ' '
            << this -> costo_piedra << ' ' 
            << this -> costo_madera << ' ' 
            << this -> costo_metal << ' ' 
            << this -> maximos_permitidos 
            << endl;
}