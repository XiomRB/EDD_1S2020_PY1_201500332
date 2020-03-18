#ifndef NODOC_H
#define NODOC_H
#include<iostream>
using namespace std;

class NodoC
{
    public:
        NodoC(char,int);
        char getLetra();
        void setLetra(char);
        int getPunteo();
        NodoC *getSig();
        void setSig(NodoC *);
        virtual ~NodoC();

    protected:

    private:
        NodoC *sig;
        char letra;
        int punteo;
};

#endif // NODOC_H
