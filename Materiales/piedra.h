#ifndef PIEDRA_H
#define PIEDRA_H

#include "../material.h"


class Piedra: public Material {

public:

    // pre: -
    // pos: CONSTRUCTOR y DESTRUCTOR de piedra
    Piedra(double cantidad);
    ~Piedra(){};

    // pre: -
    // post: devuelve una string con el tipo de material que es (piedra)
    string obtener_nombre_material();

};


#endif // PIEDRA_H
