//
// Created by Sergio Oviedo Seas on 25/5/22.
//

#ifndef TAREA_1_NODOS_H
#define TAREA_1_NODOS_H
#include <iostream>
#include <stdlib.h>

using namespace std;

class nodoS {
    private:
        int dato;
        nodoS* sgte; // sgte es un puntero al siguiente nodo
    public:
        nodoS(); // constructor de la clase
        nodoS(int); // contructor sobrecargad
        int getDato();
        nodoS *getSgte();
        void setDato(int);
        void setSgte(nodoS *);
};


#endif //TAREA_1_NODOS_H
