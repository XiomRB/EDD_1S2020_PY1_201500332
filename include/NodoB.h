#ifndef NODOB_H
#define NODOB_H
#include <iostream>
#include <string>
#include "FichasLD.h"
#include "PuntajesJugador.h"
using namespace std;

class NodoB
{
    public:
        NodoB(string);
        void setIzq(NodoB *);
        void setDer(NodoB *);
        NodoB *getIzq();
        NodoB *getDer();
        string getUsuario();
        PuntajesJugador *puntaje;
        FichasLD *fichas;
        virtual ~NodoB();

    protected:

    private:
        NodoB *izq;
        NodoB *der;
        string usuario;
};

#endif // NODOB_H
