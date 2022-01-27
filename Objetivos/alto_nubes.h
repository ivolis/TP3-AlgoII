#ifndef ALTO_NUBES_H
#define ALTO_NUBES_H

#include "../objetivo.h"

const string CONDICIONES_MAS_ALTO_NUBES = "Construir el obelisco";
const int CANT_OBELISCOS = 1;

class Alto_nubes: public Objetivo {

    public:

        // Metodos

        // pre: - 
        // pos: Constructor objeto Alto nubes
        Alto_nubes();

        // pre: -
        // pos: Destructor clase Alto nubes
        ~Alto_nubes(){};
        
        // pre: -
        // pos: Obtiene las condiciones para cumplir cono el objetivo 
        string obtener_condiciones();

        // pre: -
        // pos: modifica atributo cumplido si se cumplen las conidiciones, si esta complido no vuelve a verificar cumplimiento
        void actualizar_cumplimiento(   const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios,int cant_maxima_escuelas); 
        
        // pre: -
        // pos: Obtiene una string con la cantidad necesaria para cumplir con el objetivo
        string obtener_progreso(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios,int cant_maxima_escuelas);
};

#endif

