#ifndef LAGO_H
#define LAGO_H


#include <string>
#include "../errores.h"
#include "../superficie.h"

using namespace std;

class Lago : public Superficie {

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR de un lago
    Lago(char identificador);

    // pre: -
    // pos: CONSTRUCTOR de un lago default
    Lago():Superficie(){};

    // pre: -
    // pos: DESTRUCTOR de un lago
    ~Lago(){};

};





#endif // LAGO_H