#ifndef FABRICA_H
#define FABRICA_H

#include "../edificio.h"
#include "../material.h"

const double CANTIDAD_METAL_BRINDADA = 40;

class Fabrica: public Edificio {
private:
    // Atributos
    char identificador_material_brindado;
    double cantidad_material_brindado;

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR fabrica
    Fabrica(char identificador, Jugador_t creador, double deposito);

    // pre: -
    // pos: DESTRUCTOR fabrica
    ~Fabrica(){};

    // pre: -
    // pos: obtiene el tipo de edificio que es (su "nombre")
    string obtener_tipo_edificio();

    // pre: -
    // pos: obtiene el identificador del material que brinda
    char obtener_identificador_recurso();

    // pre: -
    // pos: deposita 40 de metal en el deposito
    void depositar_recurso();
};


#endif //FABRICA_H
