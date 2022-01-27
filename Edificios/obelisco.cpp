#include "obelisco.h"


// ------------------------------------------------------------------------------------------------------------


Obelisco::Obelisco(char identificador, Jugador_t creador, double deposito): Edificio(identificador, creador, deposito){}

// ------------------------------------------------------------------------------------------------------------


string Obelisco::obtener_tipo_edificio(){
    
    return STR_OBELISCO;
    
}
