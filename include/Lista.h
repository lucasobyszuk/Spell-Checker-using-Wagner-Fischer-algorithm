#ifndef LISTA_H
#define LISTA_H

#include <string>

using namespace std;

class Lista
{
    private:

        // Datos miembro
        struct Nodo {
            string dato;
            Nodo * siguiente; };
        Nodo * lista;
        Nodo * ultimo;
        Nodo * actual;

    public:

        // Constructor
        Lista();

        // Destructor
        virtual ~Lista();

        // Metodos modificadores
        void agregarLinea(string linea);
        void setearActual();
        bool devolverActual(string & linea); // Si aun no se llego a fin de lista, devuelve true
                                             // y pone en "linea" el string actual, y avanza actual una posicion.

        // Metodos observadores
        bool esVacio() const;
};

#endif // CONJUNTO_H
