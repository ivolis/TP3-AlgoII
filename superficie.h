#ifndef SUPERFICIE_H
#define SUPERFICIE_H

#include <sstream>
#include <fstream>
#include <string>
#include "errores.h"
#include "formatos.h"
#include "herramientas.h"

using namespace std;

const int CANT_SUPERFICIES = 5;
const string STR_COLOR_AZUL = "azul";
const string STR_COLOR_VERDE = "verde";
const string STR_COLOR_GRIS = "gris";
const string STR_COLOR_CENIZA = "ceniza";
const string STR_COLOR_MARRON = "marron";

const string codigos_color_superficies[CANT_SUPERFICIES][CANT_SUPERFICIES] = {
    {STR_COLOR_AZUL, FONDO_COLOR_AZUL},
    {STR_COLOR_GRIS, FONDO_COLOR_GRIS},
    {STR_COLOR_VERDE, FONDO_COLOR_VERDE},
    {STR_COLOR_CENIZA, FONDO_COLOR_CENIZA},
    {STR_COLOR_MARRON, FONDO_COLOR_MARRON}
};

const char identificador_lago = 'L';
const char identificador_camino = 'C';
const char identificador_terreno = 'T';
const char identificador_muelle = 'M';
const char identificador_betun = 'B';

class Superficie{

protected:
    // Atributos
    char identificador;
    string color;
    bool transitable;
    bool construible;
    bool accesible;
    int costo_energia_jugador[2];

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR de superficie
    Superficie(char identificador);

    // pre: -
    // pos: CONSTRUCTOR de una superficie default
    Superficie();

    // pre: -
    // pos: DESTRUCTOR de una superficie (virtual hacia todas las hijas)
    virtual ~Superficie(){};

    // pre: -
    // pos: devuelve el identificador de la superficie
    char obtener_identificador();

    // pre: -
    // pos: obtiene el color caracteristico de la superficie
    string obtener_color();

    // pre: -
    // pos: obtiene el peso (costo de energia) de un jugador para pasar por la superficie
    int obtener_peso(Jugador_t jugador);

    // pre: -
    // pos: devuelve si es una superficie transitable o no
    bool es_transitable();

    // pre: -
    // pos: devuelve si es una superficie construible o no
    bool es_construible();

    // pre: -
    // pos: devuelve si es una superficie accesible o no
    bool es_accesible();

};


#endif // SUPERFICIE_H