#ifndef USUARIOSA_H
#define USUARIOSA_H
#include "NodoB.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class UsuariosA
{
    public:
        UsuariosA();
        void insertar(string);
        string inorder();
        string preorder();
        string postorder();
        string dibujar();
        virtual ~UsuariosA();
        string dibujo;

    protected:

    private:
        NodoB *insertarAB(NodoB *,string);
        NodoB *raiz;
        void inorderAB(NodoB *);
        void preorderAB(NodoB *);
        void postorderAB(NodoB *);
        void dibujarAB(NodoB *);
};

#endif // USUARIOSA_H
