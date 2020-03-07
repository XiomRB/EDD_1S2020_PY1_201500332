#ifndef NODOC_H
#define NODOC_H
#include<iostream>
using namespace std;

class NodoC
{
    public:
        NodoC(char);
        char getLetra();
        void setLetra(char);
        NodoC *getSig();
        void setSig(NodoC *);
        virtual ~NodoC();

    protected:

    private:
        NodoC *sig;
        char letra;
};

#endif // NODOC_H
