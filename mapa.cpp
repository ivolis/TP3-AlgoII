#include <iostream>
#include "mapa.h"


// ------------------------------------------------------------------------------------------------------------


Mapa::Mapa(fstream& archivo_mapa){

    string letra_leida;

    archivo_mapa >> letra_leida;
    this -> cantidad_filas = stoi(letra_leida);
    archivo_mapa >> letra_leida;
    this -> cantidad_columnas = stoi(letra_leida);

    // Creo el mapa
    mapa = new Casillero**[cantidad_filas];
    for (int i = 0 ; i < cantidad_filas ; ++i){
        mapa[i] = new Casillero*[cantidad_columnas];
    }

    // Utilizo el polimorfismo dinamico para crear el casillero y superficie correspondiente
    for(int i = 0 ; i < cantidad_filas ; ++i){
        for (int j = 0 ; j < cantidad_columnas; ++j){
            
            archivo_mapa >> letra_leida;
            Parser parser(letra_leida);
            Superficie* superficie_leida = parser.procesar_entrada_superficie();
            if(superficie_leida -> es_accesible()){
                if ( superficie_leida -> es_construible()){
                    mapa[i][j] = new Casillero_construible(superficie_leida, i, j, false, NADIE);
                } else {
                    mapa[i][j] = new Casillero_transitable(superficie_leida, i, j, false, NADIE);
                    Coordenadas* coord = new Coordenadas;
                    *coord = {i,j};
                    casilleros_transitables_disponibles.alta(coord,0);
                }
            } else {
                mapa[i][j] = new Casillero_inaccesible(superficie_leida, i, j, false, NADIE);
            }

        }
    }

}


// ------------------------------------------------------------------------------------------------------------


Mapa::Mapa(){

    this -> mapa = nullptr;
    this -> cantidad_columnas = 0;
    this -> cantidad_filas = 0;

}


// ------------------------------------------------------------------------------------------------------------


Mapa::~Mapa(){

    for(int i = 0 ; i < cantidad_filas ; ++i){
        for(int j = 0 ; j < cantidad_columnas ; ++j){
            delete mapa[i][j];
            mapa[i][j] = nullptr;
        }

        delete [] mapa[i];
        mapa[i] = nullptr;
    }

    for(int i = 0 ; i < casilleros_transitables_disponibles.obtener_cantidad() ; ++i){
        delete casilleros_transitables_disponibles.consulta(i);
    }

    delete [] mapa;
    mapa = nullptr;

}


// ------------------------------------------------------------------------------------------------------------


int Mapa::obtener_filas() const{

    return cantidad_filas;

}


// ------------------------------------------------------------------------------------------------------------


int Mapa::obtener_columnas() const{

    return cantidad_columnas;

}


// ------------------------------------------------------------------------------------------------------------


string Mapa::obtener_nombre_objeto_de_casillero_ocupado(int coord_x, int coord_y){

    return mapa[coord_x][coord_y]-> obtener_nombre_objeto_de_casillero();

}


// ------------------------------------------------------------------------------------------------------------


int Mapa::obtener_peso_casillero(int coord_x, int coord_y, Jugador_t jugador) const{

    return mapa[coord_x][coord_y] -> obtener_peso(jugador);

}


// ------------------------------------------------------------------------------------------------------------


int Mapa::obtener_indice_casillero_transitable(int coord_x, int coord_y){

    int i = 0;
    int posicion = -1;
    bool encontrado = false;

    while( i < casilleros_transitables_disponibles.obtener_cantidad() && !encontrado){
        
        if(casilleros_transitables_disponibles.consulta(i) -> coordenada_x == coord_x && casilleros_transitables_disponibles.consulta(i) -> coordenada_y == coord_y){
            encontrado = true;
            posicion = i;
        }

        ++i;
    }

    return posicion;

}


// ------------------------------------------------------------------------------------------------------------


bool Mapa::se_puede_transitar(int coord_x, int coord_y){

    return mapa[coord_x][coord_y] -> es_casillero_transitable();

}


// ------------------------------------------------------------------------------------------------------------


bool Mapa::se_puede_construir(int coord_x, int coord_y){

    return mapa[coord_x][coord_y] -> es_casillero_construible();

}


// ------------------------------------------------------------------------------------------------------------


bool Mapa::se_puede_acceder(int coord_x, int coord_y){

    return mapa[coord_x][coord_y] -> es_casillero_accesible();

}

// ------------------------------------------------------------------------------------------------------------


bool Mapa::casillero_esta_ocupado(int coord_x, int coord_y){

    return mapa[coord_x][coord_y] -> esta_ocupado();

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Mapa::asignar_edificio_en_coord(Edificio* edificio, int coord_x, int coord_y){

    Estado_t estado = OK;

    if(mapa[coord_x][coord_y] -> es_casillero_construible()){ // usar se puede construir
        if(!(casillero_esta_ocupado(coord_x,coord_y)) ){
            mapa[coord_x][coord_y] -> construir_edificio(edificio);
            } else {
                estado = ERROR_CASILLERO_OCUPADO;
                delete edificio;
                edificio = nullptr;
            }
    } else {
        estado = ERROR_CASILLERO_NO_CONSTRUIBLE;
        delete edificio;
        edificio = nullptr;
    }

    return estado;

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Mapa::destruir_edificio_en_coord(int coord_x, int coord_y){

    Estado_t estado = OK;

    if(mapa[coord_x][coord_y] -> es_casillero_construible()){ // usar se puede construir
        if(casillero_esta_ocupado(coord_x,coord_y)){
            mapa[coord_x][coord_y] -> destruir_edificio();
        } else estado = ERROR_CASILLERO_VACIO;
    } else estado = ERROR_CASILLERO_NO_CONSTRUIBLE;

    return estado;

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Mapa::posicionar_jugador(int coord_x, int coord_y, Jugador_t jugador){

    if(coord_x > cantidad_columnas || coord_y > cantidad_filas)
        return ERROR_POSICION_INEXISTENTE;
    mapa[coord_x][coord_y] -> posicionar_jugador(jugador);

    if(se_puede_transitar(coord_x,coord_y)){
        int ind = obtener_indice_casillero_transitable(coord_x, coord_y);
        delete casilleros_transitables_disponibles.consulta(ind);
        casilleros_transitables_disponibles.baja(ind);
    }


    return OK;

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Mapa::eliminar_posicion_jugador(int coord_x, int coord_y){

    if(coord_x > cantidad_columnas || coord_y > cantidad_filas)
        return ERROR_POSICION_INEXISTENTE;
    
    mapa[coord_x][coord_y] -> eliminar_jugador();

    return OK;

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Mapa::consultar_casillero(int coord_x, int coord_y) const{

    Estado_t estado = OK;

    if(coord_x < cantidad_filas && coord_y < cantidad_columnas){
        mapa[coord_x][coord_y] -> consultar_casillero();
    } else estado = ERROR_POSICION_INEXISTENTE;

    return estado;

}


// ------------------------------------------------------------------------------------------------------------


void Mapa::mostrar_mapa(int pos_visual_x, int pos_visual_y){

    imprimir_leyenda_mapa();

    //Gotoxy gotoxy;

    for (int i = 0 ; i < cantidad_filas ; ++i){
        //cout << gotoxy.pos(pos_visual_x,pos_visual_y+i);
        cout << "\t\t";
        for (int j = 0 ; j < cantidad_columnas ; ++j){
            mapa[i][j] -> imprimir_casillero();
        }
        cout << endl;
    }

 // Para mejor visualizacion del mapa es posible descomentar el siguiente codigo:
 
/*
    string retorno;
    cout << endl;
    cout << "Ingrese cualquier cosa para volver" << endl;
    getline(cin, retorno);
*/

}


// ------------------------------------------------------------------------------------------------------------


void Mapa::imprimir_leyenda_mapa(){

cout << TAB << "╔════════════════════════════════════════════════════════╗" << endl;
cout << TAB << NEGRITA << "║ " << "Superficies:" << string(42, ' ') << FIN_DE_FORMATO " ║" << endl;
cout << TAB << "║ " << FONDO_COLOR_AZUL  << "LAGO" << string(3, ' ') << FIN_DE_FORMATO << string(47, ' ') << " ║" << endl;
cout << TAB << "║ " << FONDO_COLOR_GRIS  << "CAMINO" << string(1, ' ') << FIN_DE_FORMATO << string(47, ' ') << " ║" << endl;
cout << TAB << "║ " << FONDO_COLOR_VERDE  << "TERRENO" << FIN_DE_FORMATO << string(47, ' ') << " ║" << endl;
cout << TAB << "║ " << FONDO_COLOR_CENIZA  << "BETUN" << string(2, ' ') << FIN_DE_FORMATO << string(47, ' ') << " ║" << endl;
cout << TAB << "║ " << FONDO_COLOR_MARRON  << "MUELLE" << string(1, ' ') << FIN_DE_FORMATO << string(47, ' ') << " ║" << endl;
cout << TAB << "║ " << string(54, ' ') << " ║" << endl;
cout << TAB << NEGRITA << "║ " << "Edificios:" << string(44, ' ') << FIN_DE_FORMATO << " ║" << endl;
cout << TAB << "║ " << "(A) Aserradero"  <<  string(40, ' ') << " ║" << endl;
cout << TAB << "║ " << "(E) Escuela"  << string(43, ' ') << " ║" << endl;
cout << TAB << "║ " << "(F) Fabrica"  << string(43, ' ') << " ║" << endl;
cout << TAB << "║ " << "(M) Mina"  << string(46, ' ') << " ║" << endl;
cout << TAB << "║ " << "(G) Mina oro"  << string(42, ' ') << " ║" << endl;
cout << TAB << "║ " << "(O) Obelisco"  << string(42, ' ') << " ║" << endl;
cout << TAB << "║ " << "(P) Planta electrica" << string(34, ' ')  << " ║" << endl;
cout << TAB << "║ " << string(54, ' ') << " ║" << endl;
cout << TAB << NEGRITA << "║ " << "Materiales:" << string(43, ' ') << FIN_DE_FORMATO << " ║" << endl;
cout << TAB << "║ " << "(I) Metal || (W) Madera || (S) Piedra || (C) Andycoins"  << " ║" << endl;
cout << TAB << "╚════════════════════════════════════════════════════════╝" << endl;    

}


// ------------------------------------------------------------------------------------------------------------


int Mapa::cantidad_casilleros_transitables_disponibles(){

    return this -> casilleros_transitables_disponibles.obtener_cantidad();

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Mapa::agregar_material_en_coordenadas(Material* material, int coord_x, int coord_y){
    Estado_t estado = OK;

    if(se_puede_transitar(coord_x,coord_y)){
        if(!(casillero_esta_ocupado(coord_x, coord_y))){
            mapa[coord_x][coord_y] -> poner_material(material);
            int ind = obtener_indice_casillero_transitable(coord_x, coord_y);
            delete casilleros_transitables_disponibles.consulta(ind);
            casilleros_transitables_disponibles.baja(ind);

        }else estado = ERROR_CASILLERO_OCUPADO;

    }else estado = ERROR_CASILLERO_NO_TRANSITABLE;

    return estado;

}


// ------------------------------------------------------------------------------------------------------------


void Mapa::quitar_material_en_coordenadas(int coord_x, int coord_y){

    mapa[coord_x][coord_y]->destruir_material();

    // Agrego la coordenada a la lista de transitables desocupados
    Coordenadas* coord = new Coordenadas;
    *coord = {coord_x, coord_y};

    casilleros_transitables_disponibles.alta( coord, casilleros_transitables_disponibles.obtener_cantidad() );
}


// ------------------------------------------------------------------------------------------------------------


void Mapa::agregar_material_en_coordenada_transitable_aleatoria(Material* material){

    // Agarro una coordenada aleatoria de la lista
    int indice_coordenada_a_colocar = rand() % casilleros_transitables_disponibles.obtener_cantidad();
    Coordenadas* coord = casilleros_transitables_disponibles.consulta(indice_coordenada_a_colocar);

    // Posiciono el material
    mapa[coord -> coordenada_x][coord -> coordenada_y] -> poner_material(material);

    // Doy de baja
    delete casilleros_transitables_disponibles.consulta(indice_coordenada_a_colocar);
    casilleros_transitables_disponibles.baja(indice_coordenada_a_colocar);

}


// ------------------------------------------------------------------------------------------------------------


char Mapa::obtener_identificador_recurso_de_casillero( int coord_x, int coord_y){
    return this -> mapa[coord_x][coord_y] -> obtener_identificador_recurso_de_casillero();
}


// ------------------------------------------------------------------------------------------------------------


double Mapa::recolectar_recursos_casillero( int coord_x, int coord_y){
    return this -> mapa[coord_x][coord_y] -> recolectar_recursos();
}


// ------------------------------------------------------------------------------------------------------------


void Mapa::depositar_recurso_casillero(int coord_x, int coord_y){

    this -> mapa[coord_x][coord_y] -> depositar_recurso_casillero();

}

// ------------------------------------------------------------------------------------------------------------


Estado_t Mapa::verificar_coordenadas_construccion(int coord_x, int coord_y){
    Estado_t estado;

    if(coord_x < this -> cantidad_filas && coord_y < this -> cantidad_columnas){
        
        if(this -> se_puede_construir(coord_x, coord_y)){

            if(!(this -> casillero_esta_ocupado(coord_x, coord_y))){

                estado = OK;
            } else estado = ERROR_CASILLERO_OCUPADO;
        } else estado = ERROR_CASILLERO_NO_CONSTRUIBLE;
    }else estado = ERROR_POSICION_INEXISTENTE;

    return estado;
}


// ------------------------------------------------------------------------------------------------------------


Estado_t Mapa::verificar_coordenadas_demolicion(int coord_x, int coord_y, Jugador_t jugador){
    Estado_t estado;

    if(coord_x < this -> cantidad_filas && coord_y < this -> cantidad_columnas){
        
        if(this -> se_puede_construir(coord_x, coord_y)){

            if(this -> casillero_esta_ocupado(coord_x, coord_y)){

                if( this-> obtener_creador_edificio(coord_x, coord_y) == jugador){
                    estado = OK;
                }else estado = ERROR_EDIFICIO_AJENO;
            } else estado = ERROR_CASILLERO_VACIO;
        } else estado = ERROR_CASILLERO_NO_CONSTRUIBLE;
    }else estado = ERROR_POSICION_INEXISTENTE;

    return estado;
}


// ------------------------------------------------------------------------------------------------------------


Estado_t Mapa::verificar_coordenadas_ataque(int coord_x, int coord_y, Jugador_t jugador){
    Estado_t estado;

    if(coord_x < this -> cantidad_filas && coord_y < this -> cantidad_columnas){
        
        if(this -> se_puede_construir(coord_x, coord_y)){

            if(this -> casillero_esta_ocupado(coord_x, coord_y)){

                if( this-> obtener_creador_edificio(coord_x, coord_y) != jugador){
                    estado = OK;
                }else estado = ERROR_EDIFICIO_PROPIO;
            } else estado = ERROR_CASILLERO_VACIO;
        } else estado = ERROR_CASILLERO_NO_CONSTRUIBLE;
    }else estado = ERROR_POSICION_INEXISTENTE;

    return estado;
}


// ------------------------------------------------------------------------------------------------------------


Estado_t Mapa::verificar_coordenadas_reparacion(int coord_x, int coord_y, Jugador_t jugador){
    Estado_t estado;

    if(coord_x < this -> cantidad_filas && coord_y < this -> cantidad_columnas){
        
        if(this -> se_puede_construir(coord_x, coord_y)){

            if(this -> casillero_esta_ocupado(coord_x, coord_y)){

                if( this-> obtener_creador_edificio(coord_x, coord_y) == jugador){
                    estado = OK;
                }else estado = ERROR_EDIFICIO_AJENO;
            } else estado = ERROR_CASILLERO_VACIO;
        } else estado = ERROR_CASILLERO_NO_CONSTRUIBLE;
    }else estado = ERROR_POSICION_INEXISTENTE;

    return estado;
}


// ------------------------------------------------------------------------------------------------------------


Jugador_t Mapa::obtener_creador_edificio(int coord_x, int coord_y){
    
    Jugador_t jugador;

    mapa[coord_x][coord_y]->obtener_creador_edificio(jugador);

    return jugador;
}


// ------------------------------------------------------------------------------------------------------------


Coordenadas Mapa::obtener_coordenadas_casillero_transitable_aleatorio(){
    
    int coord_x, coord_y;
    Coordenadas aux;

    coord_x = rand() % cantidad_columnas;
    coord_y = rand() % cantidad_filas;

    while( !mapa[coord_x][coord_y] -> es_casillero_transitable()){
        coord_x = rand() % cantidad_columnas;
        coord_y = rand() % cantidad_filas;
    }

    aux.coordenada_x = coord_x;
    aux.coordenada_y = coord_y;

    return aux;  
}


// ------------------------------------------------------------------------------------------------------------


void Mapa::guardar_materiales_en_achivo( fstream &archivo_salida){

    for(int i = 0 ; i < cantidad_filas ; ++i){
        for(int j = 0 ; j < cantidad_columnas ; ++j){
            if( mapa[i][j] -> es_casillero_transitable() && mapa[i][j] -> esta_ocupado() && (!mapa[i][j] -> hay_jugador()) )
                archivo_salida << mapa[i][j] -> obtener_nombre_objeto_de_casillero() << " (" << i << ", " << j << ")" << endl;
        }
    }
}


