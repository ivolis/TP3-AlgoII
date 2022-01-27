#ifndef TERRENO_H
#define TERRENO_H


#include <string>
#include "../errores.h"
#include "../superficie.h"

using namespace std;

class Terreno : public Superficie {

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR de un terreno
    Terreno(char identificador);

    // pre: -
    // pos: CONSTRUCTOR de un terreno default
    Terreno():Superficie(){};

    // pre: -
    // pos: DESTRUCTOR de un terreno
    ~Terreno(){};

};





#endif // TERRENO_H