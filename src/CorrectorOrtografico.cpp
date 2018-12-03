#include "..\include\CorrectorOrtografico.h"


int WagnerFischer(string p1, string p2)
{
    unsigned int f, c;

    int Matriz[p1.length()+1][p2.length()+1];       // Matriz de (N+1)x(M+1) siendo M y N la longitud de los string

    for(c=0 ; c<=p2.length() ; c++)
        Matriz[0][c]= c;                // Rellena la primera fila con el numero de fila

    for(f=0 ; f<=p1.length() ; f++)
        Matriz[f][0]=f;                 // Rellena la primera columna con el numero de columna

    for(c=1 ; c<=p2.length() ; c++)
        for(f=1 ; f<=p1.length() ; f++)
            if(p1[f-1]==p2[c-1])
                Matriz[f][c]=Matriz[f-1][c-1];
            else
                Matriz[f][c]= min( Matriz[f-1][c-1] , min( Matriz[f][c-1] , Matriz[f-1][c] ) ) +1;


    return Matriz[p1.length()][p2.length()];
}


string minimaDistancia(Lista & Resultado, string palabra) {

    string dato1,dato2;
    int distancia1,distancia2;

    Resultado.setearActual();

    // Cargo informacion del primer string de la Lista Resultado
    Resultado.devolverActual(dato1);
    distancia1 = WagnerFischer(palabra,dato1);

    // Si existen mas elementos en la Lista, entonces los comparo, dejando siempre en dato1 la palabra con menor distancia
    bool existe = Resultado.devolverActual(dato2);
    while (existe) {
        distancia2 = WagnerFischer(palabra,dato2);
        if (distancia2 < distancia1) {
            distancia1 = distancia2;
            dato1 = dato2;
        }
        existe = Resultado.devolverActual(dato2);
    }

    return dato1;
}


void CorrectorOrtografico(Archivo & Entrada,const Diccionario & Dicc,Archivo & Salida) {

    string palabra;
    Lista * Resultado;

    Entrada.setearActual();
    bool existe = Entrada.devolverActual(palabra);

    while (existe) {

        if ( Dicc.existe(palabra) )
            Salida.agregarLinea(palabra);

        else {
            Resultado = new Lista;
            Dicc.comienzaCon(palabra[0],*Resultado);
            if (Resultado->esVacio())
                Salida.agregarLinea(palabra);
            else
                Salida.agregarLinea( minimaDistancia(*Resultado,palabra) );
            delete Resultado;
        }

        existe = Entrada.devolverActual(palabra);
    }
}
