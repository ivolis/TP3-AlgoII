#ifndef EDIFICIO_JUGADOR_H
#define EDIFICIO_JUGADOR_H

#include <string>
#include <sstream>
#include "lista.h"
#include "herramientas.h"
#include "errores.h"
#include "formatos.h"


using namespace std;

class Edificio_jugador{

private:
    // Atributos
    string nombre;
    char identificador;
    int cantidad_construidos;
    Lista<Coordenadas*> ubicaciones;
    Lista<int> vida;

public:
    // Metodos

    // pre: -
    // pos: Constructor por default
    Edificio_jugador();

    // pre: -
    // pos: Constructor por parametros
    Edificio_jugador(string nombre, char identificador );

    // pre: -
    // pos: Destruye los recursos utilizados
    ~Edificio_jugador();

    // pre: Objeto previamente creado
    // pos: Devuelve string nombre del edificio
    string obtener_nombre() const;

    // pre: Objeto previamente creado
    // pos: Devuelve el identificador del edificio
    char obtener_identificador();

    // pre: Objeto previamente creado
    // pos: Devuelve la cantidad de edificios cosntruidos
    int obtener_cantidad_construidos() const;

    // pre: Objeto previamente creado
    // pos: Devuelve ubicaciones construidas
    string obtener_ubicaciones_construidas_str() const;

    // pre:
    // pos: devuelve la coordenada x de la ubicacion del edificio en la posicion pos de la lista
    int obtener_coord_x_ubicacion(int pos);

    // pre:
    // pos: devuelve la coordenada x de la ubicacion del edificio en la posicion pos de la lista
    int obtener_coord_y_ubicacion(int pos);

    // pre: Objeto previamente creado
    // pos: Devuelve la vida de los edificios construidos
    string obtener_vida_edificios_str() const;

    // pre: Objeto previamente creado
    // pos: Devuelve la vida del edficio segun la posicion ingresada
    int obtener_vida( int posicion ) const;


    // pre:
    // pos: si no tiene 100 de vida es porque necesita repararse
    bool puede_repararse( int posicion );

    // pre: Objeto previamente creado
    // pos: Agrega una coordenada a la lista con los valores pasados por parametros
    void agregar_coordenadas_a_lista(int coord_x, int coord_y);

    /// pre: Objeto previamente creado
    // pos: Agrage la cantidad de vida al edificio
    void agregar_vida(int cantidad);

    // pre:
    // pos: Devuelve la posicion en la lista de coordenadas
    int buscar_coordenadas_en_lista(int coord_x, int coord_y);

    // pre: tiene que ser una coorenada existente (chequear en funciones mas externas)
    // pos: 
    void quitar_coordenadas_a_lista(int coord_x, int coord_y);

    // pre: Objeto previamente creado
    // pos: Quita la vida ubicada en la posicion de la lista
    void quitar_vida( int orden_edificio );

    // pre: Objeto previamente creado
    // pos: Resta la cantidad de edificios construidos
    void restar_cantidad_construidos();

    // pre: Objeto previamente creado
    // pos: Resta la vida la del edfiicio segun la posicion
    void restar_vida( int posicion );

    // pre: Objeto previamente creado
    // pos: Suma la vida la del edfiicio segun la posicion
    void sumar_vida( int posicion );




};


#endif // EDIFICIO_JUGADOR_H