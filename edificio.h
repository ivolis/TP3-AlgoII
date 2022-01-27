#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <string>
#include <sstream>
#include <iostream>
//#include "lista.h"
#include "errores.h"
#include "herramientas.h"

using namespace std;

const string STR_MINA = "mina";
const string STR_ASERRADERO = "aserradero";
const string STR_FABRICA = "fabrica";
const string STR_ESCUELA = "escuela";
const string STR_OBELISCO = "obelisco";
const string STR_P_ELECTRICA = "planta electrica";
const string STR_MINA_ORO = "mina oro";

const int CANTIDAD_EDIFICIOS_OBJETIVO = 6;

const string NOMBRES_EDIFICIOS[] = {
    STR_MINA,
    STR_ASERRADERO,
    STR_FABRICA,
    STR_ESCUELA,
    STR_OBELISCO,
    STR_P_ELECTRICA,
    STR_MINA_ORO,
};

class Edificio{

protected:
    // Atributos
    char identificador;
    Jugador_t creador;
    double deposito;

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR edificio
    Edificio();

    // pre: identificador valido (entre los que hay en la consigna)
    // pos: CONSTRUCTOR con parametro
    Edificio(char identificador, Jugador_t creador, double deposito);

    // pre: -
    // pos: DESTRUCTOR de edificios
    virtual ~Edificio(){};

    // pre: -
    // pos: devuelve el tipo/nombre del edificio
    virtual string obtener_tipo_edificio() = 0;

    // pre: -
    // pos: obtiene (en caso de poder brindar materiales) el identificador del material que brinda el edificio
    virtual char obtener_identificador_recurso() = 0; 

    // pre: -
    // pos: Deposita el recurso segun el edificio 
    virtual void depositar_recurso(){};

    // pre: -
    // pos: obtiene (en caso de poder brindar materiales/energia) la cantidad de material/energia acumulada en el deposito del edificio
    double recolectar_recursos();

    // pre: -
    // pos: devuelve el identificador del edificio
    char obtener_identificador();

    // pre: -
    // pos: devuelve el creador del edificio
    Jugador_t obtener_creador();

};


#endif // EDIFICIO_H