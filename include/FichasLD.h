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
        void insertar(int,char);
        NodoLD *eliminar(int);
        void modificar(int,char,int);
        string dibujar();
        string intCadena(int);
        virtual ~FichasLD();

    protected:

    private:
        NodoLD *primero;
        NodoLD *ultimo;
};

#endif // FICHASLD_H
