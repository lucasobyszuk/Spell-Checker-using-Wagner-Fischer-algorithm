#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "Lista.h"

class Archivo
{
    private:

        // Dato miembro
        Lista Lineas;

    public:

        // Constructor
        Archivo();

        // Destructor
        virtual ~Archivo();

        // Modificadoras
        void getPalabras(string ruta);
        void agregarLinea(string linea);
        void guardar(string ruta);
        void setearActual();
        bool devolverActual(string & linea);

        // Observadoras
        bool esVacio() const;

};

#endif // ARCHIVO_H
