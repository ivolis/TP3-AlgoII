#ifndef CANSADO_H
#define CANSADO_H

#include "../objetivo.h"

const double CANT_ENERGIA_OBJETIVO = 100;
const string CONDICIONES_CANSADO = "Terminar un turno con 0 de energía.";

class Cansado: public Objetivo {
    
    public:
        // Metodos
        
        // pre: - 
        // pos: Constructor objeto ansado
        Cansado();

        // pre: -
        // pos: Destructor clase Cansado
        ~Cansado(){};

        // pre: -
        // pos: Obtiene las condiciones para cumplir cono el objetivo 
        string obtener_condiciones();

        // pre: -
        // pos: modifica atributo cumplido si se cumplen las conidiciones, si esta complido no vuelve a verificar cumplimiento
        void actualizar_cumplimiento(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas); 
        
        // pre: -
        // pos: Obtiene una string con la cantidad necesaria para cumplir con el objetivo
        string obtener_progreso(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas);
};

#endif

