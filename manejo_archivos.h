#ifndef MANEJO_ARCHIVOS_H
#define MANEJO_ARCHIVOS_H

#include <iostream>
#include <fstream>
#include <string>
#include "andypolis.h"

using namespace std;

const string PATH_ENTRADA_MATERIALES = "Archivos/materiales.txt"; 
const string PATH_ENTRADA_EDIFICIOS = "Archivos/edificios.txt";
const string PATH_ENTRADA_UBICACIONES = "Archivos/ubicaciones.txt";
const string PATH_ENTRADA_MAPA = "Archivos/mapa.txt";

class Manejo_archivos{

private:
    // Atributos

    fstream archivo_materiales;
    fstream archivo_edificios;
    fstream archivo_ubicaciones;
    fstream archivo_mapa;

public:
    // Metodos

    // pre: -
    // pos: Construrctor de Manejo_archivos
    Manejo_archivos();

    // pre: -
    // pos: Destructor de Manejo_archivos
    ~Manejo_archivos();

    // pre: -
    // pos: Crea un archivo vacio y lo deja como modo lectura
    void crear_archivo_vacio(string ruta_archivo, fstream& archivo);

    // pre: -
    // pos: Chequea si el archivo ubicaciones esta vacio (True si esta vacio, False en caso contrario)
    bool archivo_ubicaciones_vacio();

    // pre: -
    // pos: Devuelve archivo_materiales
    fstream& obtener_archivo_materiales();

    // pre: -
    // pos: Devuelve archivo_edificios
    fstream& obtener_archivo_edificios();

    // pre: -
    // pos: Devuelve archivo_ubicaciones
    fstream& obtener_archivo_ubicaciones();

    // pre: -
    // pos: Devuelve archivo_mapa
    fstream& obtener_archivo_mapa();

    // pre: -
    // pos: Guarda los cambios cuando todavia no se inicio una nueva partida, en los archivos correspondientes 
    void guardar_cambios_partida_nueva(Andypolis& andypolis);

    // pre: No tiene que haber finalizado la partida (Ningun jugador gano)
    // pos: Guarda los cambios cuando todavia no finalizo el juego, en los archivos correspondientes
    void guardar_cambios(Andypolis& andypolis);

    // pre: Haber finalizado la partida (Alguno de los jugadores gano)
    // pos: Crea un archivo de ubicaciones vacio y pone los materiales en 0, dejando todo listo para una nueva partida
    void generar_archivos_para_nueva_partida(Andypolis& andypolis);


};


#endif // MANEJO_ACHIVOS_H