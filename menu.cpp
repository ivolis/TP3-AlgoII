#include "menu.h"


// ------------------------------------------------------------------------------------------------------------


Menu::Menu(){

    this -> ingreso_usuario = " ";
    this -> opcion_elegida = 0;

}


// ------------------------------------------------------------------------------------------------------------


void Menu::mostrar_menu_jugador(Jugador_t jugador, Andypolis& andypolis){

    string FONDO = "";

    if(jugador == JUGADOR_UNO){
        cout << TAB << NEGRITA << MSJ_MENU_BIENVENIDA_JUGADOR_UNO << FIN_DE_FORMATO <<endl;
        FONDO = FONDO_COLOR_ROSA;
    }
    else if(jugador == JUGADOR_DOS){
        cout << TAB << NEGRITA << MSJ_MENU_BIENVENIDA_JUGADOR_DOS << FIN_DE_FORMATO <<endl;
        FONDO = FONDO_COLOR_PURPURA_OSCURO;
    }

    cout << TAB << "╔════════════════════════════════════════╗" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_1 << string(6, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_2 << string(3, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_3 << string(1, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_4 << string(2, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_5 << string(1, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_6 << string(21, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_7 << string(14, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_8 << string(17, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_9 << string(18, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_10 << string(4, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_11 << string(10, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_12 << string(19, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_13 << string(19, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "╚════════════════════════════════════════╝" << endl;

}


// ------------------------------------------------------------------------------------------------------------


void Menu::mostrar_menu_partida_nueva(){

    string FONDO = "";
    
    cout << TAB << NEGRITA << MSJ_MENU_BIENVENIDA_PARTIDA_NUEVA << FIN_DE_FORMATO <<endl;
    FONDO = FONDO_COLOR_ANARANJADO;

    cout << TAB << "╔════════════════════════════════════════╗" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_PARTIDA_NUEVA_OPCION_1 << string(6, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_PARTIDA_NUEVA_OPCION_2 << string(10, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_PARTIDA_NUEVA_OPCION_3 << string(23, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_PARTIDA_NUEVA_OPCION_4 << string(19, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_PARTIDA_NUEVA_OPCION_5 << string(20, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "╚════════════════════════════════════════╝" << endl;

}


// ------------------------------------------------------------------------------------------------------------


void Menu::mostrar_pantalla_final(Jugador_t jugador){

    cout << NEGRITA << TAB << MSJ_FELICITACIONES_FINAL << FIN_DE_FORMATO << endl;
    if(jugador == JUGADOR_UNO)
        cout << NEGRITA << TAB << TAB << MSJ_MENU_BIENVENIDA_JUGADOR_UNO << FIN_DE_FORMATO << endl;
    else if(jugador == JUGADOR_DOS)
        cout << NEGRITA << TAB << TAB << MSJ_MENU_BIENVENIDA_JUGADOR_DOS << ARTE_PANTALLA_FINAL << FIN_DE_FORMATO << endl;
    
    cout << endl << endl;

    cout << TAB << TAB << "¡Muchas gracias por jugar! Esperamos que lo hayan disfrutado ♥ " << endl << endl
    << TAB << TAB << TAB << TAB << "# Ivan Lisman (a.k.a Lazurro)" << endl
    << TAB << TAB << TAB << TAB << "# Gonzalo Puy (a.k.a Gona)" << endl
    << TAB << TAB << TAB << TAB << "# Maximiliano Pintos (a.k.a El massi)" << endl;

}


// ------------------------------------------------------------------------------------------------------------


int Menu::obtener_opcion_elegida(){

    return this -> opcion_elegida;
}


// ------------------------------------------------------------------------------------------------------------


bool Menu::verificar_opcion_elegida_en_rango(int min, int max){

    if( this -> opcion_elegida < min || this -> opcion_elegida > max )
        return false;

    else return true;
}   


// ------------------------------------------------------------------------------------------------------------

Estado_t Menu::ingreso_menu(){

    Estado_t estado = OK;

    cout << TAB << SUBRAYADO << MSJ_MENU_INGRESO_OPCION<< FIN_DE_FORMATO <<endl;
    cout << '>' << ESPACIO; getline(cin, ingreso_usuario); cout << FIN_DE_FORMATO;

    if( !es_un_numero(ingreso_usuario) )
        return ERROR_ENTRADA_INVALIDA;

    opcion_elegida = stoi(ingreso_usuario);

    return estado;
}