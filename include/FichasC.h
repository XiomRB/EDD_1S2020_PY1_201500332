#ifndef FICHASC_H
#define FICHASC_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include "NodoC.h"
#include <sstream>
#include "UsuariosA.h"
using namespace std;

class FichasC
{
    public:
        FichasC();
        void insertar(char,short);
        NodoC *eliminar();
        void crearCola();
        string dibujar();
        virtual ~FichasC();

    protected:

    private:
        NodoC *primero;
        NodoC *ultimo;
        template <class T>
        string intCad(T);
};

#endif // FICHASC_H
