#ifndef PUNTAJESJUGADOR_H
#define PUNTAJESJUGADOR_H
#include "NodoJL.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class PuntajesJugador
{
    public:
        PuntajesJugador();
        void insertar(int);
        string dibujar();
        string intCadena(int);
        virtual ~PuntajesJugador();

    protected:

    private:
        NodoJL *primero;
};

#endif // PUNTAJESJUGADOR_H
