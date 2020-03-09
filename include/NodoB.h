#ifndef NODOB_H
#define NODOB_H
#include <iostream>
#include <string>
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
        virtual ~NodoB();

    protected:

    private:
        NodoB *izq;
        NodoB *der;
        string usuario;
};

#endif // NODOB_H
