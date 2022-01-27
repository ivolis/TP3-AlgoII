#ifndef ENERGETICO_H
#define ENERGETICO_H

#include "../objetivo.h"

const int CANT_ENERGIA_MAXIMA = 100;
const string CONDICIONES_ENERGETICO = "Haber terminado un turno con 100 puntos de energía";


class Energetico: public Objetivo {

    public:

        // Metodos

        // pre: - 
        // pos: Constructor objeto Energetico
        Energetico();

        // pre: -
        // pos: Destructor clase Energetico
        ~Energetico(){};

        // pre: -
        // pos: Obtiene las condiciones para cumplir cono el objetivo 
        string obtener_condiciones();

       // pre: -
        // pos: modifica atributo cumplido si se cumplen las conidiciones, si esta complido no vuelve a verificar cumplimiento
        void actualizar_cumplimiento(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas);
        
        // pre: -
        // pos: Obtiene una string con la cantidad necesaria para cumplir con el objetivo
        string obtener_progreso(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas);
};


#endif

