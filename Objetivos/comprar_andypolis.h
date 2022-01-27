#ifndef COMPRAR_ANDYPOLIS_H
#define COMPRAR_ANDYPOLIS_H

#include "../objetivo.h"

const int CANT_ANDYCOINS_OBJETIVO = 100000;
const string CONDICIONES_COMPRAR_ANDYPOLIS = "Haber juntado 100.000 andycoins a lo largo de la partida";

class Comprar_andypolis : public Objetivo {

    public:

        // Metodos

        //pre: - 
        // pos: Constructor objeto Comprar_andypolis
        Comprar_andypolis();

        // pre: -
        // pos: Destructor clase Comprar_andypolis
        ~Comprar_andypolis(){};

        // pre: -
        // pos: Obtiene las condiciones para cumplir cono el objetivo :
        string obtener_condiciones();
        
         // pre: -
        // pos: modifica atributo cumplido si se cumplen las conidiciones, si esta complido no vuelve a verificar cumplimiento
        void actualizar_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas); 
        
        // pre: -
        // pos: Obtiene una string con la cantidad necesaria para cumplir con el objetivo
        string obtener_progreso( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas);
};

#endif

