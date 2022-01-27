#include <iostream>
#include "casillero_transitable.h"


// ------------------------------------------------------------------------------------------------------------


Casillero_transitable::Casillero_transitable(Superficie* superficie, int coord_x, int coord_y, bool ocupado, Jugador_t jugador) 
        :Casillero(superficie, coord_x, coord_y, ocupado, jugador){}


// ------------------------------------------------------------------------------------------------------------


Casillero_transitable::~Casillero_transitable(){

    if(material_ocupado != nullptr){
        delete material_ocupado;
        material_ocupado = nullptr;
    }

}


// ------------------------------------------------------------------------------------------------------------


void Casillero_transitable::imprimir_casillero(){

    bool color_superficie_encontrada = false;
    int i = 0;

    while(!color_superficie_encontrada && i < CANT_SUPERFICIES){

        if(superficie -> obtener_color() == codigos_color_superficies[i][0]){
            color_superficie_encontrada = true;
            if(ocupado){
                if(hay_jugador()){
                    cout << codigos_color_superficies[i][1] << identificaciones_jugadores[jugador_en_casillero] << FIN_DE_FORMATO;  
                } else
                    cout << codigos_color_superficies[i][1] << TEXTO_AMARILLO_CHILLON <<
                    material_ocupado -> obtener_identificador() << FIN_DE_FORMATO;
            } else
                cout << codigos_color_superficies[i][1] << ' ' << FIN_DE_FORMATO;
        }

        ++i;
    }

}


// ------------------------------------------------------------------------------------------------------------


void Casillero_transitable::consultar_casillero(){

    cout << TAB << NEGRITA << FONDO_COLOR_ANARANJADO << "Soy un casillero transitable y ";
    if(ocupado){
        if(hay_jugador()){
            cout << "en mi casillero esta el jugador "<< jugador_en_casillero + 1 << FIN_DE_FORMATO << endl;
        } else{
            cout << "tengo " <<  material_ocupado -> obtener_nombre_material() << " en mi casillero" << FIN_DE_FORMATO << endl;
        }
    } else{
        cout << "estoy vacio" << FIN_DE_FORMATO << endl;
    }

}


// ------------------------------------------------------------------------------------------------------------


void Casillero_transitable::poner_material(Material* material){

    this -> material_ocupado = material;
    this -> ocupado = true;

}


// ------------------------------------------------------------------------------------------------------------


string Casillero_transitable::obtener_nombre_objeto_de_casillero(){

    return material_ocupado -> obtener_nombre_material();

}


// ------------------------------------------------------------------------------------------------------------


void Casillero_transitable::destruir_material(){

    delete material_ocupado;
    material_ocupado = nullptr;
    this -> ocupado = false;

}