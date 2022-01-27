#ifndef MADERA_H
#define MADERA_H

#include "../material.h"


class Madera: public Material {

public:
    
    // pre: -
    // pos: CONSTRUCTOR y DESTRUCTOR de madera
    Madera(double cantidad);
    ~Madera(){};

    // pre: -
    // post: devuelve una string con el tipo de material que es (madera)
    string obtener_nombre_material();

};


#endif // MADERA_H
