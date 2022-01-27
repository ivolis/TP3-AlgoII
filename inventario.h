#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <string>
#include <fstream>
#include <iomanip>
#include "material.h"
#include "parser.h"
#include "vector.h"
#include "herramientas.h"

using namespace std;

const int PRECIO_BOMBA = 100;

class Inventario{

private:
    // Atributos
    Vector<Material> materiales;
    int cantidad_materiales;
    Jugador_t jugador;
    int andycoins_gastadas;
    int bombas_usadas;
    int bombas_compradas;

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR un inventario vacio con una capacidad inicial para cargar materiales
    Inventario(); // Constructor por default

    // pre: -
    // pos: DESTRUCTOR del inventario (especificamente la lista de materiales dinamica)
    ~Inventario(); // destructor

    // pre: -
    // pos: agrega un material a la lista de materiales
    void agregar_material_a_lista(Material* material);

    // pre: -
    // pos: devuelve la ubicacion de un material en la lista de materiales
    int buscar_material(char identificador) const;

    // pre: -
    // pos:Obtiene la cantidad de materiales
    int obtener_cantidad_materiales();

    // pre: -
    // pos: obtiene cuanta cantidad de piedra hay en el inventario
    double obtener_cantidad_de_piedra() const;

    // pre: -
    // pos: obtiene cuanta cantidad de madera hay en el inventario
    double obtener_cantidad_de_madera();

    // pre: -
    // pos: obtiene cuanta cantidad de metal hay en el inventario
    double obtener_cantidad_de_metal();

    // pre: -
    // pos: obtiene cuanta cantidad de bombas hay en el inventario
    double obtener_cantidad_de_bombas() const;

    // pre: -
    // pos: obtiene cuanta cantidad de andycoins hay en el inventario
    double obtener_cantidad_de_andycoins() const;

    // pre: deberia ya estar chequeado que la resta queda > 0 como cantidad final de c/material
    // pos: resta una cantidad de material de los 3 elementos de construccion
    void restar_cantidad_materiales_construccion(double costo_piedra, double costo_madera, double costo_metal);

    // pre: -
    // pos: resta una cantidad de material de los 3 elementos de construccion
    void sumar_cantidad_materiales_construccion(double costo_piedra, double costo_madera, double costo_metal);

    // pre: -
    // pos: se suma una cantidad especifica de un material especifico en funcion de su identificador
    void sumar_cantidad_material(char identificador, double cantidad);

    // pre: -
    // pos: se resta una cantidad especifica de un material especifico en funcion de su identificador
    void restar_cantidad_material(char identificador, double cantidad);


    // pre: -
    // pos: mustra el inventario
    void mostrar_inventario();

    // pre: -
    // pos: guarda el inventario
    void guardar_inventario(ofstream& archivo_materiales);

    // pre: -
    // pos: guarda el inventario
    string guardar_linea_inventario_en_string(int pos);

    //Para el objetivo comprar_andypolis:

    // pre: -
    // pos: Aumenta la cantidad de andycoins
    void aumentar_andycoins_gastadas(int cantidad);

    // pre: -
    // pos: obtiene la cantida de andycoinsb gastadas
    int obtener_andycoins_gastadas() const;

    // pre: -
    // pos: aumenta la cantidad de bombas usadas
    void aumentar_bombas_usadas(int cantidad);

    // pre: -
    // pos: obtiene la cantidad de bombas usadas
    int obtener_bombas_usadas() const;

    //Para el objetivo extremista:

    // pre: -
    // pos: aumenta la cantidad de bombas compradas
    void aumentar_bombas_compradas(int cantidad);

    // pre: -
    // pos: obtiene la cantidad de bombas usadas
    int obtener_bombas_compradas() const;

};











#endif // INVENTARIO_H