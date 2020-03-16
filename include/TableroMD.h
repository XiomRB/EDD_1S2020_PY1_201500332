#ifndef TABLEROMD_H
#define TABLEROMD_H
#include "NodoM.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class TableroMD
{
    public:
        TableroMD();
        void insertar(int,int,char,int);
        NodoM *eliminar(int,int);
        string dibujar();
        virtual ~TableroMD();
    protected:

    private:
        NodoM *buscarCol(int);
        NodoM *buscarFila(int);
        NodoM *crearCol(int);
        NodoM *crearFila(int);
        NodoM *insertarCol(NodoM *,NodoM *);
        NodoM *insertarFila(NodoM *,NodoM *);
        template <class T>
        string intCadena(T);
        NodoM *raiz;
};

#endif // TABLEROMD_H
