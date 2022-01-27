#ifndef ANDYPOLIS_H
#define ANDYPOLIS_H

#include <sstream>
#include <fstream>
#include <string>
#include <locale>
#include <iomanip>
#include <unistd.h>
#include "parser.h"
#include "inventario.h"
#include "jugador.h"
#include "mapa.h"
#include "datos_edificio.h"
#include "errores.h"
#include "herramientas.h"
#include "ABB.h"
#include "grafo.h"

using namespace std;

const int CANT_MAX_JUGADORES = 2;
const int POS_JUGADOR_UNO = 0;
const int POS_JUGADOR_DOS = 1;

const int MAX_EDIF_CONSTRUIBLES_INICIAL = 3;
const int AMPLIACION_EDIF_CONSTRUIBLES = 2;
const char DELIM_ESPACIO = ' ';

const string CONFIRMACION_AFIRMATIVA_CONSTRUCCION = "SI";
const string CONFIRMACION_NEGATIVA_CONSTRUCCION = "NO";

const int RAND_MAX_PIEDRA = 2;
const int RAND_MAX_MADERA = 3;
const int RAND_MAX_METAL = 4;
const int RAND_MAX_ANDYCOINS = 2;



class Andypolis{

private:
    // Atributos
    Mapa mapa;
    ABB<Datos_edificio,string> diccionario;
    Jugador jugadores[CANT_MAX_JUGADORES];


public:
    // Metodos

    // pre: archivos bien formados
    // pos: CONSTRUCTOR de andypolis a partir de todos los archivos
    Andypolis(fstream& archivo_edif, fstream& archivo_ubics, fstream& archivo_mapa, fstream& archivo_mats, bool partida_nueva);

    // pre: -
    // pos: DESTRUCTOR de andypolis
    ~Andypolis();

    // pre: -
    // pos: completa la informacion de los jugadores (excepto ubicacion, claro)
    void cargar_informacion_jugadores();

    // pre: Archivo bien formado
    // pos: Carga los inventarios de los jugadores
    void cargar_inventarios(fstream& archivo_mats);

    // pre: archivo bien formado
    // pos: carga el diccionario
    void cargar_diccionario(fstream& archivo_edif);

    // pre: Archivo bien formado
    // pos: carga las ubicaciones de materiales y los edificios de cada jugador
    Estado_t cargar_ubicaciones(fstream& archivo_ubics);

    // pre: Archivo bien formado
    // pos: carga los materiales en el mapa
    Estado_t cargar_materiales_mapa(fstream& archivo_ubics);

    // pre: Archivo bien formado
    // pos: carga los edificios de los jugadores (en caso de no estar "ubicaciones.txt" vacio)
    Estado_t cargar_edificios_jugador(fstream& archivo_ubics);

    // pre: coordenadas existentes en el mapa
    // pos: posiciona un jugador en el mapa y le asigna su ubicacion
    Estado_t posicionar_jugador(int coord_x, int coord_y, Jugador_t jugador);

    // pre: -
    // pos: Agrega un edificio a un jugador en particular
    void cargar_edificio_a_jugador(string nombre, char identificador, int coord_x, int coord_y, Jugador_t jugador);

    // pre: - 
    // pos: obtiene la cantidad de energia de un jugador en particular
    double obtener_energia_jugador(Jugador_t jugador);

    // pre: energia > 0
    // pos: agrega energia un jugador en particular
    void agregar_energia_jugador(Jugador_t jugador, double energia);

    // pre: -
    // pos: Compra bombas para un jugador en particular
    Estado_t comprar_bombas(Jugador_t jugador);

    // pre: -
    // pos: Busca un edificio en el diccionario, devuelve true si lo encuentra, false en caso contrario
    bool esta_edificio(string nombre);

    // pre: -
    // pos: construye un edificio
    Estado_t construir_edificio(string nombre, int coord_x, int coord_y, Jugador_t jugador);

    // pre: -
    // pos: modifica los datos de construccion de un edificio (cambio solo efectuado en el diccionario)
    void modificar_edificio(string nombre, int piedra_nuevo , int madera_nuevo, int metal_nuevo);

    // pre: -
    // pos: crea un string listo para usar con Parser (en este caso para el archivo ubicaciones.txt)
    string construir_string_edificio(string nombre, int coord_x, int coord_y);

    // pre: -
    // pos: Demuele un edificio de un jugador en particular
    Estado_t destruir_edificio_de_coord(int coord_x, int coord_y, Jugador_t jugador);

    // pre: -
    // pos: Ataca a un edificio del jugador contrario
    Estado_t atacar_edificio_de_coord(int coord_x, int coord_y, Jugador_t jugador);

    // pre: -
    // pos: Repara el edificio de un jugador en particular
    Estado_t reparar_edificio_de_coord(int coord_x, int coord_y, Jugador_t jugador);

    // pre: -
    // pos: LLUVIA DE RECURSOS
    Estado_t lluvia_de_recursos();

    // pre: -
    // pos: mueve al jugador a una coordenada
    Estado_t moverse_a_una_coord(int coord_x, int coord_y, Jugador_t jugador);

    // pre: -
    // pos: Realiza todo el camino encontrado en 'moverse_a_un_coord(...)' 
    void realizar_movimiento(int coord_inicial_x, int coord_inicial_y, Jugador_t jugador, Lista<Coordenadas*> &camino);

    // pre: -
    // pos: Imprime por pantalla el mapa con un delay para que parezca que el jugar va "caminando" por el mapa
    void animacion_movimiento();

    // pre: -
    // pos: Recolecta los recurso de los edificios del jugador
    void recolectar_recursos_jugador(Jugador_t jugador);

    // pre: -
    // pos: deposita los recursos de los edificios del jugador que termino su turno
    void depositar_recursos_jugador(Jugador_t jugador);

    // pre: -
    // pos: se fija si el jugador gano (claramente va a actualizar primero el estado de los objetivos)
    bool gano_el_jugador(Jugador_t jugador);

    // pre: -
    // pos: muestra el inventario del jugador pedido
    void mostrar_inventario(Jugador_t jugador);

    // pre: -
    // pos: muestra los edificios construidos del jugador
    void listar_edificios_construidos(Jugador_t jugador);

    // pre: -
    // pos: imprime por pantalla el diccionario con todos su datos
    void listar_edificios_diccionario();

    // pre: -
    // pos: muestra el mapa
    void mostrar_mapa(int pos_visual_x, int pos_visual_y);

    // pre: Objetivos del jugador han sido iniciliazados
    // pos: Se muestran por consola los objetivos del jugador junto con su progreso
    void mostrar_objetivos(Jugador_t jugador);

    // pre: -
    // pos: Consulta un casillero del mapa
    Estado_t consultar_casillero_de_mapa(int coord_x, int coord_y) const;


    // pre: -
    // pos: Verifica que el usuario (jugador) quiera construir el edificio
    Estado_t consultar_construccion_edificio();

    // pre: coordenadas existentes
    // pos: Devuelve true si el casillero del mapa es transitable, false en caso contrario
    bool es_transitable(int coord_x, int coord_y);

    // pre: coordenadas existentes
    // pos: Devuelve true si el casillero del mapa es transitable, false en caso contrario
    bool es_construible(int coord_x, int coord_y);

    // pre: jugador ubicado previamente
    // pos: Quita la posicion actual que tiene el jugador
    Estado_t eliminar_posicion_jugador( Jugador_t jugador);

    // pre: -
    // pos: Guarda todos los cambios realizados en andypolis en los archivos correspondientes (partida en curso)
    void guardar_andypolis(  fstream& archivo_salida_materiales, fstream& archivo_salida_ubicaciones );

    // pre: -
    // pos: Guarda la informacion que se cambio del diccionario en el archivo "edificios.txt"
    void guardar_andypolis_partida_nueva(  fstream& archivo_salida_edificios );

    // pre: -
    // pos: Guarda los materiales de los jugadores en el archivo correspondiente
    void guardar_materiales_en_archivo( fstream& archivo_salida_materiales );

    // pre: -
    // pos: Arma una string con el estilo de "materiales.txt"
    string armar_str_para_guardar_inventario(int pos);

    // pre: -
    // pre: Arma un string con el estilo de "materiales.txt" pero con las cantidades de los materiales en 0 para ambos jugadores
    string armar_str_para_guardar_inventario_nueva_partida(int pos);

    // pre: -
    // pos: Guarda las ubicaciones de los edificios (y de los mismos jugadores) en el archivo correspondiente
    void guardar_ubicaciones_en_archivo(fstream &archivo_salida);

    // pre: -
    // pos: Guarda los materiales con 0 de cantidad para cada uno de los jugadores
    void guardar_materiales_para_nueva_partida(fstream &archivo_materiales);

    // pre: -
    // pos: devuelve la cantidad de filas del mapa
    int obtener_filas_mapa();

    // pre: -
    // pos: devuelve la cantidad de columnas del mapa
    int obtener_columnas_mapa();



};


#endif // ANDYPOLIS_H