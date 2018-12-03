#include "..\include\Lista.h"


// Constructor
// --------------------------------------------------------------------------------------------------------------------
Lista::Lista() {
    lista = NULL;
    ultimo = NULL;
    actual = NULL;
}


// Destructor
// --------------------------------------------------------------------------------------------------------------------
Lista::~Lista() {
    while (lista!=NULL) {
        actual = lista;
        lista = lista->siguiente;
        delete actual;
    }
}


// Metodos modificadores
// --------------------------------------------------------------------------------------------------------------------
void Lista::agregarLinea(string linea) {

    if (lista==NULL) {
        lista = new Nodo;
        lista->siguiente = NULL;
        lista->dato = linea;
        ultimo = lista;
    }
    else {
        Nodo * aux = new Nodo;
        aux->siguiente = NULL;
        aux->dato = linea;
        ultimo->siguiente = aux;
        ultimo = aux;
    }
}


void Lista::setearActual(){
    actual = lista;
}


 bool Lista::devolverActual(string & linea) {
    if (actual!=NULL) {
        linea = actual->dato;
        actual = actual->siguiente;
        return true;
    }
    else
        return false;
}


// Metodos observadores
// --------------------------------------------------------------------------------------------------------------------
bool Lista::esVacio() const {
    if (lista!=NULL)
        return false;
    else
        return true;
}
