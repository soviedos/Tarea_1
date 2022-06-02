// Programa que recibe numeros enteros y los almacena en una lista, pila o cola.
// Luego de agregagar los numeros enteros, el usuario los puede mover entre las tres estructuras.

#include <iostream>
#include <stdlib.h>

using namespace std;

#include "listaSimple.h"
#include "cola.h"
#include "pila.h"

listaSimple* LS = new listaSimple();
pila* pi = new pila();
cola* co = new cola();

struct nodo{
    int nro;
    struct nodo *izq, *der;
};

typedef struct nodo *ABB;
/* es un puntero de tipo nodo que hemos llamado ABB, que ulitizaremos
   para mayor facilidad de creacion de variables */

ABB crearNodo(int x)
{
    ABB nuevoNodo = new(struct nodo);
    nuevoNodo->nro = x;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;
}
int insertar(ABB &arbol, int x, int contador)
{
    contador ++;
    if(arbol==NULL)
    {
        arbol = crearNodo(x);
    }
    else if(x < arbol->nro)
        insertar(arbol->izq, x, contador);
    else if(x > arbol->nro)
        insertar(arbol->der, x, contador);
    return contador;
}

void preOrden(ABB arbol)
{
    if(arbol!=NULL)
    {
        cout << arbol->nro <<" ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void enOrden(ABB arbol)
{
    if(arbol!=NULL)
    {
        enOrden(arbol->izq);
        cout << arbol->nro << " ";
        enOrden(arbol->der);
    }
}

void postOrden(ABB arbol)
{
    if(arbol!=NULL)
    {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->nro << " ";
    }
}

void verArbol(ABB arbol, int n)
{
    if(arbol==NULL)
        return;
    verArbol(arbol->der, n+1);

    for(int i=0; i<n; i++)
        cout<<"   ";

    cout<< arbol->nro <<endl;

    verArbol(arbol->izq, n+1);
}

void menuArbol () {
    ABB arbol = NULL;   // creado Arbol
    int opc = 0;
    do {
        cout << " Arbol Binario de búsqueda" << endl;
        cout << endl;
        cout << "(1) Agregar valores de la lista al arbol" << endl;
        cout << "(2) Ver arbol" << endl;
        cout << "(3) Ver recorrido del arbol En-Orden" << endl;
        cout << "(4) Ver recorrido del arbol Pre-Orden" << endl;
        cout << "(5) Ver recorrido del arbol Post-Orden" << endl;
        cout << "(0) Terminar" << endl;
        cout << endl;
        cout << "OPCION SELECCIONADA-> "; cin >> opc;
        cout << "-----------------------------------";
        cout << endl << endl;

        switch (opc) {
            case 1: {
                nodoS* aux = LS->getCab();
                int n;  // numero de nodos del arbol
                int x; // elemento a insertar en cada nodo
                int contador = 0;
                cout << "\n\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";
                cout << endl;
                if (LS->esVacia()) {
                    cout << "La lista esta vacia";
                }
                else {
                    int i = 0;
                    while (aux != NULL) {
                        x = aux->getDato();
                        aux = aux->getSgte();
                        cout << " Numero del nodo " << i+1 << ": " << x << endl;
                        contador = insertar(arbol, x, contador);
                        cout << "Los pasos requeridos para ingresar el numero: " <<x << " son: " << contador << endl;
                        i++;
                    }
                }
                /*
                for(int i=0; i<n; i++)
                {
                    cout << " Numero del nodo " << i+1 << ": ";
                    cin >> x;
                    insertar( arbol, x);
                }*/
                break;
            }
            case 2: {
                cout << "\n Mostrando ABB \n\n";
                verArbol( arbol, 0);
                break;
            }
            case 3: {
                cout << "\n Recorridos del ABB";
                cout << "\n\n En orden   :  ";   enOrden(arbol);
                break;
            }
            case 4: {
                cout << "\n Recorridos del ABB";
                cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
                break;
            }
            case 5: {
                cout << "\n Recorridos del ABB";
                cout << "\n\n Post Orden :  ";   postOrden(arbol);
                break;
            }
            case 0: {
                break;
            }
            default: {
                break;
            }
        }
    }while (opc != 0);
}

void menuPila () {
    int opc = 0;
    do {
        cout << "Operaciones de Pilas" << endl;
        cout << endl;
        cout << "(1) Agregar a la pila" << endl;
        cout << "(2) Retirar de la pila" << endl;
        cout << "(3) Mostrar los valores de la pila" << endl;
        cout << "(4) Mover valor a la lista" << endl;
        cout << "(5) Mover valor a la cola" << endl;
        cout << "(0) Terminar" << endl;
        cout << endl;
        cout << "OPCION SELECCIONADA-> "; cin >> opc;
        cout << "-----------------------------------";
        cout << endl << endl;

        switch (opc) {
            case 1: {
                cout << "Agregar a la pila" << endl;
                int numero;
                cout << "Por favor, ingrese el número que desea agregar" << endl;
                cin >> numero;
                pi->push(numero);
                break;
            }
            case 2: {
                cout << "Retirar de la pila" << endl;
                int numero;
                numero = pi->pop();
                cout << "El número que se elimino es: " << numero;
                cout << endl << endl;
                break;
            }
            case 3: {
                cout << "Mostrar los valores de la pila" << endl;
                pi->show();
                cout << endl;
                break;
            }
            case 4: {
                cout << "Mover valor a la lista" << endl;
                int numero = pi->pop();
                LS->agregarAsc(numero);
                cout << "El numero: " << numero << " ha sido movido a la lista." << endl;
                break;
            }
            case 5: {
                cout << "Mover valor a la cola" << endl;
                int numero = pi->pop();
                co->poner(numero);
                cout << "El numero: " << numero << " ha sido movido a la cola." << endl;
                break;
            }
            case 0: {
                break;
            }
            default: {
                break;
            }
        }
    } while (opc != 0);
}

void menuCola () {
    int opc = 0;
    do {
        cout << "Operaciones de Colas" << endl;
        cout << endl;
        cout << "(1) Agregar a la cola" << endl;
        cout << "(2) Retirar de la cola" << endl;
        cout << "(3) Mostrar los valores de la cola" << endl;
        cout << "(4) Mover valor a la lista" << endl;
        cout << "(5) Mover valor a la pila" << endl;
        cout << "(0) Terminar" << endl;
        cout << endl;
        cout << "OPCION SELECCIONADA-> "; cin >> opc;
        cout << "-----------------------------------";
        cout << endl << endl;

        switch (opc) {
            case 1: {
                cout << "Agregar a la cola" << endl;
                int numero;
                cout << "Por favor, ingrese el número que desea agregar" << endl;
                cin >> numero;
                co->poner(numero);
                break;
            }
            case 2: {
                cout << "Retirar de la cola" << endl;
                int numero;
                numero = co->quitar();
                cout << "El número que se elimino es: " << numero;
                cout << endl << endl;
                break;
            }
            case 3: {
                cout << "Mostrar los valores de la cola" << endl;
                co->mostrarCola();
                cout << endl;
                break;
            }
            case 4: {
                cout << "Mover valor a la lista" << endl;
                int numero = co->quitar();
                LS->agregarAsc(numero);
                cout << "El numero: " << numero << " ha sido movido a la lista." << endl;
                break;
                break;
            }
            case 5: {
                cout << "Mover valor a la pila" << endl;
                int numero = co->quitar();
                pi->push(numero);
                cout << "El numero: " << numero << " ha sido movido a la pila." << endl;
                break;
            }
            case 0: {
                break;
            }
            default: {
                break;
            }
        }
    } while (opc != 0);
}

void menuLista () {
    int opc = 0;
    do {
        cout << "Operaciones de Listas" << endl;
        cout << endl;
        cout << "(1) Agregar a la lista" << endl;
        cout << "(2) Retirar de la lista" << endl;
        cout << "(3) Consultar la lista" << endl;
        cout << "(4) Mover valor a la Cola" << endl;
        cout << "(5) Mover valor a la Pila" << endl;
        cout << "(0) Terminar" << endl;
        cout << endl;
        cout << "OPCION SELECCIONADA-> "; cin >> opc;
        cout << "-----------------------------------";
        cout << endl << endl;

        switch (opc) {
            case 1: {
                cout << "Agregar a la lista" << endl;
                int numero;
                cout << "Por favor, ingrese el número que desea agregar" << endl;
                cin >> numero;
                bool agregado = LS->agregarAsc(numero);
                if (agregado) {
                    cout << "El número ha sido agregado satisfactoriamente a la lista";
                }else {
                    cout << "El número no se pudo ingresar";
                }
                break;
            }
            case 2: {
                cout << "Retirar de la lista" << endl;
                int numero;
                cout << "Por favor, ingrese el número que desea agregar" << endl;
                cin >> numero;
                bool agregado = LS->eliminar(numero);
                if (agregado) {
                    cout << "El número ha sido eliminado satisfactoriamente a la lista" << endl;
                }else {
                    cout << "El número no se pudo eliminar" << endl;
                }
                break;
            }
            case 3: {
                cout << "Consultar la lista" << endl;
                LS->desplegarLista();
                break;
            }
            case 4: {
                cout << "Mover valor a la cola" << endl;
                int numero;
                cout << "Por favor, ingrese el número que desea mover a la cola" << endl;
                cin >> numero;
                bool cambiado = LS->eliminaPos(numero);
                if (cambiado) {
                    co->poner(numero);
                    cout << "El número ha sido movido satisfactoriamente a la cola" << endl;
                }else {
                    cout << "El número no se pudo mover" << endl;
                }
                break;
            }
            case 5: {
                cout << "Mover valor a la pila" << endl;
                int numero;
                cout << "Por favor, ingrese el número que desea mover a la pila" << endl;
                cin >> numero;
                bool cambiado = LS->eliminaPos(numero);
                if (cambiado) {
                    pi->push(numero);
                    cout << "El número ha sido movido satisfactoriamente a la pila" << endl;
                }else {
                    cout << "El número no se pudo mover" << endl;
                }
                break;
            }
            case 0: {
                break;
            }
            default: {
                break;
            }
        }
    } while (opc != 0);
}

void menuPrincipal () {
    int opc = 0;
    do {
        cout << " UNIVERSIDAD CENFOTEC" << endl;
        cout << "ESTRUCTURAS DE DATOS 2\n" << endl;
        cout << "Menu Principal Tarea 1" << endl;
        cout << endl;
        cout << "(1) Menu Lista Ordenada" << endl;
        cout << "(2) Menu Pila" << endl;
        cout << "(3) Menu Cola" << endl;
        cout << "(4) Menu Arbol Binario" << endl;
        cout << "(0) Terminar" << endl;
        cout << endl;
        cout << "OPCION SELECCIONADA-> "; cin >> opc;
        cout << "-----------------------------------";
        cout << endl << endl;

        switch (opc) {
            case 1: {
                menuLista();
                break;
            }
            case 2: {
                menuPila();
                break;
            }
            case 3: {
                menuCola();
                break;
            }
            case 4: {
                menuArbol();
                break;
            }
            case 0: {
                break;
            }
            default: {
                break;
            }
        }
    } while (opc != 0);
}

int main () {
    menuPrincipal();
    return 0;
}
