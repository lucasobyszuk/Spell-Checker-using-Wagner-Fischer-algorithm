#include "..\include\Diccionario.h"
#include <fstream>
#include <cassert>


// Constructor
// --------------------------------------------------------------------------------------------------------------------
Diccionario::Diccionario() {
    Arreglo = NULL;
    longitud = 0;
}


// Destructor
// --------------------------------------------------------------------------------------------------------------------
Diccionario::~Diccionario() {
    if (Arreglo!=NULL)
        delete [] Arreglo;
}


// Funciones privadas
// --------------------------------------------------------------------------------------------------------------------
unsigned int Diccionario::filesize(ifstream & dicc) {
    unsigned int contador = 0;
    string iterador;

    dicc >> iterador;
    while (!dicc.eof()) {
        contador++;
        dicc >> iterador;
    }

    dicc.clear();
    dicc.seekg(0,dicc.beg);

    return contador;
}


void Diccionario::intercalar(unsigned int inicio,unsigned int medio,unsigned int fin) {
    string aux[fin-inicio+1];

    unsigned int i = inicio; // Indice de la primer mitad del arreglo
    unsigned int j = medio+1; // Indice de la segunda mitad del arreglo
    unsigned int k = 0; // Indice del arreglo aux

    // Intercala ambas mitades
    while ((i<=medio) && (j<=fin)) {

        if (Arreglo[i] < Arreglo[j]) {
            aux[k] = Arreglo[i];
            i++;
        }

        else {
            aux[k] = Arreglo[j];
            j++;
        }

        k++;
    }


    // Completa arreglo aux con los elementos que aun no copio de Arreglo
    while (i<=medio) {
        aux[k] = Arreglo[i];
        i++;
        k++;
    }

    while (j<=fin) {
        aux[k] = Arreglo[j];
        j++;
        k++;
    }

    // Copio el arreglo aux que ya esta ordenado, en el Arreglo original
    for (k = 0; k < (fin-inicio+1) ; k++)
        Arreglo[inicio+k] = aux[k];

}


void Diccionario::ordenar(unsigned int inicio,unsigned int fin) {
    if (inicio<fin) {
        int medio = (inicio+fin)/2;
        ordenar(inicio,medio);
        ordenar(medio+1,fin);
        intercalar(inicio,medio,fin);
    }
}


bool Diccionario::busquedaBinaria(int inicio, int fin, string dato) const {
    if (inicio > fin)
        return false;
    else {
        int medio = (inicio+fin)/2;
        if (Arreglo[medio] > dato)
            return busquedaBinaria(inicio,medio-1,dato);
        else if (Arreglo[medio] < dato)
            return busquedaBinaria(medio+1,fin,dato);
        else
            return true;
    }
}


bool Diccionario::buscarIndices(int & izq,int & der,char letra) const {

    int inicio = 0;
    int fin = longitud-1;
    int medio = (inicio+fin)/2;

    bool encontrado = false;

    // Busco la posicion de alguna palabra que comienze con la letra
    while ((inicio<=fin) && !encontrado) {

        if (Arreglo[medio][0] == letra)
            encontrado = true;

        else if (Arreglo[medio][0] > letra) {
            fin = medio-1;
            medio = (inicio+fin)/2;
        }

        else {
            inicio = medio+1;
            medio = (inicio+fin)/2;
        }
    }


    if (encontrado) {

        // Busco la posicion donde comienzan las palabras con esa letra
        izq = medio;
        while ( (inicio < izq) && (Arreglo[izq-1][0] == letra) )
            izq--;

        // Busco la posicion donde terminan las palabras con esa letra
        der = medio;
        while ( ( fin > der ) && (Arreglo[der+1][0] == letra) )
            der++;

        return true;

    }
    else
        return false;
}


// Modificadoras
// --------------------------------------------------------------------------------------------------------------------
void Diccionario::getPalabras(string ruta) {

    ifstream Dicc(ruta.c_str());
    assert(Dicc.is_open()); // Si hubo error al abrir, termina la ejecucion del programa.

    int N = filesize(Dicc);
    if (N>0) // Si N=0 -> el diccionario vino vacio.
    {
        // Inicializo los datos miembro
        Arreglo = new string[N];
        longitud = N;

        // Cargo el arreglo
        for (int k=0; k<N; k++)
            Dicc >> Arreglo[k];

        // Ordeno el Arreglo
        ordenar(0,N-1);
    }

    Dicc.close();
}


// Observadoras
// --------------------------------------------------------------------------------------------------------------------
bool Diccionario::esVacio() const {
    if (Arreglo==NULL)
        return true;
    else
        return false;
}


bool Diccionario::existe(string linea) const {
    if (longitud==0)
        return false;
    else
        return busquedaBinaria(0,longitud-1,linea);
}


void Diccionario::comienzaCon(char letra, Lista & resultado) const {
    if (longitud>0) {
        int izq,der;
        if ( buscarIndices(izq,der,letra) )
        // buscarIndices devuelve false si no hay ninguna palabra con esa letra,
        // si devuelve true, carga izq y der con los indices entre los que se encuentran todas las palabras con esa letra.
            for (int i=izq; i<=der ; i++)
                resultado.agregarLinea(Arreglo[i]);
    }
}
