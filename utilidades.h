#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <iostream>
#include <cstdlib>
#include "andypolis.h"
#include "errores.h"
#include "herramientas.h"


using namespace std;

const string MSJ_INGRESO_EDIFICIO_CONSTRUIR = "Ingresa el nombre del edifico a construir:";
const string MSG_UBICACION_CONSTRUCCION_EDIFCIO = "Ingrese las coordenadas donde quiere construir el edificio:";
const string MSJ_INGRESO_EDIFICIO_MODIFICAR = "Ingresa el nombre del edifico a modificar:";
const string MSJ_UBICACION_MODIFICAR_EDIFCIO = "Ingrese la cantidad de material que quiere modificar del edificio:";
const string MSJ_UBICACION_DEMOLICION_EDIFCIO = "Ingrese la coordenadas del edificio que quiere demoler:";
const string MSJ_UBICACION_ATACAR_EDIFCIO = "Ingrese la coordenadas del edificio que quiere atacar:";
const string MSJ_UBICACION_REPARAR_EDIFCIO = "Ingrese la coordenadas del edificio que quiere reparar:";
const string MSJ_UBICACION_CONSULTAR_EDIFCIO =  "Ingrese las coordenadas que quiere consultar:";
const string MSJ_UBICACION_MOVERSE =   "Ingrese las coordenadas a las que desea movilizarse:";


// -------------------------------------------- FUNCIONES --------------------------------------------

// pre: Andypolis creado y jugador inicializado
// pos: Verifica si la cantidad de energia es correcta y procede al metodo para compara bombas
Estado_t comprar_bombas(Andypolis &andypolis, Jugador_t jugador);

// pre: Andypolis creado y jugador inicializado
// pos: Verifica si la cantidad de energia y las coordenadas ingresadaspor el usuario sena correctas es correcta
Estado_t construir_edificio_por_nombre(Andypolis &andypolis, Jugador_t jugador);


// pre: Andypolis creado y jugador inicializado
// pos: Verifica si la cantidad de energia y las coordenadas ingresadaspor el usuario sena correctas es correcta
Estado_t demoler_edificio_por_coordenada(Andypolis &andypolis, Jugador_t jugador);

// pre: Andypolis creado y jugador inicializado
// pos: Verifica si la cantidad de energia y las coordenadas ingresadaspor el usuario sena correctas es correcta
Estado_t atacar_edificio_por_coordenada(Andypolis &andypolis, Jugador_t jugador);

// pre: Andypolis creado y jugador inicializado
// pos: Verifica si la cantidad de energia y las coordenadas ingresadaspor el usuario sena correctas es correcta
Estado_t reparar_edificio_por_coordenada(Andypolis &andypolis, Jugador_t jugador);

// pre: -
// pos: funcion para el menu para pedirle al usuario datos para consultar un casillero de andypolis
Estado_t consultar_coordenada(const Andypolis &andypolis);

// pre: -
// pos: pide coordenadas para mover al jugador
Estado_t moverse_a_una_coord(Andypolis &andypolis, Jugador_t jugador);

// pre: Andypolis creado 
// pos: Verifica si la cantidad de energia, las coordenadas y los costos de construccion ingresadas por el usuario sean correctas es correcta
Estado_t modificar_edificio_por_nombre(Andypolis &andypolis);

// pre: -
// pos: Valida el valor numerico de los costos de los materiales para el edificios
Estado_t validar_cantidad_materiales(string piedra, string  madera, string metal);

// pre: -
// pos: Crea un archivo vacio
void crear_archivo_vacio(string ruta_archivo, fstream& archivo);

// pre: -
// pos: Verificad si el archivo esta vacio
bool archivo_esta_vacio(fstream& archivo);

// pre: - 
// pos: Consulta la posicion en la que se desea ubicar a los jugadores
Estado_t consultar_ubicacion_jugadroes(Andypolis& andypolis);



#endif // UTILIDADES_H