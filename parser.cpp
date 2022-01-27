#include <iostream>
#include "parser.h"


// ------------------------------------------------------------------------------------------------------------


Parser::Parser(string linea) {

    this -> entrada = new string[CANTIDAD_MAX_PALABRAS_INICIAL];
    this -> cantidad_de_palabras = 0;
    this -> cantidad_de_palabras_max = CANTIDAD_MAX_PALABRAS_INICIAL;
    
    int i = 0;
    stringstream sstream(linea);

    while (sstream.good()){

        if(cantidad_de_palabras == cantidad_de_palabras_max){
            string* nueva_entrada = new string[cantidad_de_palabras_max+AMPLIACION_MAX_PALABRAS];
            for(int j = 0; j < cantidad_de_palabras_max ; j++){
                nueva_entrada[j] = this -> entrada[j]; // reasigno punteros
            }
            delete [] this -> entrada;
            this -> entrada = nueva_entrada;
            cantidad_de_palabras_max += AMPLIACION_MAX_PALABRAS;
        }

        sstream >> this -> entrada[i];
        cantidad_de_palabras++;
        ++i;
    }

}


// ------------------------------------------------------------------------------------------------------------


Parser::~Parser(){

    delete [] entrada;

}


// ----------------------------------------------------------------------------------------------------------//
//                                     +-----------------------+                                             //
//                                     | Para  materiales.txt  |                                             //
//                                     +-----------------------+                                             //
// ----------------------------------------------------------------------------------------------------------//


Material* Parser::procesar_entrada_material(Jugador_t jugador){

    Material* material = nullptr;

    if (tipo_material() == STR_PIEDRA){
        material = new Piedra(cantidad_material(jugador));
    } else if (tipo_material() == STR_MADERA){
        material = new Madera(cantidad_material(jugador));
    } else if (tipo_material() == STR_ANDYCOINS){
        material = new Andycoins(cantidad_material(jugador));
    } else if (tipo_material() == STR_BOMBAS){
        material = new Bombas(cantidad_material(jugador));
    } else {
        material = new Metal(cantidad_material(jugador));
    }

    return material;

}


// ------------------------------------------------------------------------------------------------------------


string Parser::tipo_material(){

    return entrada[0];

}


// ------------------------------------------------------------------------------------------------------------


double Parser::cantidad_material(Jugador_t jugador){
    
    return stod(entrada[jugador + 1]);

}


// ----------------------------------------------------------------------------------------------------------//
//                                     +-----------------------+                                             //
//                                     |  Para edificios.txt   |                                             //
//                                     +-----------------------+                                             //
// ----------------------------------------------------------------------------------------------------------//


Datos_edificio* Parser::procesar_entrada_edificio(){

    Datos_edificio* dato = new Datos_edificio(nombre_edificio(), costo_piedra(), costo_madera(), costo_metal(), cantidad_maxima_permitida());
    
    return dato;
}


// ------------------------------------------------------------------------------------------------------------


char Parser::obtener_identificador_edificio(){

    char identificador;
    locale loc;

    identificador = toupper(this->entrada[0][POS_PRIMERA_LETRA],loc);

    return nombre_edificio() == STR_MINA_ORO ? 'G' : identificador;

}


// ------------------------------------------------------------------------------------------------------------


string Parser::nombre_edificio(){

    string nombre_edificio;
    int i = 0;

    if(!contiene_numeros(this -> entrada[i+1])) {
        
        for (; i < this -> cantidad_de_palabras - CANTIDAD_PARAMETROS_EDIFICIO - 1; ++i) {
            nombre_edificio.append(this->entrada[i]);
            nombre_edificio.append(ESPACIO);
        }

        nombre_edificio.append(this->entrada[i]);
        return nombre_edificio;

    } else return this -> entrada[i];

}


// ------------------------------------------------------------------------------------------------------------


double Parser::costo_piedra(){
    return stod(entrada[cantidad_de_palabras - 4]);
}


// ------------------------------------------------------------------------------------------------------------


double Parser::costo_madera(){
    return stod(entrada[cantidad_de_palabras - 3]);
}


// ------------------------------------------------------------------------------------------------------------


double Parser::costo_metal(){
    return stod(entrada[cantidad_de_palabras - 2]);
}


// ------------------------------------------------------------------------------------------------------------


int Parser::cantidad_maxima_permitida(){
    return stoi(entrada[cantidad_de_palabras - 1]);
}


// ----------------------------------------------------------------------------------------------------------//
//                                     +-----------------------+                                             //
//                                     |     Para mapa.txt     |                                             //
//                                     +-----------------------+                                             //
// ----------------------------------------------------------------------------------------------------------//


Superficie* Parser::procesar_entrada_superficie(){

    Superficie* superficie = nullptr; 

    if (identificador_superficie() == identificador_lago){
        superficie = new Lago(identificador_superficie());
    } else if (identificador_superficie() == identificador_camino){
        superficie = new Camino(identificador_superficie());
    } else if (identificador_superficie() == identificador_betun){
        superficie = new Betun(identificador_superficie());
    } else if (identificador_superficie() == identificador_muelle){
        superficie = new Muelle(identificador_superficie());
    } else {
        superficie = new Terreno(identificador_superficie());
    }

    return superficie; 

}


// ------------------------------------------------------------------------------------------------------------


char Parser::identificador_superficie(){

    return entrada[0][0];

}



// ----------------------------------------------------------------------------------------------------------//
//                                     +-----------------------+                                             //
//                                     |  Para ubicaciones.txt |                                             //
//                                     +-----------------------+                                             //
// ----------------------------------------------------------------------------------------------------------//


Edificio* Parser::procesar_entrada_ubicaciones_edificios(Jugador_t jugador){
   
    Edificio* edificio = nullptr;

    if(nombre_elemento_ubicaciones() == STR_MINA){
        edificio = new Mina(obtener_identificador_edificio_ubicaciones(), jugador, 0);
    } else if(nombre_elemento_ubicaciones() == STR_P_ELECTRICA){
        edificio = new Planta_electrica(obtener_identificador_edificio_ubicaciones(), jugador, 0);
    } else if(nombre_elemento_ubicaciones() == STR_ESCUELA){
        edificio = new Escuela(obtener_identificador_edificio_ubicaciones(), jugador, 0);
    } else if(nombre_elemento_ubicaciones() == STR_OBELISCO){
        edificio = new Obelisco(obtener_identificador_edificio_ubicaciones(), jugador, 0);
    } else if(nombre_elemento_ubicaciones() == STR_FABRICA){
        edificio = new Fabrica(obtener_identificador_edificio_ubicaciones(), jugador, 0);
    } else if(nombre_elemento_ubicaciones() == STR_MINA_ORO){
        edificio = new Mina_oro(obtener_identificador_edificio_ubicaciones(), jugador, 0);
    } else {
        edificio = new Aserradero(obtener_identificador_edificio_ubicaciones(), jugador, 0);
    }

    return edificio;
}


// ------------------------------------------------------------------------------------------------------------


Material* Parser::procesar_entrada_ubicaciones_materiales(){
   
    Material* material = nullptr;

    // DESHARCODEAR
    if(nombre_elemento_ubicaciones() == STR_PIEDRA){
        material = new Piedra( (double) 100 );
    } else if(nombre_elemento_ubicaciones() == STR_MADERA){
        material = new Madera( (double) 50 );
    } else if(nombre_elemento_ubicaciones() == STR_METAL){
        material = new Metal( (double) 50 );
    } else{
        material = new Andycoins( (double) 250 );
    }

    return material;
}


// ------------------------------------------------------------------------------------------------------------


string Parser::nombre_elemento_ubicaciones(){
    
    string nombre_elemento;
    int i = 0;

    for (; i < cantidad_de_palabras - CANTIDAD_PARAMETROS_UBICACIONES ; ++i){
        nombre_elemento.append(this -> entrada[i]);
        nombre_elemento.append(ESPACIO);
    }
    nombre_elemento.append(this->entrada[i]);
    
    return nombre_elemento;

}


// ------------------------------------------------------------------------------------------------------------


char Parser::obtener_identificador_edificio_ubicaciones(){

    char identificador;
    locale loc;

    identificador = toupper(this->entrada[0][POS_PRIMERA_LETRA],loc);

    return nombre_elemento_ubicaciones() == STR_MINA_ORO ? 'G' : identificador;

}


// ------------------------------------------------------------------------------------------------------------


int Parser::obtener_coordenada_x(){

    string coordenada;
    int i = 1;

    while(isdigit(this -> entrada[cantidad_de_palabras - 2][i])){
        coordenada.append(1,this -> entrada[cantidad_de_palabras - 2][i]);
        ++i;
    }


    // Si i > 1 significa que es un numero de mas de un digito
    return i > 1 ? stoi(coordenada) : this -> entrada[cantidad_de_palabras - 2][1] - '0';

}


// ------------------------------------------------------------------------------------------------------------


int Parser::obtener_coordenada_y(){

    string coordenada;
    int i = 0;

    while(isdigit(this -> entrada[cantidad_de_palabras - 1][i])){
        coordenada.append(1, this -> entrada[cantidad_de_palabras - 1][i]);
        ++i;
    }

    // Si i > 0 significa que es un numero de mas de un digito
    return i > 0 ? stoi(coordenada) : this -> entrada[cantidad_de_palabras - 1][0] - '0';

}


// --------------------------------------------------------------------------------------------------------------//
//                                     +---------------------------+                                             //
//                                     | Para  lluvia de recursos  |                                             //
//                                     +---------------------------+                                             //
// --------------------------------------------------------------------------------------------------------------//


Material* Parser::procesar_entrada_material_lluvia(){

    Material* material = nullptr;

    if (tipo_material() == STR_PIEDRA){
        material = new Piedra(cantidad_material_lluvia());
    } else if (tipo_material() == STR_MADERA){
        material = new Madera(cantidad_material_lluvia());
    } else if (tipo_material() == STR_ANDYCOINS){
        material = new Andycoins(cantidad_material_lluvia());
    } else if (tipo_material() == STR_BOMBAS){
        material = new Bombas(cantidad_material_lluvia());
    } else {
        material = new Metal(cantidad_material_lluvia());
    }

    return material;

}


// ------------------------------------------------------------------------------------------------------------


double Parser::cantidad_material_lluvia(){
    
    return stod(entrada[1]);

}