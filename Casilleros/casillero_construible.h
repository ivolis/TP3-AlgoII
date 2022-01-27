#ifndef CASILLERO_CONSTRUIBLE_H
#define CASILLERO_CONSTRUIBLE_H

#include "../edificio.h"
#include "../casillero.h"
#include "../formatos.h"

class Casillero_construible: public Casillero {

private:
    // Atributos
    Edificio* edificio_construido = nullptr; // hasta no leer ubicaciones.txt no tiene sentido construir el casillero con el edificio

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR de un casillero construible
    Casillero_construible(Superficie* superficie, int coord_x, int coord_y, bool ocupado, Jugador_t jugador);

    // pre: -
    // pos: CONSTRUCTOR de un casillero construible default
    Casillero_construible():Casillero(){};

    // pre: -
    // pos: DESTRUCTOR de un casillero construible
    ~Casillero_construible();

    // pre: -
    // pos: imprime una letra que representa el edificio que tiene construido y el color de la superficie del casillero
    void imprimir_casillero();

    // pre: -
    // pos: imprime un mensaje diciendo si tiene o no un edificio construido y que es un casillero construible
    void consultar_casillero();

    // pre: -
    // pos: "construye" un edificio en el casillero
    void construir_edificio(Edificio* edificio);

    // pre: -
    // pos: elimina el edificio del casillero
    virtual void destruir_edificio();

    // pre: debe ser un casillero ocupado (validado en funciones mas externas)
    // pos: devuelve el nombre del edificio construido en el casillero
    string obtener_nombre_objeto_de_casillero();

    // pre: antes de llamarla tiene que verificarse que efectivamente el casillero este ocupado
    // pos: obtiene el identificador del material que brinda el edificio en el casillero
    char obtener_identificador_recurso_de_casillero();

    // pre: antes de llamarla tiene que verificarse que efectivamente el casillero este ocupado
    // pos: le devuelve al jugador el acumulado de materiales que tiene el edificio del casillero en su deposito
    double recolectar_recursos();

    // pre: antes de llamarla tiene que verificarse que efectivamente el casillero este ocupado
    // pos: "deposita" un recurso en el deposito del edificio del casillero
    void depositar_recurso_casillero();

    // pre: antes de llamarla tiene que verificarse que efectivamente el casillero este ocupado
    // pos: devuelve a que jugador pertenece el edificio del casillero
    void obtener_creador_edificio(Jugador_t &jugador);

};



#endif // CASILLERO_CONSTRUIBLE_H