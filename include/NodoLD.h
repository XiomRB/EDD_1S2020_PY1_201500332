#ifndef NODOLD_H
#define NODOLD_H
#include<string>
#include<iostream>
using namespace std;

class NodoLD
{
    public:
        NodoLD(char,int,string);
        int getPunteo();
        char getLetra();
        string getJugador();
        void setPunteo(int);
        void setLetra(char);
        void setSig(NodoLD *);
        void setAnt(NodoLD *);
        NodoLD *getSig();
        NodoLD *getAnt();
        virtual ~NodoLD();

    protected:

    private:
        string jugador;
        int punteo;
        char letra;
        NodoLD *sig;
        NodoLD *ant;
};

#endif // NODOLD_H
