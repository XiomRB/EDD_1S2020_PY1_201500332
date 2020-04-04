#ifndef USUARIOSA_H
#define USUARIOSA_H
#include "NodoB.h"
#include <iostream>
#include <string>
#include <sstream>
#include "FichasLD.h"
#include "PuntajesL.h"

using namespace std;

class UsuariosA
{
    public:
        UsuariosA();
        PuntajesL *scoreboard;
        void darScoreRec(NodoB *);
        void darScore();
        void insertar(string);
        string inorder();
        string preorder();
        string postorder();
        string dibujar();
        virtual ~UsuariosA();
        string dibujo;
        NodoB *getRaiz();
        NodoB *getJugador(string);


    protected:

    private:
        NodoB *raiz;
        NodoB *insertarAB(NodoB *,string);
        void inorderAB(NodoB *);
        void preorderAB(NodoB *);
        void postorderAB(NodoB *);
        void dibujarAB(NodoB *);
};

#endif // USUARIOSA_H
