#ifndef EDAD_PIEDRA_H
#define EDAD_PIEDRA_H

#include "../objetivo.h"

const int CANT_PIEDRA_OBJETIVO = 50000;
const string CONDICIONES_EDAD_PIEDRA = "Tener en el inventario 50000 piedras";


class Edad_piedra: public Objetivo {
    
    public:

        // Metodos

        // pre: - 
        // pos: Constructor objeto Edad_piedra
        Edad_piedra();

        // pre: -
        // pos: Destructor clase dad_piedra
        ~Edad_piedra(){};

        // pre: -
        // pos: Obtiene las condiciones para cumplir cono el objetivo
        string obtener_condiciones();

        // pre: -
        // pos: modifica atributo cumplido si se cumplen las conidiciones, si esta complido no vuelve a verificar cumplimiento
        void actualizar_cumplimiento(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas); 
        
       // pre: -
        // pos: Obtiene una string con la cantidad necesaria para cumplir con el objetivo
        string obtener_progreso(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas);
};

#endif

