#ifndef NODOL_H
#define NODOL_H
#include <iostream>
#include <string>
using namespace std;

class NodoL
{
    public:
        NodoL(int,string);
        void setPunteo(int);
        int getPunteo();
        string getJugador();
        void setSig(NodoL *);
        NodoL *getSig();
        virtual ~NodoL();

    protected:

    private:
        int punteo;
        NodoL *sig;
        string jugador;
};

#endif // NODOL_H
