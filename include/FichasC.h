#ifndef FICHASC_H
#define FICHASC_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include "NodoC.h"
#include <sstream>
#include "UsuariosA.h"
#include <time.h>
using namespace std;

class FichasC
{
    public:
        FichasC();
        void insertar(char,int);
        NodoC *eliminar();
        void limpiar();
        NodoC *getPrimero();
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
