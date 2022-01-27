#ifndef ERRORES_H
#define ERRORES_H

#include <string>
#include "formatos.h"

using namespace std;

// SEGURO HAYA QUE CAMBIAR ALGUNOS ERRORES
const string STR_OK = "Ok";
const string STR_ERROR_CONSTRUCCION_CANCELADA = "¡La construccion ha sido cancelda!";
const string STR_ERROR_JUGADOR_ELEGIDO_INCORRECTO = "¡El numero ingresado no corresponde a un jugador!";
const string STR_ERROR_MODIFICAR_OBELISICO = "¡No se puede modificar el Obelisco!";
const string STR_ERROR_CANTIDAD_MATERIALES_INVALIDOS = "¡La cantidad ingresada de algun material es incorrecta!";
const string STR_ERROR_EDIFICIO_NO_REPARABLE = "¡Este edificio no puede ser reparado!";
const string STR_ERROR_EDIFICIO_AJENO = "¡Este edificio no es de tu propiedad!";
const string STR_ERROR_EDIFICIO_PROPIO = "¡Este edificio es de tu propiedad!";
const string STR_ERROR_BOMBAS_INSUFICIENTES = "¡No tienes bombas para atacar a tu oponente!";
const string STR_ERROR_ENTRADA_INVALIDA = "¡El dato ingresado es invalido!";
const string STR_ERROR_PUNTERO_NULO = "Error interno del sistema";
const string STR_ERROR_MATERIAL_INVALIDO = "¡Ese material no es valido!";
const string STR_ERROR_EDIFICIO_INEXISTENTE = "¡Este edificio no existe!";
const string STR_ERROR_NO_HAY_CONSTRUIDOS = "¡No hay mas edificios de este tipo, no podes destruir mas!";
const string STR_ERROR_MAXIMO_EDIFICIOS_ALCANZADO = "¡Alcanzaste el maximo de edificios posible!";
const string STR_ERROR_MATERIALES_INSUFICIENTES = "¡No tenes suficiente materiales para construir!";
const string STR_ERROR_NUMERO_OPCION_INVALIDA = "¡Ese numero está fuera de rango!";
const string STR_ERROR_CODIGO_INEXISTENTE = "¡Ese codigo no existe!";
const string STR_ERROR_POSICION_INEXISTENTE = "¡La posicion ingresada no existe en el mapa!";
const string STR_ERROR_CASILLERO_NO_CONSTRUIBLE = "¡Este casillero no es construible!";
const string STR_ERROR_CASILLERO_OCUPADO = "¡El casillero esta ocupado!";
const string STR_ERROR_CASILLERO_NO_TRANSITABLE = "¡El casillero no es del tipo transitable!";
const string STR_ERROR_PAR_COORDENADAS_INVALIDAS = "¡Alguna de esas coordenadas no es un numero!";
const string STR_ERROR_MATERIALES_INVALIDOS = "¡Alguno de esas materiales no es un numero!";
const string STR_ERROR_CASILLERO_VACIO = "¡Este casillero esta vacio!";
const string STR_ERROR_RECOLECCION_MATERIALES = "¡No hay edificios de los cuales recolectar materiales!";
const string STR_ERROR_ANDYCOINS_INSUFICIENTES = "¡No tenes suficientes andycoins para comprar!";
const string STR_ERROR_ENERGIA_INSUFICIENTE = "¡No tenes suficiente energia para realizar esta acción!";
const string STR_ERROR_MOVIMIENTO_A_OCUPADO = "¡No es posible moverse a este casillero, hay un edificio o un jugador!";
const string STR_ERROR_MISMA_UBICACION = "¡El jugador ya se encuentra en esa posicion!";
const string STR_ERROR_CASILLERO_CONSTRUIBLE = "¡Este casillero es construible!";

const string errores[] = {
	STR_OK,
	STR_ERROR_ENTRADA_INVALIDA,
	STR_ERROR_PUNTERO_NULO,
	STR_ERROR_MATERIAL_INVALIDO,
	STR_ERROR_EDIFICIO_INEXISTENTE,
	STR_ERROR_NO_HAY_CONSTRUIDOS,
	STR_ERROR_MAXIMO_EDIFICIOS_ALCANZADO,
	STR_ERROR_MATERIALES_INSUFICIENTES,
	STR_ERROR_NUMERO_OPCION_INVALIDA,
	STR_ERROR_CODIGO_INEXISTENTE,
	STR_ERROR_POSICION_INEXISTENTE,
	STR_ERROR_CASILLERO_NO_CONSTRUIBLE,
	STR_ERROR_CASILLERO_OCUPADO,
	STR_ERROR_CASILLERO_NO_TRANSITABLE,
	STR_ERROR_PAR_COORDENADAS_INVALIDAS,
	STR_ERROR_CASILLERO_VACIO,
    STR_ERROR_RECOLECCION_MATERIALES,
	STR_ERROR_ANDYCOINS_INSUFICIENTES,
	STR_ERROR_ENERGIA_INSUFICIENTE,
	STR_ERROR_EDIFICIO_AJENO,
	STR_ERROR_EDIFICIO_PROPIO,
	STR_ERROR_BOMBAS_INSUFICIENTES,
	STR_ERROR_EDIFICIO_NO_REPARABLE,
	STR_ERROR_MATERIALES_INVALIDOS,
	STR_ERROR_CANTIDAD_MATERIALES_INVALIDOS,
	STR_ERROR_MODIFICAR_OBELISICO,
	STR_ERROR_JUGADOR_ELEGIDO_INCORRECTO,
	STR_ERROR_CONSTRUCCION_CANCELADA,
	STR_ERROR_MOVIMIENTO_A_OCUPADO,
	STR_ERROR_MISMA_UBICACION,
	STR_ERROR_CASILLERO_CONSTRUIBLE
	
};

enum Estado_t {
	OK = 0,
	ERROR_ENTRADA_INVALIDA = 1, 
	ERROR_PUNTERO_NULO = 2,
	ERROR_MATERIAL_INVALIDO = 3,
	ERROR_EDIFICIO_INEXISTENTE = 4,
	ERROR_NO_HAY_CONSTRUIDOS = 5,
	ERROR_MAXIMO_EDIFICIOS_ALCANZADO = 6,
	ERROR_MATERIALES_INSUFICIENTES = 7,
	ERROR_NUMERO_OPCION_INVALIDA = 8,
	ERROR_CODIGO_INEXISTENTE = 9,
	ERROR_POSICION_INEXISTENTE = 10,
	ERROR_CASILLERO_NO_CONSTRUIBLE = 11,
	ERROR_CASILLERO_OCUPADO = 12,
	ERROR_CASILLERO_NO_TRANSITABLE = 13,
	ERROR_PAR_COORDENADAS_INVALIDAS = 14,
    ERROR_CASILLERO_VACIO = 15,
    ERROR_RECOLECCION_MATERIALES = 16,
	ERROR_ANDYCOINS_INSUFICIENTES = 17,
	ERROR_ENERGIA_INSUFICIENTE = 18,
	ERROR_EDIFICIO_AJENO = 19,
	ERROR_EDIFICIO_PROPIO = 20,
	ERROR_BOMBAS_INSUFICIENTES = 21,
	ERROR_EDIFICIO_NO_REPARABLE = 22,
	ERROR_MATERIALES_INVALIDOS = 23,
	ERROR_CANTIDAD_MATERIALES_INVALIDOS = 24,
	ERROR_MODIFICAR_OBELISICO = 25,
	ERROR_JUGADOR_ELEGIDO_INCORRECTO = 26,
	ERROR_CONSTRUCCION_CANCELADA =27,
	ERROR_MOVIMIENTO_A_OCUPADO = 28,
	ERROR_MISMA_UBICACION = 29,
	ERROR_CASILLERO_CONSTRUIBLE = 30,
	ADVERTENCIA_LLUVIA_RECURSOS = 100,
	ESTADO_JUGADOR_GANADOR = 200,
	PARTIDA_NUEVA_NO_INICIALIZADA = 300};


//####################################################### FUNCIONES #################################################################


// pre: -
// pos: imprime el error en funcion del tipo de Estado_t que ingresan
void imprimir_error(Estado_t st);


#endif //ERRORES_H
