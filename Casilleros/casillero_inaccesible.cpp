#include <iostream>
#include "casillero_inaccesible.h"


// ------------------------------------------------------------------------------------------------------------


Casillero_inaccesible::Casillero_inaccesible(Superficie* superficie, int coord_x, int coord_y, bool ocupado, Jugador_t jugador) 
        :Casillero(superficie, coord_x, coord_y, ocupado, jugador){}


// ------------------------------------------------------------------------------------------------------------


void Casillero_inaccesible::imprimir_casillero(){

    bool color_superficie_encontrada = false;
    int i = 0;

    while(!color_superficie_encontrada && i < CANT_SUPERFICIES){

        if(superficie -> obtener_color() == codigos_color_superficies[i][0]){
            color_superficie_encontrada = true;
            if(hay_jugador()){
                cout << codigos_color_superficies[i][1] << identificaciones_jugadores[jugador_en_casillero] << FIN_DE_FORMATO;
            } else
                cout << codigos_color_superficies[i][1] << ' ' << FIN_DE_FORMATO;
        }

        ++i;
    }

}

// ------------------------------------------------------------------------------------------------------------


void Casillero_inaccesible::consultar_casillero(){

    cout << TAB << NEGRITA << FONDO_COLOR_ANARANJADO << "Soy un casillero inaccesible y ";
    if(hay_jugador()){
        cout << "en mi casillero esta el jugador "<< jugador_en_casillero + 1 << FIN_DE_FORMATO << endl;
    } else{
        cout << "estoy vacio" << FIN_DE_FORMATO << endl;
    }
}