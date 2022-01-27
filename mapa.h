#ifndef MAPA_H
#define MAPA_H

#include "casillero.h"
#include "superficie.h"
#include "parser.h"
#include "lista.h"
#include "herramientas.h"
#include "Casilleros/casillero_construible.h"
#include "Casilleros/casillero_inaccesible.h"
#include "Casilleros/casillero_transitable.h"
#include "gotoxy.h"


class Mapa{

private:
    // Atributos
    Casillero*** mapa;
    int cantidad_filas;
    int cantidad_columnas;
    Lista<Coordenadas*> casilleros_transitables_disponibles; //CUADNO EL JUGADOR PASE POR UNA DE ESAS COORD TIENE QUE LLEVARSE EL MATERIAL

public:
    // Metodos

    // pre: archivo debe ser valido
    // pos: CONSTRUCTOR del mapa
    Mapa(fstream& archivo_mapa);

    // pre: archivo debe ser valido
    // pos: CONSTRUCTOR del mapa default
    Mapa();

    // pre: -
    // pos: DESCTRUCTOR del mapa
    ~Mapa();

    // pre: -
    // pos: obtiene la cantidad de filas que tiene el mapa
    int obtener_filas() const;

    // pre: -
    // pos: obtiene la cantidad de columnas que tiene el mapa
    int obtener_columnas() const;

    // pre: las coordenadas deben ser de un casillero que esta ocupado (es decir, validar antes en funcionas mas externas esto)
    // pos: obtiene lo que haya en el casillero
    string obtener_nombre_objeto_de_casillero_ocupado(int coord_x, int coord_y);

    // pre: el casillero debe ser valido
    // pos: devuelve el peso (costo de energia) para el jugador que pase por dicho casillero debido a la superf que se halle ahi
    int obtener_peso_casillero(int coord_x, int coord_y, Jugador_t jugador) const;

    // pre: coordenada valida
    // pos: devuelve el indice de la lista de casilleros transitables disponibles de una coordenada pedida
    int obtener_indice_casillero_transitable(int coord_x, int coord_y);

    // pre: -
    // pos: Devuelve la ubicacion de un casillero transitable aleatorio de la lista
    Coordenadas obtener_coordenadas_casillero_transitable_aleatorio();

    // pre: coordenadas validas (depende de mapa.txt)
    // pos: devuelve si un casillero particular del mapa es transitable
    bool se_puede_transitar(int coord_x, int coord_y);

    // pre: coordenadas validas (depende de mapa.txt)
    // pos: devuelve si un casillero particular del mapa es construible
    bool se_puede_construir(int coord_x, int coord_y);

    // pre: coordenadas validas (depende de mapa.txt)
    // pos: devuelve si un casillero particular del mapa es accesible
    bool se_puede_acceder(int coord_x, int coord_y);

    // pre: coordenadas validas (depende de mapa.txt)
    // pos: devuelve si un casillero particular del mapa esta ocupado
    bool casillero_esta_ocupado(int coord_x, int coord_y);

    // pre: coordenadas validas
    // pos: "construye" un edificio en una coordenada dada (y devuelve un error en caso de que sea no sea construible o ya este ocupado)
    Estado_t asignar_edificio_en_coord(Edificio* edificio, int coord_x, int coord_y);

    // pre: coordenadas validas
    // pos: "destruye" el edificio en una coordenada dada (y devuelve un error en caso de que sea no sea construible o no haya nada)
    Estado_t destruir_edificio_en_coord(int coord_x, int coord_y);

    // pre: coordenadas validas
    // pos: posiciona al jugador en el casillero
    Estado_t posicionar_jugador(int coord_x, int coord_y, Jugador_t jugador);

    // pre: coordenadas validas
    // pos: consulta un casillero del mapa en particular
    Estado_t consultar_casillero(int coord_x, int coord_y) const;

    // pre: -
    // pos: muestra el mapa con sus edificios y materiales a partir de unas coordenadas para la consola (visual)
    void mostrar_mapa(int pos_visual_x, int pos_visual_y);

    // pre: -
    // pos: imprime la leyenda del mapa (las referencias de que es cada cosa)
    void imprimir_leyenda_mapa();

    // pre: -
    // pos: devuelve la cantidad de casilleros transitables desocupados/disponibles/libres
    int cantidad_casilleros_transitables_disponibles();

    // pre: -
    // pos: agrega un material a una coordenada particular
    Estado_t agregar_material_en_coordenadas(Material* material, int coord_x, int coord_y);

    // pre: La coordenada debe tener un material!
    // pos: quita el material de un casillero
    void quitar_material_en_coordenadas(int coord_x, int coord_y);

    // pre: -
    // pos: agrega un material en un casillero transitable DISPONIBLE ALEATORIO (y deja de estar disponible, claro)
    void agregar_material_en_coordenada_transitable_aleatoria(Material* material);

    // pre: antes de llamarla chequear que el casillero tenga un edificio
    // pos: devuelve el identificador de un casillero que tiene un edificio con la capacidad de brindar materiales
    char obtener_identificador_recurso_de_casillero(int coord_x, int coord_y);

    // pre: antes de llamarla chequear que el casillero tenga un edificio
    // pos: devuelve la cantidad de material brindado de un casillero que tiene un edificio con la capacidad de brindar materiales
    double recolectar_recursos_casillero( int coord_x, int coord_y);

    // pre: coordenadas validas
    // pos: "deposita" un recurso en el deposito del edificio del casillero 
    void depositar_recurso_casillero(int coord_x, int coord_y);

    // pre: -
    // pos: Verifica que se cumplan las condiciones para construir 
    Estado_t verificar_coordenadas_construccion(int coord_x, int coord_y);

    // pre: -
    // pos: Verifica que se cumplan las condiciones para demoler
    Estado_t verificar_coordenadas_demolicion(int coord_x, int coord_y, Jugador_t jugador);

    // pre: -
    // pos: Verifica que se cumplan las condiciones para atacar a un edificio
    Estado_t verificar_coordenadas_ataque(int coord_x, int coord_y, Jugador_t jugador);

    // pre: -
    // pos: Verifica que se cumplan las condiciones para reparar un edificio
    Estado_t verificar_coordenadas_reparacion(int coord_x, int coord_y, Jugador_t jugador);

    // pre: coordenadas validas (que haya un edificio)
    // pos: Devuelve de que jugador es el edificio
    Jugador_t obtener_creador_edificio(int coord_x, int coord_y);

    // pre: coordenadas validas
    // pos: Elimina al jugador del mapa
    Estado_t eliminar_posicion_jugador(int coord_x, int coord_y);

    // pre: -
    // pos: Guarda los materiales que estan en el mapa (No son de ningun jugador!)
    void guardar_materiales_en_achivo( fstream & archivo_salida);


    
};





#endif // MAPA_H