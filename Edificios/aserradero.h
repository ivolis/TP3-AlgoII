#ifndef ASERRADERO_H
#define ASERRADERO_H

#include "../edificio.h"
#include "../material.h"

const double CANTIDAD_MADERA_BRINDADA = 25;


class Aserradero: public Edificio {
private:
    // Atributos
    char identificador_material_brindado;
    double cantidad_material_brindado;

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR aserradero
    Aserradero(char identificador, Jugador_t creador, double deposito);

    // pre: -
    // pos: DESTRUCTOR aserradero
    ~Aserradero(){};

    // pre: -
    // pos: obtiene el tipo de edificio que es (su "nombre")
    string obtener_tipo_edificio();

    // pre: -
    // pos: obtiene el identificador del material que brinda
    char obtener_identificador_recurso();

    // pre: -
    // pos: deposita 25 de madera en el deposito
    void depositar_recurso();
};


#endif //ASERRADERO_H
