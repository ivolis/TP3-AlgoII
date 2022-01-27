#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <ctime>
#include "menu.h"
#include "utilidades.h"

using namespace std;

enum Opciones_menu{
	CONSTRUIR_EDIFICIO_POR_NOMBRE = 1,
	LISTAR_EDIFICIOS_CONSTRUIDOS = 2,
	DEMOLER_EDIFICIO_POR_COORD = 3,
	ATACAR_EDIFICIO_POR_COORD = 4,
	REPARAR_EDIFICIO_POR_COORD = 5,
	COMPRAR_BOMBAS = 6,
	CONSULTAR_COORDENADA = 7,
	MOSTRAR_INVENTARIO = 8,
	MOSTRAR_OBJETIVOS = 9,
	RECOLETAR_RECURSOS_PRODUCIDOS = 10,
	MOVERSE_A_UNA_COORD = 11,
	FINALIZAR_TURNO = 12,
	GUARDAR_SALIR = 13,
};

enum Opciones_menu_partida_nueva_t{
	MODIFICAR_EDIFICIO_POR_NOMBRE_PARTIDA_NUEVA = 1,
	LISTAR_TODOS_LOS_EDIFICIOS_PARTIDA_NUEVA = 2,
	MOSTRAR_MAPA_PARTIDA_NUEVA = 3,
	COMENZAR_PARTIDA_PARTIDA_NUEVA = 4,
	GUARDAR_SALIR_PARTIDA_NUEVA = 5,
};

class Juego{

private:
    // Atributos

    bool partida_nueva;
    bool jugador_ganador;
    int turno;
    Menu menu;
    Manejo_archivos archivos;

public:
    // Metodos

    // pre:
    // pos:
    Juego();

    // pre:
    // pos:
    ~Juego(){};

    // pre:
    // pos:
    void jugar();

    // pre:
    // pos:
    Estado_t juego_nuevo(Andypolis& andypolis, int& opcion);

    // pre:
    // pos:
    Estado_t procesar_juego(Andypolis& andypolis);

    // pre: -
    // pos: asigna quien va a ir primero (jugador A) y quien ira segundo (jugador B) en el primer par de turnos
    void sortear_jugadores(Jugador_t &jugador_A, Jugador_t &jugador_B);

    // pre: ingreso_menu() ya valida el puntero nulo
    // pos: realiza la opcion del menu que el usuario elija
    Estado_t procesar_opcion(Andypolis &andypolis, Jugador_t jugador, int& opcion);

};


#endif // JUEGO_H