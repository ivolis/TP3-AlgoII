#ifndef CAMINO_H
#define CAMINO_H


#include <string>
#include "../errores.h"
#include "../superficie.h"

using namespace std;

class Camino : public Superficie {

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR de un camino
    Camino(char identificador);

    // pre: -
    // pos: CONSTRUCTOR de un camino default
    Camino():Superficie(){};

    // pre: -
    // pos: DESTRUCTOR de un camino
    ~Camino(){};

};





#endif // CAMINO_H