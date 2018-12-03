#include "..\include\Archivo.h"
#include <cassert>
#include <fstream>


// Constructor
// --------------------------------------------------------------------------------------------------------------------
Archivo::Archivo() {

}


// Destructor
// --------------------------------------------------------------------------------------------------------------------
Archivo::~Archivo() {

}


// Modificadoras
// --------------------------------------------------------------------------------------------------------------------
 void Archivo::getPalabras(string ruta) {

    ifstream entrada(ruta.c_str()); // .c_str convierte string en cadena de caracteres de C
    assert(entrada.is_open()); // Si hubo un error al abrir el archivo, termina el programa

    string dato;
    entrada >> dato;
    while (!entrada.eof()) {
        Lineas.agregarLinea(dato);
        entrada >> dato;
    }

    entrada.close();
}


void Archivo::agregarLinea(string linea) {
    Lineas.agregarLinea(linea);
}


void Archivo::guardar(string ruta) {

    ofstream salida(ruta.c_str(),ios::trunc);
    assert(salida.is_open()); // Si hubo un error al abrir el archivo, termina el programa.

    Lineas.setearActual();
    string dato;
    bool existe = Lineas.devolverActual(dato);
    while (existe) {
        salida << dato << "\n";
        existe = Lineas.devolverActual(dato);
    }

    salida.close();
}


void Archivo::setearActual() {
    Lineas.setearActual();
}


bool Archivo::devolverActual(string & linea) {
    bool existe = Lineas.devolverActual(linea);
    return existe;
}


// Observadoras
// --------------------------------------------------------------------------------------------------------------------
bool Archivo::esVacio() const {
    if (Lineas.esVacio())
        return true;
    else
        return false;
}
