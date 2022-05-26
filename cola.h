//
// Created by Sergio Oviedo Seas on 25/5/22.
//

#ifndef TAREA_1_COLA_H
#define TAREA_1_COLA_H
#include <iostream>
#include <stdlib.h>
#include "nodoS.h"

using namespace std;

class cola {
    private:
        int tam;
        nodoS* pFrente;
        nodoS* pFinal;

    public:
        // Constructores
        cola();
        ~cola();

        // Getters
        int getTam();
        nodoS* getPFrente();
        nodoS* getPFinal();

        // Setters
        void setTam(int);
        void setPFrente(nodoS*);
        void setPFinal(nodoS*);

        // Operaciones de agregar
        void poner(int);

        // Operaciones de eliminar
        int quitar();

        // Operaciones de desplegar
        void mostrarCola();

        // Operaciones miscelaneas
        bool esVacia();
        int largo();
        int frente();
};


#endif //TAREA_1_COLA_H
