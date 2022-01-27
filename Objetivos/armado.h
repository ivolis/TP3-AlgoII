#ifndef ARMADO_H
#define ARMADO_H

#include "../objetivo.h"

const int CANT_BOMBAS_OBJETIVO = 10;
const string CONDICIONES_ARMADO = "Tener 10 bombas en el inventario";

class Armado: public Objetivo {

    public:
        // Metodos

        // pre: - 
        // pos: Constructor objeto Armado
        Armado();

        // pre: -
        // pos: Destructor clase Armado
        ~Armado(){};

        // pre: -
        // pos: Obtiene las condiciones para cumplir cono el objetivo
        string obtener_condiciones();

        // pre: -
        // pos: modifica atributo cumplido si se cumplen las conidiciones, si esta complido no vuelve a verificar cumplimiento
        void actualizar_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios,int cant_maxima_escuelas); 
        
        /// pre: -
        // pos: Obtiene una string con la cantidad necesaria para cumplir con el objetivo
        string obtener_progreso(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios,int cant_maxima_escuelas);
};

#endif

