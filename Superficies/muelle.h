#ifndef MUELLE_H
#define MUELLE_H


#include <string>
#include "../errores.h"
#include "../superficie.h"

using namespace std;

class Muelle : public Superficie {

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR de un muelle
    Muelle(char identificador);

    // pre: -
    // pos: CONSTRUCTOR de un muelle default
    Muelle():Superficie(){};

    // pre: -
    // pos: DESTRUCTOR de un muelle
    ~Muelle(){};

};





#endif // MUELLE_H