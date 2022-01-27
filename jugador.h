#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <algorithm>
#include <random>
#include "edificio.h"
#include "herramientas.h"
#include "inventario.h"
#include "grafo.h"
#include "objetivo.h"
#include "vector.h"
#include "lista.h"
#include "ABB.h"

#include "edificio_jugador.h"
#include "Objetivos/armado.h"
#include "Objetivos/bombardero.h"
#include "Objetivos/cansado.h"
#include "Objetivos/comprar_andypolis.h"
#include "Objetivos/constructor.h"
#include "Objetivos/edad_piedra.h"
#include "Objetivos/energetico.h"
#include "Objetivos/extremista.h"
#include "Objetivos/letrado.h"
#include "Objetivos/minero.h"
#include "Objetivos/alto_nubes.h"


using namespace std;


const char IDENTIFICADOR_JUGADOR_UNO = 'J';
const char IDENTIFICADOR_JUGADOR_DOS = 'U';
const int CANT_OBJETIVOS_SORTEADOS = 3;
const int CANT_OBJETIVOS_SECUNDARIOS = 10;
const int CANT_MAX_ENERGIA = 100;
const double CANTIDAD_ENERGIA_NECESARIA_P_CONSTRUIR = 15;
const int  CANT_OBJETIVOS_SECUNDARIOS_PARA_GANAR = 2;

const string MSJ_RECOLECCION_EXITOSA = "¡Recolección exitosa!";
const string MSJ_ACTUALIZACION_INVENTARIO =  "Tu inventario ahora quedo de la siguiente manera:";
const string MSG_CANTIDAD_BOMBAS_A_COMPRAR = "Ingresa la cantidad de bombas que desea comprar:";

class Jugador{
private:
        // Atributos
        char identificador;
        Jugador_t jugador;
        Coordenadas ubicacion;
        Lista<Edificio_jugador*> mis_edificios; 

        Grafo* grafo;
        Inventario inventario;
        Objetivo* objetivo_principal;
        Vector<Objetivo> objetivos_secundarios;
        double energia;

public:
        // Metodos

        // pre: -
        // pos: CONSTRUCTOR por default de un juegador
        Jugador();

        // pre: -
        // pos: DESTRUCTOR del jugador
        ~Jugador();

        // pre: -
        // pos: agrega energia al jugador
        void agregar_energia(double energia);

        // pre: que una funciona mas externa chequee que no quede negativa la energia
        // pos: resta energia
        void restar_energia(double energia);

        // pre: -
        // pos: asigna el identificador al jugador (con el que será visto en el mapa)
        void asignar_identificador(char identif);

        // pre: -
        // pos: asigna que jugador es (jugador 1 o 2)
        void asignar_numero_jugador(Jugador_t jugador);

        // pre: las coordenadas deben estar dentro del mapa (chequear en funcion superior)
        // pos: asigna la ubicacion en el mapa del jugador
        void asignar_ubicacion_jugador(int coord_x, int coord_y);

        // pre: -
        // pos: crea el grafo correspondiente al jugador
        void crear_grafo(const Mapa &mapa);

        // pre: -
        // pos: actualiza el grafo por si hubieron cambios
        void actualizar_grafo(const Mapa &mapa);

        // pre: -
        // pos: devuelve la cantidad de energia que tiene el jugador
        double obtener_energia();

        // pre: -
        // pos: devuelve la ubicacion que tiene el jugador
        Coordenadas obtener_ubicacion();

        // pre: -
        // pos: devuelve la cantidad de andycoins que tiene el jugador
        double obtener_cantidad_andycoins();

        // pre: edificio previamente cargado, valores de parametros positivos
        // pos: Devuelve el valor de la vida del edificio en posicion edificio en mis edificio y de la posicion orden edificio en vida
        int obtener_vida_edificio( int posicion_edificio, int orden_edificio);


        // pre: edificio previamente cargado, valores de parametros positivos
        // pos: Suma el valor de la vida del edificio en posicion edificio en mis edificio y de la posicion orden edificio en vida
        void sumar_vida_edificio( int posicion_edificio, int orden_edificio);

        // pre: -
        // pos: devuelve la cantidad de bombas que tiene el jugador
        double obtener_cantidad_bombas();

        // pre: -
        // pos: Creo los objetivos secundarios en el vector de objetivos_secundarios
        void sortear_objetivos_secundarios();

        // pre: -
        // pos: agrega un tipo de material al inventario del jugador
        void agregar_material_al_inventario(Material* material);

        // pre: -
        // pos: compra bombas para el jugador (y devuelve un error si no tiene las andycoins necesarias)
        Estado_t comprar_bombas();

        // pre: Todos los parametros han sido previamente validados
        // pos: Se crea un edificio jugador y se lo agrega en mis edifcios con los valores ingresados por paramtros
        void agregar_edificio(string nombre, char identificador, int vida, int coord_x, int coord_y);

        // pre: Los edificios del jugador han sido previemnte creados
        // pos: Deveulve la posicion en mis edifciios del edificio identificado con el char
        int buscar_edificio_por_identificador(char identificador);

        // pre: Lista de edificios cargado desde el archivo
        // pos: Posicion del edificio en la lista.
        int buscar_edificio_por_nombre(string nombre);

        // pre: los parametros han sido validados
        // pos: verifica que el jugador tiene los elementos necesarios para construir el edificio
        Estado_t verificar_condiciones_construccion(string nombre, const ABB<Datos_edificio,string> &diccionario);

        // pre: los parametros han sido validados
        // pos: verifica que el jugador tiene los elementos necesarios para reparacion el edificio
        Estado_t verificar_condiciones_reparacion(string nombre, const ABB<Datos_edificio,string> &diccionario);

        // pre: los parametros han sido validados
        // pos: Resta los materiales del inventario del jugador por construccion
        void restar_materiales_construccion(string nombre, const ABB<Datos_edificio,string> &diccionario);

        // pre: los parametros han sido validados
        // pos: Resta los materiales del inventario del jugador por reparacion
        void restar_materiales_reparacion(string nombre, const ABB<Datos_edificio,string> &diccionario);

        // pre: parametros validados
        // pos: suma la cantidad de material identificado por el identificador en el inventario
        void sumar_cantidad_material_inventario(char identificador, double cantidad);
        
        // pre: parametros validados
        // pos: resta la vida del edificio ubicado en posicion edificio de mis edificio en la posicion orden edificio de vida
        void restar_vida_edificio(int posicion_edificio, int orden_edificio);

        // pre: -
        // pos: resta la cantida de bombas del jugador
        void restar_bombas();

        // pre: -
        // pos: aumenta la cantidad de bombas del jugador
        void aumentar_bombas_usadas();

        // pre: -
        // pos: recolecta el recursos que se ubica en la posicion segun el edificio
        void recolectar_recursos(Mapa &mapa);

        /// pre: -
        // pos: deposita el recursos que se ubica en la posicion segun el edificio
        void depositar_recursos(Mapa &mapa);

        // pre: -
        // pos: utiliza el camino generado por caminos minimos del grafo para moverse por el mapa reci=olectando materiales
        Estado_t moverse_a_una_coord(int coord_x, int coord_y, Lista<Coordenadas*> &camino);

        // pre: -
        // pos: actualiza lel estado de los objetivos verificando si se cumplen las condiciones
        void actualizar_estado_objetivos( int cant_maxima_escuelas);

        // pre:
        // pos: actualiza el estado de los objs del jugador y devuelve true si el jugador gano el juevo ya sea por objetivo principal o objetivos secundarios
        bool gane_el_juego( int cant_maxima_escuelas);

        // pre:
        // pos: devuelve verdadero si el jugador gano por objetivo principal (construir el obelisco)
        bool victoria_por_objetivo_principal();

        //pre: -
        //post: devuelve verdadero si el jugador gano por objetivos secundarios (cumplio 2 de los 3 asignados)
        bool victoria_por_objetivos_secundarios();

        // pre: -
        // pos: muestra el inventario del jugador
        void mostrar_inventario();

        // pre: -
        // pos: muestra los edificios construidos por el jugador (FALTA RESTANTES HASTA MAXIMO - NECESITO DIC catalogo :( -))
        void listar_edificios_construidos();

        // pre: -
        // pos: Demuele el edificio de mis edifcios, del mapa y retorna al jugador un cuarto de los materiales de contruccion
        void demoler_edificio(string nombre_edificio, const ABB<Datos_edificio,string> &diccionario, int coord_x, int coord_y);

        // pre: -
        // pos: destruye el edficio de mis edificios y del mapa
        void destruir_edificio(string nombre_edificio, const ABB<Datos_edificio,string> &diccionario, int coord_x, int coord_y);
        
        // pre: El vector de objetivos_secundarios esta completo
        // pos: Se imprimen todos los objetivos secundarios y el objetivo principal por consola
        void mostrar_objetivos( int cant_maxima_escuelas);

        // pre:
        // pos: Devuelve la posicion en la lista de coordenadas
        int buscar_posicion_coordenadas( int posicion_edificio, int coord_x, int coord_y);

        // pre: -
        // pos: inidica si el edificio puede ser reparado segun la cantidad de vida que tenga 
        bool puede_repararse_edificio( int posicion, int orden_edificio);

        // pre: -
        // pos: guarda la ubicacion del jugador en el archivo
        void guardar_ubicacion_en_archivo( fstream &archivo_salida, Jugador_t jugador);

        // pre: -
        // pos: guarda los edificios del jugador en el archivo
        void guardar_mis_edificios_en_archivo(fstream &archivo_salida);

        // pre: -
        // pos: obtiene el  nombre material de la posicion en el inventario
        string obtener_str_nombre_material(int pos);
        // pre: -
        // pos: obtiene la cantidad material de la posicion en el inventario
        string obtener_str_cantidad_material(int pos);
        
        // pre: -
        // pos: obtiene la cantidad de  materiales en el inventario
        int obtener_cantidad_de_materiales_en_inventario();

        




private:
        //pre: opcion entre 0 y 8
        //pos: devuelve uno de los objetivos que salio en el "sorteo"
        Objetivo* generar_objetivos_secundarios(int opcion_objetivo);

};

#endif