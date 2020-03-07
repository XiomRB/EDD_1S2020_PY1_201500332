#ifndef DICCIONARIOLDC_H
#define DICCIONARIOLDC_H
#include<NodoLDC.h>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

class DiccionarioLDC
{
    public:
        DiccionarioLDC();
        bool vacia();
        void insertar(string);
        void eliminar();
        bool buscar(string);
        string dibujarDiccionario();
        virtual ~DiccionarioLDC();

    protected:

    private:
        NodoLDC *primero;
        NodoLDC *ultimo;
};

#endif // DICCIONARIOLDC_H
