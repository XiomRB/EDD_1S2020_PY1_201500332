#ifndef NODOLDC_H
#define NODOLDC_H
#include <iostream>
#include <string>
using namespace std;

class NodoLDC
{
    public:
        NodoLDC(string);
        NodoLDC *getSig();
        void setSig(NodoLDC *);
        NodoLDC *getAnt();
        void setAnt(NodoLDC *);
        string getDato();
        void setDato(string);
        virtual ~NodoLDC();

    protected:

    private:
        string dato;
        NodoLDC *sig;
        NodoLDC *ant;
};

#endif // NODOLDC_H
