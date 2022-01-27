#ifndef MENU_H
#define MENUH

#include <iostream>
#include <string>
#include "manejo_archivos.h"
#include "herramientas.h"
#include "error.h"


using namespace std;

const string ARTE_PANTALLA_FINAL = R"(
         __
 _(\    |@@|
(__/\__ \--/ __
   \___|----|  |   __
       \ }{ /\ )_ / _\
       /\__/\ \__O (__
      (--/\--)    \__/
      _)(  )(_
     `---''---`)";

const string MSJ_FELICITACIONES_FINAL = R"(
 _______  _______  ___      ___   _______  ___   _______  _______  _______  ___   _______  __    _  _______  _______ 
|       ||       ||   |    |   | |       ||   | |       ||   _   ||       ||   | |       ||  |  | ||       ||       |
|    ___||    ___||   |    |   | |       ||   | |_     _||  |_|  ||       ||   | |   _   ||   |_| ||    ___||  _____|
|   |___ |   |___ |   |    |   | |       ||   |   |   |  |       ||       ||   | |  | |  ||       ||   |___ | |_____ 
|    ___||    ___||   |___ |   | |      _||   |   |   |  |       ||      _||   | |  |_|  ||  _    ||    ___||_____  |
|   |    |   |___ |       ||   | |     |_ |   |   |   |  |   _   ||     |_ |   | |       || | |   ||   |___  _____| |
|___|    |_______||_______||___| |_______||___|   |___|  |__| |__||_______||___| |_______||_|  |__||_______||_______|)";

const string MSJ_MENU_BIENVENIDA_JUGADOR_UNO = R"(
     ___  __   __  _______  _______  ______   _______  ______      ____  
    |   ||  | |  ||       ||   _   ||      | |       ||    _ |    |    | 
    |   ||  | |  ||    ___||  |_|  ||  _    ||   _   ||   | ||     |   | 
    |   ||  |_|  ||   | __ |       || | |   ||  | |  ||   |_||_    |   | 
 ___|   ||       ||   ||  ||       || |_|   ||  |_|  ||    __  |   |   | 
|       ||       ||   |_| ||   _   ||       ||       ||   |  | |   |   | 
|_______||_______||_______||__| |__||______| |_______||___|  |_|   |___|)";

const string MSJ_MENU_BIENVENIDA_JUGADOR_DOS = R"(
     ___  __   __  _______  _______  ______   _______  ______      _______ 
    |   ||  | |  ||       ||   _   ||      | |       ||    _ |    |       |
    |   ||  | |  ||    ___||  |_|  ||  _    ||   _   ||   | ||    |____   |
    |   ||  |_|  ||   | __ |       || | |   ||  | |  ||   |_||_    ____|  |
 ___|   ||       ||   ||  ||       || |_|   ||  |_|  ||    __  |  | ______|
|       ||       ||   |_| ||   _   ||       ||       ||   |  | |  | |_____ 
|_______||_______||_______||__| |__||______| |_______||___|  |_|  |_______|)";

const string MSJ_MENU_BIENVENIDA_PARTIDA_NUEVA = R"(

 _______  ___   _______  __    _  __   __  _______  __    _  ___   ______   _______  _______ 
|  _    ||   | |       ||  |  | ||  | |  ||       ||  |  | ||   | |      | |       ||       |
| |_|   ||   | |    ___||   |_| ||  |_|  ||    ___||   |_| ||   | |  _    ||   _   ||  _____|
|       ||   | |   |___ |       ||       ||   |___ |       ||   | | | |   ||  | |  || |_____ 
|  _   | |   | |    ___||  _    ||       ||    ___||  _    ||   | | |_|   ||  |_|  ||_____  |
| |_|   ||   | |   |___ | | |   | |     | |   |___ | | |   ||   | |       ||       | _____| |
|_______||___| |_______||_|  |__|  |___|  |_______||_|  |__||___| |______| |_______||_______|
                                  _______                                                                         
                                 |   _   |                                                                        
                                 |  |_|  |                                                                        
                                 |       |                                                                        
                                 |       |                                                                        
                                 |   _   |                                                                        
                                 |__| |__|                                                                        
 _______  __    _  ______   __   __  _______  _______  ___      ___   _______                
|   _   ||  |  | ||      | |  | |  ||       ||       ||   |    |   | |       |               
|  |_|  ||   |_| ||  _    ||  |_|  ||    _  ||   _   ||   |    |   | |  _____|               
|       ||       || | |   ||       ||   |_| ||  | |  ||   |    |   | | |_____                
|       ||  _    || |_|   ||_     _||    ___||  |_|  ||   |___ |   | |_____  |               
|   _   || | |   ||       |  |   |  |   |    |       ||       ||   |  _____| |               
|__| |__||_|  |__||______|   |___|  |___|    |_______||_______||___| |_______|               
)";


const string MSJ_MENU_OPCION_1 = "1. Construir edificio por nombre";
const string MSJ_MENU_OPCION_2 = "2. Listar mis edificios construidos";
const string MSJ_MENU_OPCION_3 = "3. Demoler un edificio por coordenada";
const string MSJ_MENU_OPCION_4 = "4. Atacar un edificio por coordenada";
const string MSJ_MENU_OPCION_5 = "5. Reparar un edificio por coordenada";
const string MSJ_MENU_OPCION_6 = "6. Comprar bombas";
const string MSJ_MENU_OPCION_7 = "7. Consultar coordenadas";
const string MSJ_MENU_OPCION_8 = "8. Mostrar inventario";
const string MSJ_MENU_OPCION_9 = "9. Mostrar objetivos";
const string MSJ_MENU_OPCION_10 = "10. Recolectar recursos producidos";
const string MSJ_MENU_OPCION_11 = "11. Moverse a una coordenada";
const string MSJ_MENU_OPCION_12 = "12. Finalizar turno";
const string MSJ_MENU_OPCION_13 = "13. Guardar y salir";

const string MSJ_MENU_PARTIDA_NUEVA_OPCION_1 = "1. Modificar edificio por nombre";
const string MSJ_MENU_PARTIDA_NUEVA_OPCION_2 = "2. Listar todos los edificos";
const string MSJ_MENU_PARTIDA_NUEVA_OPCION_3 = "3. Mostrar mapa";
const string MSJ_MENU_PARTIDA_NUEVA_OPCION_4 = "4. Comenzar partida";
const string MSJ_MENU_PARTIDA_NUEVA_OPCION_5 = "5. Guardar y salir";

const string MSJ_MENU_INGRESO_OPCION = "Elija una opcion";


const string MSJ_INGRESO_EDIFICIO_DEMOLER = "Ingresa el nombre del edificio a demoler:";
const string MSJ_DESPEDIDA = "¡Hasta la proxima!";
const string MSJ_PARTIDA_NUEVA = "¡Comienza una nueva partida!";

class Menu{

private:

    // Atributos
    string ingreso_usuario;
    int opcion_elegida;

public:

    // Metodos

    // pre: -
    // pos: Constructor por default
    Menu();

    // pre: -
    // pos: Destructor
    ~Menu(){};

    // pre:
    // pos: obtiene la opcion elegida por el usuario
    int obtener_opcion_elegida();

    // pre: - 
    // pos: muestra el menu
    void mostrar_menu_jugador(Jugador_t jugador, Andypolis& andypolis);


    // pre: - 
    // pos: muestra el menu de la partida nueva en caso de tener texto de ubicaciones vacio
    void mostrar_menu_partida_nueva();

    // pre: -
    // pos: muestra una pantalla final felicitando al ganador
    void mostrar_pantalla_final(Jugador_t jugador);

    // pre: -
    // pos: Verifica que la opcion ingresada este dentro del rango (min,max)
    bool verificar_opcion_elegida_en_rango(int min, int max);

    // pre: -
    // pos: Valida la opcion ingresada por el usuario
    Estado_t ingreso_menu();

};


#endif // MENU_H