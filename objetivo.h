#ifndef OBJETIVOS_H
#define OBJETIVOS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "lista.h"
#include "vector.h"
#include "inventario.h"
#include "edificio_jugador.h"
#include "edificio.h"

using namespace std;

const int CANT_OBJ_BOMBARDERO = 5;
const int CANT_OBJ_CANSADO = 0;
const int CANT_OBJ_ARMADO = 10;


const string OBJ_MAS_ALTO_NUBES = "Mas alto que las nubes"; // para que queremos realmente esto?
const string OBJ_COMPRAR_ANDYNOPOLIS = "Comprar Andynopolis";
const string OBJ_EDAD_PIEDRA = "Edad de Piedra";
const string OBJ_BOMBARDERO = "Bombardero";
const string OBJ_ENERGETICO = "Energetico";
const string OBJ_LETRADO = "Letrado";
const string OBJ_MINERO = "Minero";
const string OBJ_CANSADO = "Cansado";
const string OBJ_CONSTRUCTOR = "Constructor";
const string OBJ_ARMADO = "Armado";
const string OBJ_EXTREMISTA = "Extremista";
const string OBJ_CUMPLIDO =  "¡OBJETIVO CUMPLIDO!";

enum Objetivo_secundario_t{
    OPC_COMPRAR_ANDYNOPOLIS,
    OPC_EDAD_PIEDRA,
    OPC_BOMBARDERO,
    OPC_ENERGETICO,
    OPC_LETRADO,
    OPC_MINERO,
    OPC_CANSADO,
    OPC_CONSTRUCTOR,
    OPC_ARMADO,
    OPC_EXTREMISTA
};


class Objetivo{

    protected:
        string nombre;
        bool cumplido;
    
    public:
        // pre: - 
        // pos: Constructor Objetico por parametro
        Objetivo(string nombre_obj, bool realizado);

        // pre: - 
        // pos: Destructor Objetico por parametro
        virtual ~Objetivo(){};

        // pre: - 
        // pos: Constructor Objetico por parametro
        string obtener_nombre();

        // pre: -
        // pos: Verifica el cumplimiento del objetico
        bool chequear_cumplimiento();

        // pre: -
        // pos: Obtiene las condiciones para cumplir cono el objetivo
        virtual string obtener_condiciones() = 0;

        // pre: -
        // pos: modifica atributo cumplido si se cumplen las conidiciones, si esta complido no vuelve a verificar cumplimiento
        virtual void actualizar_cumplimiento(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios, int cant_maxima_escuelas) = 0; 
        
        // pre: -
        // pos: Obtiene una string con la cantidad necesaria para cumplir con el objetivo
        virtual string obtener_progreso(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios, int cant_maxima_escuelas) = 0;
};


#endif