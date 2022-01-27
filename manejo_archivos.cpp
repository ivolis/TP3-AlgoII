#include "manejo_archivos.h"

// ------------------------------------------------------------------------------------------------------------


Manejo_archivos::Manejo_archivos(){

    this -> archivo_ubicaciones.open(PATH_ENTRADA_UBICACIONES, ios::in);
	this -> archivo_materiales.open(PATH_ENTRADA_MATERIALES, ios::in);
    this -> archivo_edificios.open(PATH_ENTRADA_EDIFICIOS, ios::in);
    this -> archivo_mapa.open(PATH_ENTRADA_MAPA, ios::in);

    if( !archivo_ubicaciones.is_open() ){ // Si no existe el archivo ubicaciones, lo creo vacio.

        fstream archivo_ubicaciones;
        crear_archivo_vacio(PATH_ENTRADA_UBICACIONES, archivo_ubicaciones);

    }
}


// ------------------------------------------------------------------------------------------------------------


Manejo_archivos::~Manejo_archivos(){

    this -> archivo_ubicaciones.close();
	this -> archivo_materiales.close();
    this -> archivo_edificios.close();
    this -> archivo_mapa.close();

}


// ------------------------------------------------------------------------------------------------------------


void Manejo_archivos::crear_archivo_vacio(string ruta_archivo, fstream& archivo){

    archivo.open(ruta_archivo, ios::out);
    archivo.close();
    archivo.open(ruta_archivo, ios::in);
}


// ------------------------------------------------------------------------------------------------------------


bool Manejo_archivos::archivo_ubicaciones_vacio(){

    if(archivo_ubicaciones.peek() == fstream::traits_type::eof())
        return true;

    else return false;

}


// ------------------------------------------------------------------------------------------------------------


fstream& Manejo_archivos::obtener_archivo_materiales(){

    return this -> archivo_materiales;
}


// ------------------------------------------------------------------------------------------------------------


fstream& Manejo_archivos::obtener_archivo_edificios(){

    return this -> archivo_edificios;
}


// ------------------------------------------------------------------------------------------------------------


fstream& Manejo_archivos::obtener_archivo_ubicaciones(){

    return this -> archivo_ubicaciones;
}


// ------------------------------------------------------------------------------------------------------------


fstream& Manejo_archivos::obtener_archivo_mapa(){

    return this -> archivo_mapa;
}


// ------------------------------------------------------------------------------------------------------------


void Manejo_archivos::guardar_cambios_partida_nueva(Andypolis& andypolis){

    // Cierros los archivos de lectura
	archivo_edificios.close();

    archivo_edificios.open(PATH_ENTRADA_EDIFICIOS, ios::out | ios::trunc);

    andypolis.guardar_andypolis_partida_nueva(archivo_edificios);

}


// ------------------------------------------------------------------------------------------------------------


void Manejo_archivos::guardar_cambios(Andypolis& andypolis){

    // Cierros los archivos de lectura
	archivo_materiales.close();
	archivo_ubicaciones.close();

    archivo_materiales.open(PATH_ENTRADA_MATERIALES, ios::out | ios::trunc);
    archivo_ubicaciones.open(PATH_ENTRADA_UBICACIONES, ios::out | ios::trunc);

    andypolis.guardar_andypolis( archivo_materiales, archivo_ubicaciones);

    cout << endl << TAB << TAB << "# La partida se ha guardado correctamente. Esperamos que vuelvan pronto ♥ " << endl << endl;

}


// ------------------------------------------------------------------------------------------------------------


void Manejo_archivos::generar_archivos_para_nueva_partida(Andypolis& andypolis){

    archivo_ubicaciones.close();
    archivo_ubicaciones.open(PATH_ENTRADA_UBICACIONES, ios::out | ios::trunc);
    
    archivo_materiales.close();
    archivo_materiales.open(PATH_ENTRADA_MATERIALES, ios::out | ios::trunc);
    andypolis.guardar_materiales_para_nueva_partida(archivo_materiales);
    
}


// ------------------------------------------------------------------------------------------------------------