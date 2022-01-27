#ifndef CASILLERO_TRANSITABLE_H
#define CASILLERO_TRANSITABLE_H

#include "../material.h"
#include "../casillero.h"
#include "../formatos.h"

class Casillero_transitable: public Casillero {

private:
    // Atributos
    Material* material_ocupado = nullptr; // al momento de crearse no tiene nada "en el piso"

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR de un casillero transitable
    Casillero_transitable(Superficie* superficie, int coord_x, int coord_y, bool ocupado, Jugador_t jugador);

    // pre: -
    // pos: CONSTRUCTOR de un casillero transitable default
    Casillero_transitable():Casillero(){};

    // pre: -
    // pos: DESTRUCTOR de un casillero transitable
    ~Casillero_transitable();

    // pre: -
    // pos: imprime una letra que representa el material que tiene "en el piso" y el color de la superficie del casillero
    void imprimir_casillero();

    // pre: -
    // pos: imprime un mensaje diciendo si tiene o no un material y que es un casillero transitable
    void consultar_casillero();

    // pre: -
    // pos: pone/"tira" un material en el casillero
    void poner_material(Material* material);

    // pre: debe ser un casillero ocupado (validado en funcionas mas externas)
    // pos: devuelve el nombre del material que esta ocupando el casillero
    string obtener_nombre_objeto_de_casillero();

    // pre: antes de llamarla se debe verificar que efectivamente el casillero este ocupado
    // pos: "Quita" el material del "Suelo" (casillero)
    void destruir_material();

    // pre: antes de llamarla se debe verificar que efectivamente el casillero este ocupado
    // pos: obtiene el identificador del material que esta en el "suelo"
    char obtener_identificador_recurso_de_casillero(){return material_ocupado -> obtener_identificador();};

    // pre: antes de llamarla se debe verificar que efectivamente el casillero este ocupado 
    // pos: obtiene la cantidad el material que esta en el "suelo"
    double recolectar_recursos(){return material_ocupado -> obtener_cantidad();};

};



#endif // CASILLERO_TRANSITABLE_H