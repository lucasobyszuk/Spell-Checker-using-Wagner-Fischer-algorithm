#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "Lista.h"

class Diccionario
{
    private:

        // Datos miembro
        string * Arreglo;
        unsigned int longitud;

        // Funciones privadas
        unsigned int filesize(ifstream & dicc);
        void intercalar(unsigned int inicio,unsigned int medio,unsigned int fin);
        void ordenar(unsigned int inicio,unsigned int fin);
        bool busquedaBinaria(int inicio, int fin, string dato) const ;
        bool buscarIndices(int & inicio,int & fin,char letra) const ;

    public:

        // Constructor
        Diccionario();

        // Destructor
        virtual ~Diccionario();

        // Modificadoras
        void getPalabras(string ruta);  // Copia las palabras desde el archivo fisico en el Arreglo.

        // Observadoras
        bool existe(string linea) const;
        void comienzaCon(char letra, Lista & resultado) const;
        bool esVacio() const;

};

#endif // DICCIONARIO_H
