#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H


#include "../casillero.h"
#include "../formatos.h"

class Casillero_inaccesible : public Casillero {

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR de un casillero inaccesible
    Casillero_inaccesible(Superficie* superficie, int coord_x, int coord_y, bool ocupado, Jugador_t jugador);

    // pre: -
    // pos: CONSTRUCTOR de un casillero inaccesible default
    Casillero_inaccesible():Casillero(){};

    // pre: -
    // pos: DESTRUCTOR de un casillero transitable
    ~Casillero_inaccesible(){};

    // pre: -
    // pos: imprime el color de la superficie del casillero (es inaccesible asi que no tiene nada)
    void imprimir_casillero();

    // pre: -
    // pos: imprime un mensaje diciendo que es un casillero inaccesible
    void consultar_casillero();

    // Aclaracion: estas 3 funciones estan ya que es la unica forma de definir un metodo virtual con return != void
    // (haciendolo virtual puro y devolviendo defaults en los que no se requieran)

    // pre: -
    // pos: a priori no puede ocuparse con nada un casillero inaccesible, asi que devuelve una string vacia
    string obtener_nombre_objeto_de_casillero(){return "";};

    // pre: -
    // pos: momentaneamente no tiene sentido pedirle un material a un casillero inaccesible
    char obtener_identificador_recurso_de_casillero(){return ' ';};

    // pre: - 
    // pos: momentaneamente no tiene sentido pedirle info de un material a un casillero inaccesible
    double recolectar_recursos(){return 0;};

};



#endif // CASILLERO_INACCESIBLE_H