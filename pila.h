//
// Created by Sergio Oviedo Seas on 25/5/22.
//

#ifndef TAREA_1_PILA_H
#define TAREA_1_PILA_H
#include <iostream>
#include <stdlib.h>
#include "nodoS.h"

using namespace std;

class pila {
    private:
        nodoS* pTope;
        int largo;

    public:
        // Constructores
        pila();
        ~pila();

        // Getters
        nodoS* getPTope();
        int getLargo();

        // Setters
        void setPTope(nodoS*);
        void setLargo(int);

        // Operaciones de agregar
        void push(int); // Agregar

        // Operaciones de eliminar
        int pop(); // Eliminar

        // Operaciones de desplegar
        void show(); // Muestra la pila

        // Operaciones miscelaneas
        int top(); // Dato en el tope de la pila
        int size(); // Tamaño de la pila
        bool empty();
};


#endif //TAREA_1_PILA_H
