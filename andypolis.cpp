#include <iostream>
#include "andypolis.h"


// ------------------------------------------------------------------------------------------------------------


Andypolis::Andypolis(fstream& archivo_edif, fstream& archivo_ubics, fstream& archivo_mapa, fstream& archivo_mats, bool partida_nueva)
: mapa(archivo_mapa){

    // cuando venga vacio va a haber que meter una logica por aca
    cargar_informacion_jugadores();
    cargar_diccionario(archivo_edif);
    if(!partida_nueva)
        cargar_ubicaciones(archivo_ubics);

    cargar_inventarios(archivo_mats);
 
}


// ------------------------------------------------------------------------------------------------------------


Andypolis::~Andypolis(){}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::cargar_informacion_jugadores(){

    /*
    this -> jugador_uno.asignar_identificador(IDENTIFICADOR_JUGADOR_UNO);
    this -> jugador_uno.asignar_numero_jugador(JUGADOR_UNO);
    this -> jugador_uno.sortear_objetivos_secundarios();
    this -> jugador_uno.crear_grafo(mapa);

    this -> jugador_dos.asignar_identificador(IDENTIFICADOR_JUGADOR_DOS);
    this -> jugador_dos.asignar_numero_jugador(JUGADOR_DOS);
    this -> jugador_dos.sortear_objetivos_secundarios();
    this -> jugador_dos.crear_grafo(mapa);
    */

    this -> jugadores[POS_JUGADOR_UNO].asignar_identificador(IDENTIFICADOR_JUGADOR_UNO);
    this -> jugadores[POS_JUGADOR_UNO].asignar_numero_jugador(JUGADOR_UNO);
    this -> jugadores[POS_JUGADOR_UNO].sortear_objetivos_secundarios();
    this -> jugadores[POS_JUGADOR_UNO].crear_grafo(mapa);

    this -> jugadores[POS_JUGADOR_DOS].asignar_identificador(IDENTIFICADOR_JUGADOR_DOS);
    this -> jugadores[POS_JUGADOR_DOS].asignar_numero_jugador(JUGADOR_DOS);
    this -> jugadores[POS_JUGADOR_DOS].sortear_objetivos_secundarios();
    this -> jugadores[POS_JUGADOR_DOS].crear_grafo(mapa);

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::cargar_inventarios(fstream& archivo_mats){

    string linea_leida;
    
    while(getline(archivo_mats, linea_leida)){

        Parser parser(linea_leida);
        Material* material_leido_uno = parser.procesar_entrada_material(JUGADOR_UNO);
        jugadores[POS_JUGADOR_UNO].agregar_material_al_inventario(material_leido_uno);
        Material* material_leido_dos = parser.procesar_entrada_material(JUGADOR_DOS);
        jugadores[POS_JUGADOR_DOS].agregar_material_al_inventario(material_leido_dos);
        
    }
}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::cargar_diccionario(fstream& archivo_edif){

    string linea_leida;

    while(getline(archivo_edif, linea_leida)){
        
        Parser parser(linea_leida);

        Datos_edificio* dato = parser.procesar_entrada_edificio();

        diccionario.insertar(dato, parser.nombre_edificio());
    }
}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::cargar_ubicaciones(fstream& archivo_ubics){

    string linea_leida;
    Estado_t estado = OK;
    Estado_t estado_edificios = OK;
    Estado_t estado_materiales = OK;
    streampos pos_inicial_archivo = 0;

    getline(archivo_ubics,linea_leida); // Leo la primer linea del archivo ubicaciones
    Parser parser(linea_leida);

    if(parser.nombre_elemento_ubicaciones() != "1"){
        
        // Si es distinto de 1 significa que hay materiales en el archivo ubicaciones
        // Entonces:

        archivo_ubics.seekg(pos_inicial_archivo); // Vuevlo a colocar el cursor de lectura en el inicio.
        estado_materiales = cargar_materiales_mapa(archivo_ubics);
        estado_edificios = cargar_edificios_jugador(archivo_ubics);
    }else{

        // Si la primera linea es la posicion de un jugador, entonces no hay materiales en el archivo ubicaciones.
        // Por ende:

        archivo_ubics.seekg(pos_inicial_archivo); // Vuelvo a colocar el cursor de lectura al inicio.
        estado_edificios = cargar_edificios_jugador(archivo_ubics);
    }

    if (estado_materiales != OK){
        estado = estado_materiales;
    } else if (estado_edificios != OK){
        estado = estado_edificios;
    }

    return estado;
}


// ------------------------------------------------------------------------------------------------------------

Estado_t Andypolis::cargar_materiales_mapa(fstream& archivo_ubics){//, streampos pos){

    Estado_t estado = OK;
    string linea_leida;
    bool jugador_encontrado = false;
    streampos nueva_pos = 0; //Lo inicializo porque sino tira que puede no estar inicializado (Creo)

    //archivo_ubics.seekg(pos);

    while(!jugador_encontrado){
        
        getline(archivo_ubics, linea_leida);
        Parser parser(linea_leida);

        if(parser.nombre_elemento_ubicaciones() != "1"){
            int coord_x = parser.obtener_coordenada_x();
            int coord_y = parser.obtener_coordenada_y();
            Material* mat = parser.procesar_entrada_ubicaciones_materiales();
            estado = mapa.agregar_material_en_coordenadas(mat, coord_x, coord_y);
            nueva_pos = archivo_ubics.tellg(); //Me guardo la pos del cursor ACTUAL.
        }else{
            jugador_encontrado = true;
        }

    }

    //nueva_pos tiene la posicion del cursor justo para que lo proximo que lea sea el jugador 1.
    archivo_ubics.seekg(nueva_pos);
    
    return estado;

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::cargar_edificios_jugador(fstream& archivo_ubics){
    //Este metodo deberiamos renombrarlo y ponerle tipo "cargar_edificios_y_jugadores" no ?
    // Sino, lo que puedo hacer es modularizarlo, haciendo otro metodo que lo unico que haga sea cargar los edificios y lo llamaria
    //donde dice (*). Y podria pasarle solo la linea leida. 
    //...Pienso....
    // No lo hago ahora porque el tema de nombres de metodos y etc me parece mejor discutirlo con el grupo (re pajero jaja)

    Estado_t estado = OK;
    string linea_leida;
    bool fin_jugador_1 = false;
    streampos pos_archivo = 0; //Lo inicializo porque sino tira que puede no estar inicializado (Creo)

    while(!fin_jugador_1){

        getline(archivo_ubics, linea_leida);
        Parser parser(linea_leida);

        if( parser.nombre_elemento_ubicaciones() == "1"){
            posicionar_jugador(parser.obtener_coordenada_x(),parser.obtener_coordenada_y(), JUGADOR_UNO);
        }else if(parser.nombre_elemento_ubicaciones() == "2"){
            posicionar_jugador(parser.obtener_coordenada_x(),parser.obtener_coordenada_y(), JUGADOR_DOS);
            pos_archivo = archivo_ubics.tellg();
            fin_jugador_1 = true;
        }else{
            //(*)
            int coordenada_x = parser.obtener_coordenada_x();
            int coordenada_y = parser.obtener_coordenada_y();
            estado = mapa.asignar_edificio_en_coord(parser.procesar_entrada_ubicaciones_edificios(JUGADOR_UNO), coordenada_x, coordenada_y);
            cargar_edificio_a_jugador(parser.nombre_elemento_ubicaciones(), parser.obtener_identificador_edificio_ubicaciones(), coordenada_x, coordenada_y, JUGADOR_UNO);
        }

    }

    archivo_ubics.seekg(pos_archivo); // Esto lo deja justo para leer lo que sigue al "2 (420, 69)" jugador 2

    while(getline(archivo_ubics, linea_leida)){ // Se que todo lo que viene despues hasta eof son edificios del jugador 2.

        Parser parser(linea_leida);
        //(*)
        int coordenada_x = parser.obtener_coordenada_x();
        int coordenada_y = parser.obtener_coordenada_y();
        estado = mapa.asignar_edificio_en_coord(parser.procesar_entrada_ubicaciones_edificios(JUGADOR_DOS), coordenada_x, coordenada_y);
        cargar_edificio_a_jugador(parser.nombre_elemento_ubicaciones(), parser.obtener_identificador_edificio_ubicaciones(), coordenada_x, coordenada_y, JUGADOR_DOS);
    }

    return estado;

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::posicionar_jugador(int coord_x, int coord_y, Jugador_t jugador){

    Estado_t estado = OK;
    jugadores[jugador].asignar_ubicacion_jugador(coord_x, coord_y);
    estado = mapa.posicionar_jugador(coord_x,coord_y,jugador);
    


    return estado;

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::eliminar_posicion_jugador(Jugador_t jugador){

    Estado_t estado = OK;
    estado = mapa.eliminar_posicion_jugador(jugadores[jugador].obtener_ubicacion().coordenada_x ,jugadores[jugador].obtener_ubicacion().coordenada_y);

    return estado;

}

// ------------------------------------------------------------------------------------------------------------


void Andypolis::cargar_edificio_a_jugador(string nombre, char identificador, int coord_x, int coord_y, Jugador_t jugador){
  
    int vida = 0;

    if(nombre == STR_MINA || nombre == STR_FABRICA)
        vida = 100;
    else
        vida = 50;

    jugadores[jugador].agregar_edificio(nombre, identificador, vida, coord_x, coord_y);
    
}


// ------------------------------------------------------------------------------------------------------------


double Andypolis::obtener_energia_jugador(Jugador_t jugador){

   return jugadores[jugador].obtener_energia();

}


// ------------------------------------------------------------------------------------------------------------

void Andypolis::agregar_energia_jugador(Jugador_t jugador, double energia){

   jugadores[jugador].agregar_energia(energia);

}

// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::comprar_bombas(Jugador_t jugador){

    Estado_t estado = OK;

    estado = jugadores[jugador].comprar_bombas();    

    return estado;
}


// ------------------------------------------------------------------------------------------------------------


bool Andypolis::esta_edificio(string nombre){

    return diccionario.buscar(nombre);
}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::construir_edificio(string nombre, int coord_x, int coord_y, Jugador_t jugador){

    Estado_t estado;
 
    if((estado = mapa.verificar_coordenadas_construccion(coord_x, coord_y)) != OK)
        return estado; //Si las coordenadas tienen algun problema no tiene sentido continuar.

    
        
    if( (estado = jugadores[jugador].verificar_condiciones_construccion(nombre, diccionario)) != OK )
        return estado;

    if( (estado = consultar_construccion_edificio()) != OK)
        return estado;

    if(estado == OK){
        string linea = construir_string_edificio(nombre, coord_x, coord_y);
        Parser parser(linea);
        estado = mapa.asignar_edificio_en_coord(parser.procesar_entrada_ubicaciones_edificios(jugador), coord_x, coord_y);
        cargar_edificio_a_jugador(parser.nombre_elemento_ubicaciones(), parser.obtener_identificador_edificio_ubicaciones(), coord_x, coord_y, jugador);
        jugadores[jugador].restar_materiales_construccion(nombre, diccionario);
        jugadores[jugador].restar_energia((double)15); //desharcodear
        cout<<endl<<TAB<<NEGRITA<<FONDO_COLOR_VERDE<< "¡Se construyo " << nombre << " exitosamente!" <<FIN_DE_FORMATO<<endl;
    }
    
    return estado;
}


// -------------------------------------------------------------------------------------------


Estado_t Andypolis::consultar_construccion_edificio(){

    string opcion;
    if(system(CLR_SCREEN));
    cout << "Cumple con todos los requerimientos para construir el edificio"  << endl;
    cout <<  SUBRAYADO << "Desea usted continuar?[ si / no ]" << FIN_DE_FORMATO << endl;
    getline(cin, opcion);
 
    return ( opcion.compare("si") !=0 )? ERROR_CONSTRUCCION_CANCELADA : OK;

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::modificar_edificio(string nombre, int piedra_nuevo , int madera_nuevo, int metal_nuevo){



    diccionario.consultar(nombre) -> obtener_dato() -> modificar_costo_piedra(piedra_nuevo);
    diccionario.consultar(nombre) -> obtener_dato() -> modificar_costo_madera(madera_nuevo);
    diccionario.consultar(nombre) -> obtener_dato() -> modificar_costo_metal(metal_nuevo);
    
    cout<<endl<<TAB<<NEGRITA<<FONDO_COLOR_VERDE<< "¡Se modifico " << nombre << " exitosamente!" <<FIN_DE_FORMATO<<endl;
}



// ------------------------------------------------------------------------------------------------------------


string Andypolis::construir_string_edificio(string nombre, int coord_x, int coord_y){

    string linea;

    linea.append(nombre);
    linea.append(ESPACIO);
    linea.append("(");
    linea.append(to_string(coord_x));
    linea.append(", ");
    linea.append(to_string(coord_y));
    linea.append(")");

    return linea;
}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::destruir_edificio_de_coord(int coord_x, int coord_y, Jugador_t jugador){

    Estado_t estado;
    string nombre_edificio;

    if((estado = mapa.verificar_coordenadas_demolicion(coord_x, coord_y, jugador)) != OK)
        return estado; //Si las coordenadas tienen algun problmea no tiene sentido continuar.

    nombre_edificio = mapa.obtener_nombre_objeto_de_casillero_ocupado(coord_x, coord_y);
    estado = mapa.destruir_edificio_en_coord(coord_x, coord_y);
    jugadores[jugador].demoler_edificio(nombre_edificio, diccionario, coord_x, coord_y);
    
    cout<<endl<<TAB<<NEGRITA<<FONDO_COLOR_VERDE<< "¡Se demolio " << nombre_edificio << " exitosamente!" <<FIN_DE_FORMATO<<endl;

    return estado;
}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::atacar_edificio_de_coord(int coord_x, int coord_y, Jugador_t jugador){

    Estado_t estado;
    string nombre_edificio;
    int posicion_edificio, orden_edificio;

    if((estado = mapa.verificar_coordenadas_ataque(coord_x, coord_y, jugador)) != OK)
        return estado; //Si las coordenadas tienen algun problmea no tiene sentido continuar.

    if(!jugadores[jugador].obtener_cantidad_bombas()){
        return estado = ERROR_BOMBAS_INSUFICIENTES;
    }
    else {
        nombre_edificio = mapa.obtener_nombre_objeto_de_casillero_ocupado(coord_x, coord_y);
        posicion_edificio = jugadores[jugador].buscar_edificio_por_nombre(nombre_edificio);
        orden_edificio = jugadores[jugador].buscar_posicion_coordenadas( posicion_edificio, coord_x, coord_y);


        if( jugadores[!jugador].obtener_vida_edificio(posicion_edificio, orden_edificio) == 100 ){

            jugadores[!jugador].restar_vida_edificio(posicion_edificio, orden_edificio);

            cout<<endl<<TAB<<NEGRITA<<FONDO_COLOR_VERDE<< "¡Se ataco el/la " << nombre_edificio << " exitosamente!" <<FIN_DE_FORMATO<<endl;

        }
        else{
            jugadores[!jugador].destruir_edificio(nombre_edificio, diccionario, coord_x, coord_y);
            estado = mapa.destruir_edificio_en_coord(coord_x, coord_y);

            cout<<endl<<TAB<<NEGRITA<<FONDO_COLOR_VERDE<< "¡Se destruyo el/la " << nombre_edificio << " del jugador "<< (!jugador)+1 << "!" << FIN_DE_FORMATO <<endl;
        }

        jugadores[jugador].restar_bombas();
        jugadores[jugador].aumentar_bombas_usadas();
        jugadores[jugador].restar_energia(30);
        }
    
    return estado;
}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::reparar_edificio_de_coord(int coord_x, int coord_y, Jugador_t jugador){

    Estado_t estado;
    string nombre_edificio;
    int posicion_edificio, orden_edificio;

    if((estado = mapa.verificar_coordenadas_reparacion(coord_x, coord_y, jugador)) != OK)
        return estado; //Si las coordenadas tienen algun problmea no tiene sentido continuar.
        
    
    nombre_edificio = mapa.obtener_nombre_objeto_de_casillero_ocupado(coord_x, coord_y);
    posicion_edificio = jugadores[jugador].buscar_edificio_por_nombre(nombre_edificio);
    orden_edificio = jugadores[jugador].buscar_posicion_coordenadas( posicion_edificio, coord_x, coord_y);

    if(!jugadores[jugador].puede_repararse_edificio(posicion_edificio, orden_edificio)){
        return estado = ERROR_EDIFICIO_NO_REPARABLE;
    }
        
    
    estado = jugadores[jugador].verificar_condiciones_construccion(nombre_edificio, diccionario);

    if(estado == OK){
        
        jugadores[jugador].sumar_vida_edificio(posicion_edificio, orden_edificio); 
        jugadores[jugador].restar_materiales_reparacion(nombre_edificio, diccionario);
        jugadores[jugador].restar_energia((double)25); //desharcodear

        cout<<endl<<TAB<<NEGRITA<<FONDO_COLOR_VERDE<< "¡Se reparo el/la " << nombre_edificio << "!" << FIN_DE_FORMATO <<endl;
    }


    return estado;
}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::lluvia_de_recursos(){

    int cantidad_lluvia_piedra, cantidad_lluvia_madera, cantidad_lluvia_metal, cantidad_lluvia_andycoins;

    cantidad_lluvia_piedra = rand() % RAND_MAX_PIEDRA + 1;
    cantidad_lluvia_madera = rand() % RAND_MAX_MADERA;
    cantidad_lluvia_metal = rand() % RAND_MAX_METAL + 2;
    cantidad_lluvia_andycoins = rand() % RAND_MAX_ANDYCOINS;

    int casilleros_disponibles = mapa.cantidad_casilleros_transitables_disponibles();
    if(cantidad_lluvia_andycoins + cantidad_lluvia_madera + cantidad_lluvia_piedra + cantidad_lluvia_metal > casilleros_disponibles)
        return ADVERTENCIA_LLUVIA_RECURSOS;


    string piedra = "piedra 100";
    string madera = "madera 50";
    string metal = "metal 50";
    string andycoins = "andycoins 250";
    

    for(int i = 1; i <= cantidad_lluvia_piedra; ++i){
        Parser parser(piedra);
        mapa.agregar_material_en_coordenada_transitable_aleatoria(parser.procesar_entrada_material_lluvia()); // RE COCHINOOO ¿cambiar?
    }

    for(int i = 1; i <= cantidad_lluvia_madera; ++i){
        Parser parser(madera);
        mapa.agregar_material_en_coordenada_transitable_aleatoria(parser.procesar_entrada_material_lluvia());
    }

    for(int i = 1; i <= cantidad_lluvia_metal; ++i){
        Parser parser(metal);
        mapa.agregar_material_en_coordenada_transitable_aleatoria(parser.procesar_entrada_material_lluvia());
    }

    for(int i = 1; i <= cantidad_lluvia_andycoins; ++i){
        Parser parser(andycoins);
        mapa.agregar_material_en_coordenada_transitable_aleatoria(parser.procesar_entrada_material_lluvia());
    }

    cout << endl << TAB << FONDO_COLOR_AZUL << NEGRITA << "¡LLUVIA DE RECURSOS!" << FIN_DE_FORMATO << endl;

    return OK;

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::moverse_a_una_coord(int coord_x, int coord_y, Jugador_t jugador){

    Estado_t estado = OK;
    Lista<Coordenadas*> camino;

    if(coord_x == jugadores[jugador].obtener_ubicacion().coordenada_x && coord_y == jugadores[jugador].obtener_ubicacion().coordenada_y)
        return ERROR_MISMA_UBICACION; //No tiene sentido continuar si sucede esto

    if(coord_x < mapa.obtener_columnas() && coord_y < mapa.obtener_filas()){
        
        jugadores[jugador].actualizar_grafo(mapa);
        estado = jugadores[jugador].moverse_a_una_coord(coord_x, coord_y, camino);

        if(estado == OK){

            realizar_movimiento(coord_x, coord_y, jugador, camino);
            
        }
    } else estado = ERROR_POSICION_INEXISTENTE;

    // Elimino los punteros a Coordenadas del camino
    for(int i = 0; i < camino.obtener_cantidad(); i++){
        delete camino.consulta(i);
    }

    return estado;

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::realizar_movimiento(int coord_inicial_x, int coord_inicial_y, Jugador_t jugador, Lista<Coordenadas*> &camino){
    
    char identificador;
    double cantidad_a_sumar;

    for(int i = 1; i < camino.obtener_cantidad(); ++i){ // camino.consulta(i) -> coordenada_x , camino.consulta(i) -> coordenada_y

        eliminar_posicion_jugador(jugador); // Elimino posicion actual del jugador.
        
        if( mapa.se_puede_transitar(camino.consulta(i) -> coordenada_x , camino.consulta(i) -> coordenada_y)
            && mapa.casillero_esta_ocupado(camino.consulta(i) -> coordenada_x , camino.consulta(i) -> coordenada_y) ){
            
            //ESTO SIGNIFICA QUE HAY UN MATERIAL. NO HACE FALTA CHEQUEAR SI HAY JUGADOR, PORQ EL CAMINO MINIMO YA ENTREGA UN CAMINO QUE EVITA LOS JUGADORES Y LOS EDIFICIOS CONSTRUIDOS
            identificador = mapa.obtener_identificador_recurso_de_casillero(camino.consulta(i) -> coordenada_x , camino.consulta(i) -> coordenada_y);
            cantidad_a_sumar = mapa.recolectar_recursos_casillero(camino.consulta(i) -> coordenada_x , camino.consulta(i) -> coordenada_y);
            jugadores[jugador].sumar_cantidad_material_inventario(identificador, cantidad_a_sumar);
            mapa.quitar_material_en_coordenadas(camino.consulta(i) -> coordenada_x , camino.consulta(i) -> coordenada_y);
            
        }
        

        posicionar_jugador(camino.consulta(i) -> coordenada_x , camino.consulta(i) -> coordenada_y, jugador);
        
        animacion_movimiento();
    }

}

void Andypolis::animacion_movimiento(){

    if(system(CLR_SCREEN));

    mostrar_mapa(0,0);

    usleep(500000);

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::recolectar_recursos_jugador(Jugador_t jugador){

   jugadores[jugador].recolectar_recursos(mapa);

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::depositar_recursos_jugador(Jugador_t jugador){

   jugadores[jugador].depositar_recursos(mapa);


}


// ------------------------------------------------------------------------------------------------------------


bool Andypolis::gano_el_jugador(Jugador_t jugador){

    bool gano = false;

    return gano = jugadores[jugador].gane_el_juego( diccionario.consultar_const(STR_ESCUELA)->obtener_dato_const()->obtener_maximos_permitidos() );

}

// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_inventario(Jugador_t jugador){

   jugadores[jugador].mostrar_inventario();
}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_objetivos(Jugador_t jugador){
    
   jugadores[jugador].mostrar_objetivos( diccionario.consultar_const(STR_ESCUELA)->obtener_dato_const()->obtener_maximos_permitidos() );
}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::listar_edificios_construidos(Jugador_t jugador){

    jugadores[jugador].listar_edificios_construidos();
}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::listar_edificios_diccionario( ){

    cout
        << NEGRITA << SUBRAYADO
        << left
        << setw(30)
        << "Nombre del edificio"
        << left
        << setw(24)
        << "Cantidad de piedra"
        << left
        << setw(24)
        << "Cantidad de madera"
        << left
        << setw(24)
        << "Cantidad de metal"
        << left
        << setw(24)
        << "Maximo de construcciones"
        << FIN_DE_FORMATO
        << endl;

   
    diccionario.imprimir_en_orden();
}



// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_mapa(int pos_visual_x, int pos_visual_y){

    mapa.mostrar_mapa(pos_visual_x, pos_visual_y);

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::consultar_casillero_de_mapa(int coord_x, int coord_y) const{

    Estado_t estado = OK;

    return estado = mapa.consultar_casillero(coord_x,coord_y);

}


// ------------------------------------------------------------------------------------------------------------


bool Andypolis::es_transitable(int coord_x, int coord_y){

    return mapa.se_puede_transitar(coord_x, coord_y);
}


// ------------------------------------------------------------------------------------------------------------



bool Andypolis::es_construible(int coord_x, int coord_y){

    return mapa.se_puede_construir(coord_x, coord_y);

}

// ------------------------------------------------------------------------------------------------------------


void Andypolis::guardar_andypolis(  fstream& archivo_salida_materiales, fstream& archivo_salida_ubicaciones){

    guardar_materiales_en_archivo(archivo_salida_materiales);

    guardar_ubicaciones_en_archivo(archivo_salida_ubicaciones);
}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::guardar_andypolis_partida_nueva( fstream& archivo_salida_edificios ){

    diccionario.guardar_en_archivo(archivo_salida_edificios); 
}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::guardar_materiales_en_archivo( fstream& archivo_salida_materiales ){

    for(int i = 0; i < jugadores[JUGADOR_UNO].obtener_cantidad_de_materiales_en_inventario(); ++i){
        string linea = armar_str_para_guardar_inventario(i);
        archivo_salida_materiales << linea;
    }
}


// ------------------------------------------------------------------------------------------------------------


string Andypolis::armar_str_para_guardar_inventario(int pos){

    stringstream ss;

    ss << jugadores[JUGADOR_UNO].obtener_str_nombre_material(pos) << " " 
    << jugadores[JUGADOR_UNO].obtener_str_cantidad_material(pos)  << " "
    << jugadores[JUGADOR_DOS].obtener_str_cantidad_material(pos) << endl;

    return ss.str();

}


// ------------------------------------------------------------------------------------------------------------


string Andypolis::armar_str_para_guardar_inventario_nueva_partida(int pos){

    stringstream ss;

    ss << jugadores[JUGADOR_UNO].obtener_str_nombre_material(pos) << " " 
    << "0" << " "
    << "0" << endl;

    return ss.str();

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::guardar_ubicaciones_en_archivo(fstream &archivo_salida){

    // Imprimo los materiales:
    mapa.guardar_materiales_en_achivo(archivo_salida);

    jugadores[JUGADOR_UNO].guardar_ubicacion_en_archivo(archivo_salida, JUGADOR_UNO);

    // Imprimo los edificios del jugador uno:
    jugadores[JUGADOR_UNO].guardar_mis_edificios_en_archivo(archivo_salida);

    // Imprimo la posicion del jugador dos:
    jugadores[JUGADOR_DOS].guardar_ubicacion_en_archivo(archivo_salida, JUGADOR_DOS);

    // Imprimo los edificios del jugador dos:
    jugadores[JUGADOR_DOS].guardar_mis_edificios_en_archivo(archivo_salida);
}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::guardar_materiales_para_nueva_partida(fstream &archivo_materiales){

    for(int i = 0; i < jugadores[JUGADOR_UNO].obtener_cantidad_de_materiales_en_inventario(); ++i){
        string linea = armar_str_para_guardar_inventario_nueva_partida(i);
        archivo_materiales << linea;
    }

}


// ------------------------------------------------------------------------------------------------------------

int Andypolis::obtener_filas_mapa(){

    return mapa.obtener_filas();

}


// ------------------------------------------------------------------------------------------------------------



int Andypolis::obtener_columnas_mapa(){

    return mapa.obtener_columnas();

}

