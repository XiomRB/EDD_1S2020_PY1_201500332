#ifndef JUEGO_H
#define JUEGO_H
#include "NodoB.h"
#include "FichasC.h"
#include "TableroMD.h"
#include "Archivo.h"
class Juego
{
    public:
        FichasC *fichasglobal;
        TableroMD *tablero;
        Archivo *archi;
        NodoB *j1;
        NodoB *j2;
        Juego();
        bool validarPalabra(string palabra);
        int puntear();
        int pedirX(int);
        int pedirY(int);
        void insertarFichas();
        void darFichas();
        virtual ~Juego();

    protected:

    private:
};

#endif // JUEGO_H
