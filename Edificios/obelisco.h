#ifndef OBELISCO_H
#define OBELISCO_H

#include "../edificio.h"


class Obelisco: public Edificio {
public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR obelisco
    Obelisco(char identificador, Jugador_t creador, double deposito);

    // pre: -
    // pos: DESTRUCTOR obelisco
    ~Obelisco(){};

    // pre: -
    // pos: obtiene el tipo de edificio que es (su "nombre")
    string obtener_tipo_edificio();

    // pre: -
    // pos: no brinda material (se necesita por metodo virtual puro que se uso para devolver return =/= void)
    char obtener_identificador_recurso(){return ' ';}


};


#endif //OBELISCO_H
