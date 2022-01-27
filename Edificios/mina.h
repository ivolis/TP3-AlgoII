#ifndef MINA_H
#define MINA_H

#include "../edificio.h"
#include "../material.h"

const double CANTIDAD_PIEDRA_BRINDADA = 15;

class Mina: public Edificio {
private:
    // Atributos
    char identificador_material_brindado;
    double cantidad_material_brindado;

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR mina
    Mina(char identificador, Jugador_t creador, double deposito);

    // pre: -
    // pos: DESTRUCTOR mina
    ~Mina(){};

    // pre: -
    // pos: obtiene el tipo de edificio que es (su "nombre")
    string obtener_tipo_edificio();

    // pre: -
    // pos: obtiene el identificador del material que brinda
    char obtener_identificador_recurso();

    // pre: -
    // pos: deposita 15 piedras en el deposito
    void depositar_recurso();
};


#endif //MINA_H
