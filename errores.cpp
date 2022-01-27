#include <iostream>
#include "errores.h"

using namespace std;

void imprimir_error(Estado_t st){
	if(system(CLR_SCREEN));
	cout << endl;
	cout << TAB << NEGRITA << FONDO_COLOR_ROJO << errores[st] << FIN_DE_FORMATO << endl;

}
