//
// Created by Sergio Oviedo Seas on 25/5/22.
//

#include "cola.h"

cola::cola()
{
    this->tam = 0;
    this->pFrente = NULL;
    this->pFinal = NULL;
}

cola::~cola()
{
}

int cola::getTam() {
    return this->tam;
}

nodoS* cola::getPFrente() {
    return this->pFrente;
}

nodoS* cola::getPFinal() {
    return this->pFinal;
}

void cola::setTam(int _tam) {
    this->tam = _tam;
}

void cola::setPFrente(nodoS* _frente) {
    this->pFrente = _frente;
}

void cola::setPFinal(nodoS* _final) {
    this->pFinal = _final;
}

bool cola::esVacia(){
    return pFrente == NULL;
}

int cola::largo(){
    return this->tam;
}

void cola::poner(int _dato){

    nodoS* n = new nodoS(_dato);
    if (esVacia())
        pFrente = n;
    else
        pFinal->setSgte(n);

    pFinal = n;
    setTam(getTam() + 1);
}

int cola::quitar(){
    int dato = 0;
    if (!esVacia()){
        dato = pFrente->getDato();
        nodoS *aux = pFrente;
        pFrente = pFrente->getSgte();
        if (pFrente==NULL){
            pFinal = NULL;
        }
        delete aux;
        setTam( getTam() - 1);
    }
    return dato;
}


int cola::frente(){

    if (esVacia())
        return 0;
    else
        return pFrente->getDato();
}

void cola::mostrarCola(){
    if (esVacia()){
        cout <<"La cola esta vacia";
    }else{
        nodoS* aux = pFrente;
        while (aux != NULL){
            cout <<aux->getDato()<<"-";
            aux= aux->getSgte();
        }
        cout <<"Fin de la cola";

    }
}
