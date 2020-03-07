#ifndef NODOJL_H
#define NODOJL_H
#include <iostream>
using namespace std;

class NodoJL
{
    public:
        NodoJL(int);
        void setPunteo(int);
        int getPunteo();
        void setSig(NodoJL *);
        NodoJL *getSig();
        virtual ~NodoJL();

    protected:

    private:
        int punteo;
        NodoJL *sig;
};

#endif // NODOJL_H
