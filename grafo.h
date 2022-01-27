#ifndef GRAFO_H
#define GRAFO_H

#include "mapa.h"
#include "vertice.h"
#include "lista.h"

const int POSICION_IMPOSIBLE = -1;

class Grafo{

private:
    // Atributos
    Jugador_t jugador;
    int** matriz_adyacencia;
    int** matriz_distancias;
    int** matriz_recorridos;
    Vertice*** grafo;
    int cantidad_vertices;
    int cantidad_filas;
    int cantidad_columnas;

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR del grafo de un jugador a partir del mapa
    Grafo (const Mapa &mapa, Jugador_t jugador); // pasar por const referencia?

    // pre: -
    // pos: DESTRUCTOR del grafo
    ~Grafo();

    // pre: -
    // pos: Pide memoria para los elementos de la matriz
    void crear_matriz_adyancencia();

    // pre: -
    // pos: Pide memoria para los elementos de la matriz
    void crear_matriz_distancias();

    // pre: -
    // pos: Pide memoria para los elementos de la matriz
    void crear_matriz_recorridos();

    /// pre: -
    // pos: Destruye la memeoria dinamica de los elementos de la matriz
    void destruir_matriz_adyancencia();

    /// pre: -
    // pos: Destruye la memeoria dinamica de los elementos de la matriz
    void destruir_matriz_distancias();

    /// pre: -
    // pos: Destruye la memeoria dinamica de los elementos de la matriz
    void destruir_matriz_recorridos();

    /// pre: -
    // pos: Destruye los vertices
    void destruir_vertices();

    // pre: -
    // pos: Inicializa valores de los atributos de la clase Grafo
    void asignar_datos_basicos(const Mapa &mapa, Jugador_t jugador);

    // pre: -
    // pos: Crea vertices con memotia dinamica
    void crear_vertices();

    // pre: -
    // pos: inicializa la matriz de adyacencia (para el grafo pedido en el TP)
    void inicializar_matriz_adyacencia();

    // pre: -
    // pos: inicializa la matriz de adyacencia (para el grafo pedido en el TP)
    void inicializar_matriz_recorridos();

    // pre: -
    // pos: inicializa la matriz de adistancias(para el grafo pedido en el TP)
    void inicializar_matriz_distancias();


    // pre: -
    // pos: carga la matriz de adyacencia
    void cargar_matriz_adyacencia();

    // pre: -
    // pos: conecta los vertices "de las esquinas del mapa"
    void conectar_esquinas(const Mapa &mapa);

    // pre: -
    // pos: conecta los vertices "de las orillas del mapa"
    void conectar_orillas(const Mapa &mapa);

    // pre: -
    // pos: conecta los vertices "del centro del mapa"
    void conectar_centros(const Mapa &mapa);

    // pre: -
    // pos: Actualiza los valores de las matrices que se utilizan en el grafo segun cambios en el juego
    void actualizar_grafo(const Mapa &mapa);

    // pre: -
    // pos: Se encarga de obtener el camino minimo del jugador y desplazarlo por el mapa juntando los materiales
    Estado_t procesamiento_del_movimiento(Coordenadas coordenadas_origen, int coord_destino_x, int coord_destino_y, double &energia_requerida, Lista<Coordenadas*> &camino);

    // pre: - 
    // post: Realiza el camino minimo modificando la matriz de distancia y recorridos utilizando la matriz de adyacencia
    void camino_minimo_floyd_warshall();

    // pre: - 
    // post: Imprime la matriz de adyacencia
    void imprimir_matriz_ady();

    // pre: - 
    // post: Imprime la matriz de recorridos
    void imprimir_matriz_recorridos();

    // pre: - 
    // post: Imprime la matriz de distancias
    void imprimir_matriz_distancias();

    // pre: - 
    // post: Imprime el camino minimo
    void imprimir_camino_minimo(int origen, int destino);

    /// pre: - 
    // post: Busca la coordanad de la matriz del grafo que coincide con el vertice utilizando busqueda binaria 
    Coordenadas encontrar_coordenadas_busqueda_binaria(Vertice *** matriz, int cant_filas, int cant_columnas, int clave);

    /// pre: - 
    // post: Busca la coordanad de la matriz del grafo que coincide con el vertice utilizando busqueda binaria 
    Coordenadas encontrar_columna_busqueda_binaria(Vertice *** matriz, int cant_filas, int cant_columnas, int clave, int fila_encontrada);
    

};





#endif // GRAFO_H