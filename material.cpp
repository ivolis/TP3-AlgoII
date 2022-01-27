#include <iostream>
#include "material.h"


// ------------------------------------------------------------------------------------------------------------


Material::Material(double cantidad){

    this -> cantidad = cantidad;

}


// ------------------------------------------------------------------------------------------------------------


Material::Material(){

    this -> cantidad = 0;

}


// ------------------------------------------------------------------------------------------------------------


char Material::obtener_identificador(){

    return identificador;

}


// ------------------------------------------------------------------------------------------------------------


double Material::obtener_cantidad(){

    return cantidad;

}


// ------------------------------------------------------------------------------------------------------------


void Material::sumar_cantidad(double cantidad){

    this -> cantidad += cantidad;

}


// ------------------------------------------------------------------------------------------------------------


void Material::restar_cantidad(double cantidad){

    this -> cantidad -= cantidad;

}
