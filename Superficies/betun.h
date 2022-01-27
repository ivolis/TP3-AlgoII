#ifndef BETUN_H
#define BETUN_H


#include <string>
#include "../errores.h"
#include "../superficie.h"

using namespace std;

class Betun : public Superficie {

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR de un betun
    Betun(char identificador);

    // pre: -
    // pos: CONSTRUCTOR de un betun default
    Betun():Superficie(){};

    // pre: -
    // pos: DESTRUCTOR de un betun
    ~Betun(){};

};





#endif // BETUN_H