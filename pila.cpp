//
// Created by Sergio Oviedo Seas on 25/5/22.
//

#include "pila.h"

pila::pila() {
    this->pTope = NULL;
    this->largo = 0;
}

pila::~pila() {

}

nodoS* pila::getPTope() {
    return this->pTope;
}

int pila::getLargo() {
    return this->largo;
}

void pila::setPTope(nodoS* _pTope) {
    this->pTope = _pTope;
}
void pila::setLargo(int _largo) {
    this->largo = _largo;
}

// Agregar un elemento a la pila
void pila::push(int _info) {
    nodoS* nuevo = new nodoS(_info);

    nuevo->setSgte(pTope);
    setPTope(nuevo);
    setLargo(getLargo()+1);
}

// Eliminar un elemento de la pila
int pila::pop() {
    int info = 0;

    if(empty()) {
        info = 0;
    }else{
        info = getPTope()->getDato();
        nodoS* aux = getPTope();
        setPTope(aux->getSgte());
        delete aux;
        setLargo(getLargo()-1);
    }
    return info;
}

// Devuelve el dato en el tope de la pila
int pila::top() {
    if(empty()) {
        return 0;
    }else{
        return pTope->getDato();
    }
}

int pila::size() {
    return this->largo;
}

void pila::show() {
    if(empty()) {
        cout<<"La pila esta vacia"<<endl;
    }else{
        nodoS *aux = pTope;
        while(aux != NULL){
            cout<< aux->getDato() << endl;
            aux = aux->getSgte();
        }
    }
}

bool pila::empty() {
    return pTope == NULL;
}