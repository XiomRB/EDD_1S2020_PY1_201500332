#ifndef FICHASC_H
#define FICHASC_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include "NodoC.h"
using namespace std;

class FichasC
{
    public:
        FichasC();
        void insertar(char letra);
        NodoC *eliminar();
        void crearCola();
        virtual ~FichasC();

    protected:

    private:
        NodoC *primero;
        NodoC *ultimo;
};

#endif // FICHASC_H
