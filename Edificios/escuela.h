#ifndef ESCUELA_H
#define ESCUELA_H

#include "../edificio.h"
#include "../material.h"

const double CANTIDAD_ANDYCOINS_BRINDADAS_ESCUELA = 25;

class Escuela: public Edificio {

private:
    char identificador_material_brindado;
    double cantidad_material_brindado;

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR escuela
    Escuela(char identificador, Jugador_t creador, double deposito);

    // pre: -
    // pos: DESTRUCTOR escuela
    ~Escuela(){};

    // pre: -
    // pos: obtiene el tipo de edificio que es (su "nombre")
    string obtener_tipo_edificio();

    // pre: -
    // pos: obtiene el identificador del material que brinda
    char obtener_identificador_recurso();

    // pre: -
    // pos: deposita 25 andycoins en el deposito
    void depositar_recurso();
};


#endif //ESCUELA_H
