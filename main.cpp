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
                break;
            }
            case 5: {
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
                break;
            }
            case 5: {
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
        cout << "(4) Modificar la lista" << endl;
        cout << "(5) Mover valor a la Cola" << endl;
        cout << "(6) Mover valor a la Pila" << endl;
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
                    cout << "El número ha sido eliminado satisfactoriamente a la lista";
                }else {
                    cout << "El número no se pudo eliminar";
                }
                break;
            }
            case 3: {
                cout << "Consultar la lista" << endl;
                LS->desplegarLista();
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                break;
            }
            case 6: {
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
