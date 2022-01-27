#ifndef METAL_H
#define METAL_H

#include "../material.h"


class Metal: public Material {

public:

    // pre: -
    // pos: CONSTRUCTOR y DESTRUCTOR de metal
    Metal(double cantidad);
    ~Metal(){};

    // pre: -
    // post: devuelve una string con el tipo de material que es (metal)
    string obtener_nombre_material();

};


#endif // METAL_H
