#ifndef MINA_ORO_H
#define MINA_ORO_H

#include "../edificio.h"
#include "../material.h"

const double CANTIDAD_ANDYCOINS_BRINDADAS_MINA_ORO = 50;

class Mina_oro: public Edificio {

private:
    char identificador_material_brindado;
    double cantidad_material_brindado;

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR escuela
    Mina_oro(char identificador, Jugador_t creador, double deposito);

    // pre: -
    // pos: DESTRUCTOR escuela
    ~Mina_oro(){};

    // pre: -
    // pos: obtiene el tipo de edificio que es (su "nombre")
    string obtener_tipo_edificio();

    // pre: -
    // pos: obtiene el identificador del material que brinda
    char obtener_identificador_recurso();

    // pre: -
    // pos: deposita 50 andycoins en el deposito
    void depositar_recurso();
};

#endif //MINA_ORO