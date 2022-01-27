#include "juego.h"


// ------------------------------------------------------------------------------------------------------------


Juego::Juego(){

    srand( (unsigned int)time(NULL) );

    this -> jugador_ganador = false;
    this -> turno = 0;

    if( archivos.archivo_ubicaciones_vacio() )
        this -> partida_nueva = true;
    
    else this -> partida_nueva = false;

}


// ------------------------------------------------------------------------------------------------------------


void Juego::jugar(){

    if( partida_nueva ){

        int opcion;
        Estado_t estado;

        Andypolis andypolis(archivos.obtener_archivo_edificios(),
                            archivos.obtener_archivo_ubicaciones(),
                            archivos.obtener_archivo_mapa(),
                            archivos.obtener_archivo_materiales(),
                            true);

        
        estado = juego_nuevo(andypolis, opcion);

        if(opcion == COMENZAR_PARTIDA_PARTIDA_NUEVA && estado == OK){
            estado = procesar_juego(andypolis);
            
            if(estado == ESTADO_JUGADOR_GANADOR)
                archivos.generar_archivos_para_nueva_partida(andypolis);
        
            else archivos.guardar_cambios(andypolis);

        }else archivos.guardar_cambios_partida_nueva(andypolis);

    }else{

        Estado_t estado;

        Andypolis andypolis(archivos.obtener_archivo_edificios(),
                            archivos.obtener_archivo_ubicaciones(),
                            archivos.obtener_archivo_mapa(),
                            archivos.obtener_archivo_materiales(),
                            false);

        
        
        estado = procesar_juego(andypolis);
            
        if(estado == ESTADO_JUGADOR_GANADOR)
            archivos.generar_archivos_para_nueva_partida(andypolis);

        else archivos.guardar_cambios(andypolis);
    }

}


// ------------------------------------------------------------------------------------------------------------

Estado_t Juego::juego_nuevo(Andypolis& andypolis, int& opcion){
    
    opcion = 0;
   	Estado_t estado = OK;
    
    while(opcion != GUARDAR_SALIR_PARTIDA_NUEVA && opcion != COMENZAR_PARTIDA_PARTIDA_NUEVA){

       menu.mostrar_menu_partida_nueva();
       estado = menu.ingreso_menu();

       while( estado != OK){
            if(system(CLR_SCREEN));
            imprimir_error(estado);
            menu.mostrar_menu_partida_nueva();
            estado = menu.ingreso_menu();
       }

       opcion = menu.obtener_opcion_elegida();
        
       switch (opcion) {

        case MODIFICAR_EDIFICIO_POR_NOMBRE_PARTIDA_NUEVA:
            if(system(CLR_SCREEN));
            estado = modificar_edificio_por_nombre(andypolis);
            break;

        case LISTAR_TODOS_LOS_EDIFICIOS_PARTIDA_NUEVA:
            if(system(CLR_SCREEN));
            andypolis.listar_edificios_diccionario();
            break;

        case MOSTRAR_MAPA_PARTIDA_NUEVA: 
            if(system(CLR_SCREEN));
            andypolis.mostrar_mapa(0,0);
            break;

        case COMENZAR_PARTIDA_PARTIDA_NUEVA:
            if(system(CLR_SCREEN));
            estado = consultar_ubicacion_jugadroes(andypolis);
            if(system(CLR_SCREEN));
            if(estado == OK){
                cout << endl << TAB << NEGRITA << FONDO_COLOR_VERDE << MSJ_PARTIDA_NUEVA << FIN_DE_FORMATO <<endl;
                cout << endl << endl;
            }
            break;

        case GUARDAR_SALIR_PARTIDA_NUEVA:
            if(system(CLR_SCREEN));
            cout << endl << TAB << NEGRITA << FONDO_COLOR_AZUL << MSJ_DESPEDIDA << FIN_DE_FORMATO <<endl;
            cout << endl << endl;
            estado = PARTIDA_NUEVA_NO_INICIALIZADA;
            break;

        default: 
            estado = ERROR_NUMERO_OPCION_INVALIDA;
            break;
    }

    if( estado != OK && estado != PARTIDA_NUEVA_NO_INICIALIZADA){
        imprimir_error(estado);
        opcion = 0;
    }    

    }

    
    return estado;

}


// ------------------------------------------------------------------------------------------------------------


void Juego::sortear_jugadores(Jugador_t &jugador_A, Jugador_t &jugador_B){

    int primero = rand()%100; 

    if(primero < 50){
        jugador_A = JUGADOR_UNO;
        jugador_B = JUGADOR_DOS;
    }
    if(primero >= 50){
        jugador_A = JUGADOR_DOS;
        jugador_B = JUGADOR_UNO;
    }


}


// ------------------------------------------------------------------------------------------------------------


Estado_t Juego::procesar_juego(Andypolis& andypolis){

    int opcion = 0;
	Estado_t estado = OK;

    Jugador_t jugador_A = NADIE , jugador_B = NADIE;
    sortear_jugadores(jugador_A, jugador_B);
    
    while(opcion != GUARDAR_SALIR){
        
        if(!(turno%2))
            andypolis.lluvia_de_recursos();

        if(opcion != GUARDAR_SALIR){
            opcion = 0;
            while(opcion != GUARDAR_SALIR && opcion != FINALIZAR_TURNO){ 
                menu.mostrar_menu_jugador(jugador_A, andypolis);                
                estado = procesar_opcion(andypolis, jugador_A, opcion);
                if(estado != OK && estado != ESTADO_JUGADOR_GANADOR)
                    imprimir_error(estado);
                else if(estado == ESTADO_JUGADOR_GANADOR)
                    opcion = GUARDAR_SALIR; 

            }
        }

        if(opcion != GUARDAR_SALIR){
            opcion = 0;
            while(opcion != GUARDAR_SALIR && opcion != FINALIZAR_TURNO){
                menu.mostrar_menu_jugador(jugador_B, andypolis);
                estado = procesar_opcion(andypolis, jugador_B, opcion);
                if(estado != OK && estado != ESTADO_JUGADOR_GANADOR)
                    imprimir_error(estado);
                else if(estado == ESTADO_JUGADOR_GANADOR)
                    opcion = GUARDAR_SALIR; 
            }      
        }

    }

    return estado;

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Juego::procesar_opcion(Andypolis &andypolis, Jugador_t jugador, int& opcion){

    opcion = 0;
    Estado_t estado = OK;
    string str_edificio;
    string codigo_ingresado;

    estado = menu.ingreso_menu();

    while( estado != OK){
        imprimir_error(estado);
        menu.mostrar_menu_jugador(jugador,andypolis);
        estado = menu.ingreso_menu();
    }

    opcion = menu.obtener_opcion_elegida();

    switch (opcion) {

        case CONSTRUIR_EDIFICIO_POR_NOMBRE:
            if(system(CLR_SCREEN));
            andypolis.mostrar_mapa(0,0);
            estado = construir_edificio_por_nombre(andypolis, jugador);
            break;

        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            if(system(CLR_SCREEN));
            andypolis.listar_edificios_construidos(jugador);
            break;

        case DEMOLER_EDIFICIO_POR_COORD: 
            if(system(CLR_SCREEN));
            andypolis.mostrar_mapa(0,0);
            estado = demoler_edificio_por_coordenada(andypolis, jugador);
            break;

        case ATACAR_EDIFICIO_POR_COORD:
            if(system(CLR_SCREEN));
            andypolis.mostrar_mapa(0,0);
            estado = atacar_edificio_por_coordenada(andypolis, jugador);
            break;

        case REPARAR_EDIFICIO_POR_COORD:
            if(system(CLR_SCREEN));
            andypolis.mostrar_mapa(0,0);
            estado = reparar_edificio_por_coordenada(andypolis, jugador);
            break;
        
        case COMPRAR_BOMBAS: 
            if(system(CLR_SCREEN));
            estado = comprar_bombas(andypolis, jugador);
            break;

        case CONSULTAR_COORDENADA: 
            if(system(CLR_SCREEN));
            andypolis.mostrar_mapa(0,0);
            estado = consultar_coordenada(andypolis);
            break;
        
        case MOSTRAR_INVENTARIO:
            if(system(CLR_SCREEN));
            andypolis.mostrar_inventario(jugador);
            break;

        case MOSTRAR_OBJETIVOS:
            if(system(CLR_SCREEN));
            andypolis.mostrar_objetivos(jugador);
            break;

        case RECOLETAR_RECURSOS_PRODUCIDOS:
            if(system(CLR_SCREEN));
            andypolis.recolectar_recursos_jugador(jugador);
            break;

        case MOVERSE_A_UNA_COORD:
            if(system(CLR_SCREEN));
            andypolis.mostrar_mapa(0,0);
            estado = moverse_a_una_coord(andypolis, jugador);
            break;

        case FINALIZAR_TURNO:
            if(system(CLR_SCREEN));
            if(andypolis.gano_el_jugador(jugador)){
                menu.mostrar_pantalla_final(jugador);
                return ESTADO_JUGADOR_GANADOR;
            }
            andypolis.depositar_recursos_jugador(jugador);
            andypolis.agregar_energia_jugador(jugador, 20);
            ++turno;
            break;

        case GUARDAR_SALIR:
            if(system(CLR_SCREEN));
            cout << endl << TAB << NEGRITA << FONDO_COLOR_AZUL << MSJ_DESPEDIDA << FIN_DE_FORMATO <<endl;
            cout << endl << endl;
            break;

        default: 
            return ERROR_NUMERO_OPCION_INVALIDA;
    }

    return estado;
}


// ------------------------------------------------------------------------------------------------------------