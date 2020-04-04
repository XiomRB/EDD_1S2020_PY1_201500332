#ifndef FICHASLD_H
#define FICHASLD_H
#include <iostream>
#include "NodoLD.h"
#include <string>
#include <sstream>
using namespace std;

class FichasLD
{
    public:
        FichasLD();
        void insertar(int,char,string);
        NodoLD *eliminar(char);
        void modificar(int,char,NodoLD *);
        NodoLD *buscar(char);
        string dibujar();
        string intCadena(int);
        void mostrar();
        virtual ~FichasLD();
        NodoLD *getPrimero();
        void limpiar();

    protected:

    private:
        NodoLD *primero;
        NodoLD *ultimo;
};

#endif // FICHASLD_H
