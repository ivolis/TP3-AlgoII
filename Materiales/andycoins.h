#ifndef ANDYCOINS_H
#define ANDYCOINS_H

#include "../material.h"


class Andycoins: public Material {
    private:
    

    public:
    
    // pre: -
    // pos: CONSTRUCTOR y DESTRUCTOR de andycoins
    Andycoins(double cantidad);
    ~Andycoins(){};

    // pre: -
    // post: devuelve una string con el tipo de material que es (andycoins)
    string obtener_nombre_material();

};


#endif // ANDYCOINS_H
