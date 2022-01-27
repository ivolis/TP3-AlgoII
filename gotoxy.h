#ifndef _GOTOXY_H
#define _GOTOXY_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Gotoxy{

public:

    // METODOS

    // CONSTRUCTOR
    Gotoxy(){}

    template <typename T>
    // PRE:
    // POST:
    inline std::string ToString(const T& t) {

        std::stringstream ss;
        ss << t;

        return ss.str();
    }

    // PRE:
    // POST:
    inline std::string pos(const int& x,const int& y) {

        return "\33[" + ToString(y) + ";" + ToString(x) + "H";
    }


};



#endif //GRAFOS_GOTOXY_H
