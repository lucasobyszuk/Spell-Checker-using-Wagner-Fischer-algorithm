#ifndef CORRECTORORTOGRAFICO_H_INCLUDED
#define CORRECTORORTOGRAFICO_H_INCLUDED

#include "Archivo.h"
#include "Diccionario.h"

// Calcula la distancia entre p1 y p2
int WagnerFischer(string p1,string p2);

// Devuelve el string de la Lista que tenga menor distancia con palabra
string minimaDistancia(Lista & resultado, string palabra);

// Agrega a Salida las palabras corregidas
void CorrectorOrtografico(Archivo & Entrada,const Diccionario & Dicc,Archivo & Salida);

#endif // CORRECTORORTOGRAFICO_H_INCLUDED
