#ifndef MINERO_H
#define MINERO_H

#include "../objetivo.h"

const int CANT_MINAS_OBJETIVO = 2;
const string CONDICIONES_MINERO = "Haber construido una mina de cada tipo.";

class Minero: public Objetivo {
    
    public:

        // Metodos

        // pre: - 
        // pos: Constructor objeto Minero
        Minero();

        // pre: -
        // pos: Destructor clase Minero
        ~Minero(){};

        // pre: -
        // pos: Obtiene las condiciones para cumplir cono el objetivo
        string obtener_condiciones();

        // pre: -
        // pos: modifica atributo cumplido si se cumplen las conidiciones, si esta complido no vuelve a verificar cumplimiento
        void actualizar_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuela); 
        
        // pre: -
        // pos: Obtiene una string con la cantidad necesaria para cumplir con el objetivo
        string obtener_progreso(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuela);
};

#endif

