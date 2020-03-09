#ifndef NODOC_H
#define NODOC_H
#include<iostream>
using namespace std;

class NodoC
{
    public:
        NodoC(char,short);
        char getLetra();
        void setLetra(char);
        short getPunteo();
        NodoC *getSig();
        void setSig(NodoC *);
        virtual ~NodoC();

    protected:

    private:
        NodoC *sig;
        char letra;
        short punteo;
};

#endif // NODOC_H
