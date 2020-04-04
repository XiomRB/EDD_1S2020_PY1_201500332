#ifndef PUNTAJESL_H
#define PUNTAJESL_H
#include "NodoL.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class PuntajesL
{
    public:
        PuntajesL();
        void limpiar();
        void insertar(int,string);
        string dibujar();
        NodoL *getPrimero();
        virtual ~PuntajesL();
        string intCadena(int);

    protected:

    private:
        NodoL *primero;
};

#endif // PUNTAJESL_H
