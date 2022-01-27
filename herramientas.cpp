#include <iostream>
#include "herramientas.h"



// ------------------------------------------------------------------------------------------------------------


bool contiene_numeros(string s){
    const string CONT = "0123456789";
    if(s.find_first_of(CONT) != string::npos){
        return true;
    }else
        return false;
}


// ------------------------------------------------------------------------------------------------------------


bool contiene_letras(string s){

    const string CONT = "0123456789";
    if(s.find_first_not_of(CONT) != string::npos){
        return true;
    }else
        return false;
}


// ------------------------------------------------------------------------------------------------------------


 bool es_un_numero(string str)
{
	char c;
	int N = (int) str.length();
    bool validez = true;

    if(!N) // string vacia
        validez = false; // si N == 0 ni va a entrar al for()

    for (int i = 0 ; i < N ; i++) {
    	c = str[i];
        if (isdigit(c) == 0) validez = false;
    }

    
    return validez;
}
