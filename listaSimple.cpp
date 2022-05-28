//
// Created by Sergio Oviedo Seas on 25/5/22.
//

#include "listaSimple.h"

listaSimple::listaSimple()
{
    this->cab = NULL;
    this->largo = 0;
}

nodoS* listaSimple::getCab()
{
    return this->cab;
}

int listaSimple::getLargo()
{
    return this->largo;
}

void listaSimple::setCab(nodoS* _cab)
{
    this->cab = _cab;
}

void listaSimple::setLargo(int _largo)
{
    this->largo = _largo;
}

bool listaSimple::esVacia()
{
    return cab == NULL;
}

void listaSimple::agregarInicio(int _dato)
{
    nodoS* nuevo = new nodoS(_dato);
    nuevo->setSgte(cab);
    setCab(nuevo);
    setLargo(getLargo() + 1);
}
nodoS* listaSimple::anterior(int _dato)
{
    nodoS* ant = NULL;

    if (largo > 1) {
        bool encontrado = false;
        ant = getCab();
        while (!encontrado && ant->getSgte() != NULL) {
            if (ant->getSgte()->getDato() == _dato)
                encontrado = true;
            else
                ant = ant->getSgte();
        }
        if (!encontrado)
            ant = NULL;
    }

    return ant;
}

bool listaSimple::agregarAsc(int _dato)
{
    bool agregado = false;

    if (esVacia()) {
        setCab(new nodoS(_dato));
        setLargo(1);
        agregado = true;
    }else {
        if (_dato < getCab()->getDato()) {
            agregarInicio(_dato);
            agregado = true;
        }
        else {
            bool yaExiste = false;
            nodoS* aux = getCab();
            while (aux->getSgte() != NULL && !agregado && !yaExiste) {
                if (aux-> getDato() != _dato) {
                    if (_dato < aux->getSgte()->getDato()) {
                        // Entonces se agrega el dato
                        nodoS* nuevo = new nodoS(_dato); // Paso 1
                        // Crea el nodo
                        nuevo->setSgte(aux->getSgte()); // Paso 2
                        // Enlaza el nodo a la lista
                        aux->setSgte(nuevo); // Paso 3
                        setLargo(getLargo() + 1);
                        agregado = true;
                    }
                    else {
                        aux = aux->getSgte();
                    }
                }
                else {
                    yaExiste = true;
                }
            }
            if (aux->getSgte() == NULL && !agregado && (aux->getDato() != _dato)) {
                nodoS* nuevo = new nodoS(_dato);
                aux->setSgte(nuevo);
                setLargo(getLargo() + 1);
                agregado = true;
            }
        }
    }
    return agregado;
}

void listaSimple::desplegarLista()
{
    nodoS* aux = getCab();

    if (esVacia()) {
        cout << "Esta vacia la lista" << endl;;
    }
    else {

        while (aux != NULL) {
            cout << aux->getDato() << ",";
            aux = aux->getSgte();
        }
        cout << "fin" << endl;;
    }
}

bool listaSimple::eliminar(int _dato)
{
    bool eliminado = false;

    if (!esVacia()) {
        nodoS* aux;
        if (_dato == getCab()->getDato()) {
            aux = getCab();
            setCab(getCab()->getSgte()); // Apunta al segundo nodo.
            delete aux; // Eliminar el nodo, libera la memoria del nodo.
            setLargo(getLargo() - 1);
            eliminado = true;
        }
        else {
            //En medio
            nodoS* ant = anterior(_dato);
            if (ant != NULL) {
                aux = ant->getSgte(); // Paso 1. Apunto al nodo a eliminar.
                ant->setSgte(aux->getSgte()); // Paso 2. Reacomode las lista sin el nodo.
                delete aux; // Paso 3. Eliminar el nodo, liberar el espacio de memoria del nodo.
                setLargo(getLargo() - 1);
                eliminado = true;
            }
        }
    }
    return eliminado;
}
bool listaSimple::eliminaPos(int _dato)
{
    bool eliminado = false;
    int largo = getLargo();
    nodoS* dato = getCab();
    nodoS* aux;
    nodoS* ant;

    if (!esVacia()) {
        aux = getCab();
        for (int i = 0; i < largo; i++) {
            if (_dato == aux->getDato() && i == 0) {
                setCab(getCab()->getSgte()); // Apunta al segundo nodo.
                delete aux; // Eliminar el nodo, libera la memoria del nodo.
                setLargo(getLargo() - 1);
                eliminado = true;
                break;
            }
            else if (_dato == aux->getDato() == i && i < largo) {
                //En medio
                ant = anterior(aux->getDato());
                ant->setSgte(aux->getSgte()); // Paso 2. Reacomode las lista sin el nodo.
                delete aux; // Paso 3. Eliminar el nodo, liberar el espacio de memoria del nodo.
                setLargo(getLargo() - 1);
                eliminado = true;
                break;
            }
            else if (i == largo) {
                // Final
                ant = anterior(aux->getDato());
                ant->setSgte(NULL); // Paso 2. Reacomode las lista sin el nodo.
                delete aux; // Paso 3. Eliminar el nodo, liberar el espacio de memoria del nodo.
                setLargo(getLargo() - 1);
                eliminado = true;
                break;
            }else {
                ant = aux;
                aux = ant->getSgte();
            }
        }
    }
    return eliminado;
}