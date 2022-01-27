#include <iostream>
#include "utilidades.h"



// -------------------------------------------------------------------------------------------


Estado_t comprar_bombas(Andypolis &andypolis, Jugador_t jugador){

    if( andypolis.obtener_energia_jugador(jugador) < 5)
        return ERROR_ENERGIA_INSUFICIENTE; 

    return andypolis.comprar_bombas(jugador);

}


// -------------------------------------------------------------------------------------------


Estado_t construir_edificio_por_nombre(Andypolis &andypolis, Jugador_t jugador){

    if(andypolis.obtener_energia_jugador(jugador) < 15) // deshardc
        return ERROR_ENERGIA_INSUFICIENTE;

    string nombre;
    string coord_x, coord_y;
    //Estado_t estado = OK;

    cout << TAB << SUBRAYADO << MSJ_INGRESO_EDIFICIO_CONSTRUIR << FIN_DE_FORMATO << endl;
    cout << "> ";
    getline(cin, nombre);
    if(!andypolis.esta_edificio(nombre))
        return ERROR_EDIFICIO_INEXISTENTE;

    
    cout << endl << TAB << SUBRAYADO << MSG_UBICACION_CONSTRUCCION_EDIFCIO << FIN_DE_FORMATO << endl;
    cout << "Coordenada x > "; getline(cin, coord_x);
    cout << endl << "Coordenada y > "; getline(cin, coord_y);

    if(!es_un_numero(coord_x) || !es_un_numero(coord_y))
        return ERROR_PAR_COORDENADAS_INVALIDAS;
     
    return andypolis.construir_edificio(nombre, stoi(coord_x), stoi(coord_y), jugador);
}


// -------------------------------------------------------------------------------------------


Estado_t modificar_edificio_por_nombre(Andypolis &andypolis){

    string nombre;
    string madera, metal, piedra;
    Estado_t estado = OK;

    cout << TAB << SUBRAYADO << MSJ_INGRESO_EDIFICIO_MODIFICAR << FIN_DE_FORMATO << endl;
    cout << "> ";
    getline(cin, nombre);
    if(!andypolis.esta_edificio(nombre))
        return ERROR_EDIFICIO_INEXISTENTE; // No tiene sentido seguir si esto sucede

    if(nombre == STR_OBELISCO)
        return ERROR_MODIFICAR_OBELISICO; // No tiene sentido seguir si esto sucede


    cout << endl << TAB << SUBRAYADO << MSJ_UBICACION_MODIFICAR_EDIFCIO << FIN_DE_FORMATO << endl;
    cout << "Cantidad de piedra > "; getline(cin, piedra);
    cout << endl <<  "Cantidad de madera > "; getline(cin, madera);
    cout << endl <<  "Cantidad de metal > "; getline(cin, metal);

    if(es_un_numero(piedra) && es_un_numero(madera) && es_un_numero(metal)){

        if( validar_cantidad_materiales(piedra, madera, metal) == OK ){
            andypolis.modificar_edificio(nombre, stoi(piedra), stoi(madera), stoi(metal));
        }else estado = ERROR_CANTIDAD_MATERIALES_INVALIDOS;
            
    }else estado = ERROR_MATERIALES_INVALIDOS;
        

    return estado;
}

// -------------------------------------------------------------------------------------------


Estado_t validar_cantidad_materiales(string piedra, string  madera, string metal){

    Estado_t estado = OK;

    if(stoi(piedra) > 50000 || stoi(madera) > 50000|| stoi(metal) > 50000)
        estado = ERROR_CANTIDAD_MATERIALES_INVALIDOS;
    
    if(stoi(piedra) < 0 || stoi(madera) < 0|| stoi(metal) < 0)
        estado = ERROR_CANTIDAD_MATERIALES_INVALIDOS;

    return estado;
}

// -------------------------------------------------------------------------------------------


Estado_t demoler_edificio_por_coordenada(Andypolis& andypolis, Jugador_t jugador){

    if(andypolis.obtener_energia_jugador(jugador) < 15)
        return ERROR_ENERGIA_INSUFICIENTE;

    string coord_x, coord_y;

    cout << TAB << SUBRAYADO << MSJ_UBICACION_DEMOLICION_EDIFCIO << FIN_DE_FORMATO << endl;
    cout << "Coordenada x > "; getline(cin, coord_x);
    cout << endl << "Coordenada y > "; getline(cin, coord_y); cout << endl;
    


    if(!es_un_numero(coord_x) || !es_un_numero(coord_y))
        return ERROR_PAR_COORDENADAS_INVALIDAS;


    return andypolis.destruir_edificio_de_coord(stoi(coord_x), stoi(coord_y), jugador);
}


// -------------------------------------------------------------------------------------------


Estado_t atacar_edificio_por_coordenada(Andypolis& andypolis, Jugador_t jugador){

    if(andypolis.obtener_energia_jugador(jugador) < 30) //DESHARCODEAR
        return ERROR_ENERGIA_INSUFICIENTE;


    string coord_x, coord_y;

    cout << TAB << SUBRAYADO << MSJ_UBICACION_ATACAR_EDIFCIO << FIN_DE_FORMATO << endl;
    cout << "Coordenada x > "; getline(cin, coord_x);
    cout << endl << "Coordenada y > "; getline(cin, coord_y); cout << endl;
    


    if(!es_un_numero(coord_x) || !es_un_numero(coord_y))
        return ERROR_PAR_COORDENADAS_INVALIDAS;


    return andypolis.atacar_edificio_de_coord(stoi(coord_x), stoi(coord_y), jugador);
}


// -------------------------------------------------------------------------------------------


Estado_t reparar_edificio_por_coordenada(Andypolis& andypolis, Jugador_t jugador){

    if(andypolis.obtener_energia_jugador(jugador) < 25)
        return ERROR_ENERGIA_INSUFICIENTE;

    string coord_x, coord_y;

    cout << TAB << SUBRAYADO << MSJ_UBICACION_REPARAR_EDIFCIO << FIN_DE_FORMATO << endl;
    cout << "Coordenada x > "; getline(cin, coord_x);
    cout << endl << "Coordenada y > "; getline(cin, coord_y); cout << endl;
    


    if(!es_un_numero(coord_x) || !es_un_numero(coord_y))
        return ERROR_PAR_COORDENADAS_INVALIDAS;


    return andypolis.reparar_edificio_de_coord(stoi(coord_x), stoi(coord_y), jugador);
}


// -------------------------------------------------------------------------------------------


Estado_t consultar_coordenada(const Andypolis &andypolis){

    Estado_t estado = OK;
    string coord_x, coord_y;

    cout << TAB << SUBRAYADO << MSJ_UBICACION_CONSULTAR_EDIFCIO << FIN_DE_FORMATO << endl;
    cout << "Coordenada x > "; getline(cin, coord_x);
    cout << endl << "Coordenada y > "; getline(cin, coord_y); cout << endl;


    if(!es_un_numero(coord_x) || !es_un_numero(coord_y))
        return ERROR_PAR_COORDENADAS_INVALIDAS;


    estado = andypolis.consultar_casillero_de_mapa(stoi(coord_x),stoi(coord_y));

    return estado;

}


// -------------------------------------------------------------------------------------------


Estado_t moverse_a_una_coord(Andypolis &andypolis, Jugador_t jugador){

    Estado_t estado = OK;
    string coord_x, coord_y;

    cout << TAB << SUBRAYADO <<MSJ_UBICACION_MOVERSE << FIN_DE_FORMATO << endl;
    cout << "Coordenada x > "; getline(cin, coord_x);
    cout << endl << "Coordenada y > "; getline(cin, coord_y); cout << endl;


    if(!es_un_numero(coord_x) || !es_un_numero(coord_y))
        return ERROR_PAR_COORDENADAS_INVALIDAS;


    estado = andypolis.moverse_a_una_coord(stoi(coord_x),stoi(coord_y), jugador);

    return estado;

}


// -------------------------------------------------------------------------------------------


void crear_archivo_vacio(string ruta_archivo, fstream& archivo){

    archivo.open(ruta_archivo, ios::out);
    archivo.close();
    archivo.open(ruta_archivo, ios::in);
}


// -------------------------------------------------------------------------------------------


bool archivo_esta_vacio(fstream& archivo){

    if(archivo.peek() == fstream::traits_type::eof())
        return true;

    else return false;

}


// -------------------------------------------------------------------------------------------


Estado_t consultar_ubicacion_jugadroes(Andypolis& andypolis){

    string coord_x, coord_y, jugador_string;

    andypolis.mostrar_mapa(0,0);

    cout << TAB << SUBRAYADO << "Ingrese el jugador que desea posicionar:" << FIN_DE_FORMATO << endl;
    cout << "Numero del jugador > "; getline(cin, jugador_string); 

    if( !es_un_numero(jugador_string) )
        return ERROR_ENTRADA_INVALIDA;

    if( stoi(jugador_string)-1 >= 2 && stoi(jugador_string)-1 <= 0 )
        return ERROR_JUGADOR_ELEGIDO_INCORRECTO;
    
    if( stoi(jugador_string)-1 == JUGADOR_UNO){
        cout << TAB << SUBRAYADO << "Ingrese la coordenadas del jugador 1:" << FIN_DE_FORMATO << endl;
        cout << "Coordenada x > "; getline(cin, coord_x);
        cout << endl << "Coordenada y > "; getline(cin, coord_y); cout << endl;
    
        if(!es_un_numero(coord_x) || !es_un_numero(coord_y))
            return ERROR_PAR_COORDENADAS_INVALIDAS;

        if(stoi(coord_x) > andypolis.obtener_columnas_mapa() || stoi(coord_y) > andypolis.obtener_filas_mapa())
            return ERROR_POSICION_INEXISTENTE;



        andypolis.posicionar_jugador( stoi(coord_x), stoi(coord_y), JUGADOR_UNO);

        cout << TAB << SUBRAYADO << "Ingrese la coordenadas del jugador 2:" << FIN_DE_FORMATO << endl;
        cout << "Coordenada x > "; getline(cin, coord_x);
        cout << endl << "Coordenada y > "; getline(cin, coord_y); cout << endl;
    
        if(!es_un_numero(coord_x) || !es_un_numero(coord_y))
            return ERROR_PAR_COORDENADAS_INVALIDAS;

        if(stoi(coord_x) > andypolis.obtener_columnas_mapa()  || stoi(coord_y) > andypolis.obtener_filas_mapa())
            return ERROR_POSICION_INEXISTENTE;



        return andypolis.posicionar_jugador(stoi(coord_x), stoi(coord_y), JUGADOR_DOS);
    }

    if( stoi(jugador_string)-1 == JUGADOR_DOS){
        cout << TAB << SUBRAYADO << "Ingrese la coordenadas del jugador 2:" << FIN_DE_FORMATO << endl;
        cout << "Coordenada x > "; getline(cin, coord_x);
        cout << endl << "Coordenada y > "; getline(cin, coord_y); cout << endl;
    
        if(!es_un_numero(coord_x) || !es_un_numero(coord_y))
            return ERROR_PAR_COORDENADAS_INVALIDAS;

        if(stoi(coord_x) > andypolis.obtener_columnas_mapa()  || stoi(coord_y) > andypolis.obtener_filas_mapa())
            return ERROR_POSICION_INEXISTENTE;



        andypolis.posicionar_jugador( stoi(coord_x), stoi(coord_y), JUGADOR_DOS);

        cout << TAB << SUBRAYADO << "Ingrese la coordenadas del jugador 1:" << FIN_DE_FORMATO << endl;
        cout << "Coordenada x > "; getline(cin, coord_x);
        cout << endl << "Coordenada y > "; getline(cin, coord_y); cout << endl;
    
        if(!es_un_numero(coord_x) || !es_un_numero(coord_y))
            return ERROR_PAR_COORDENADAS_INVALIDAS;
        
        if(stoi(coord_x) > andypolis.obtener_columnas_mapa()  || stoi(coord_y) > andypolis.obtener_filas_mapa())
            return ERROR_POSICION_INEXISTENTE;



        return andypolis.posicionar_jugador(stoi(coord_x), stoi(coord_y), JUGADOR_UNO);
    }

    return ERROR_JUGADOR_ELEGIDO_INCORRECTO;
}