#include "juego.h"


using namespace std;


int main (void){
    if(system(CLR_SCREEN)) return 1;
	
    Juego juego;

    juego.jugar();
    

    return 0;
}
