#include "include\CorrectorOrtografico.h"
#include <cassert>

int main(int argc, char* argv[])
{
    // Si argc es distinto de 4, se ha pasado una cantidad erronea de comandos
    assert(argc==4);

    // Guardo los comandos en variables de tipo string
    string RutaEntrada = argv[1];
    string RutaDiccionario = argv[2];
    string RutaSalida = argv[3];

    // Creo y cargo la instancia de Archivo de Entrada
    Archivo Entrada;
    Entrada.getPalabras(RutaEntrada);

    // Creo y cargo la instancia de Diccionario
    Diccionario Dicc;
    Dicc.getPalabras(RutaDiccionario);

    // Creo la instancia de Archivo donde se guardara el resultado
    Archivo Salida;

    // Carga Salida con las palabras corregidas.
    CorrectorOrtografico(Entrada,Dicc,Salida);

    // Guarda las palabras corregidas en el archivo de memoria secundaria
    Salida.guardar(RutaSalida);

    return 0;
}
