//
// Created by Sergio Oviedo Seas on 25/5/22.
//

#ifndef TAREA_1_LISTASIMPLE_H
#define TAREA_1_LISTASIMPLE_H
#include <iostream>
#include <stdlib.h>
#include "nodoS.h"

using namespace std;

class listaSimple {
    private:
        nodoS* cab;
        int largo;

    public:
        listaSimple();
        nodoS *getCab();
        int getLargo();

        void setCab(nodoS *);
        void setLargo(int);

        //Operaciones miscelaneas
        bool esVacia();
        nodoS* anterior(int); //Devuelve la dirección del nodo anterior al dato

        /// OPERACIONES DE AGREGAR
        void agregarInicio(int);  // Agrega el dato al inicio de la lista
        bool agregarAsc(int);  //

        //OPERACIONES DE ELIMINAR
        bool eliminar(int);

        // DESPLEGAR
        void desplegarLista();
};


#endif //TAREA_1_LISTASIMPLE_H
