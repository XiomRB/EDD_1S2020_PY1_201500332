#ifndef JUEGO_H
#define JUEGO_H
#include "NodoB.h"
#include "FichasC.h"
#include "TableroMD.h"
#include "Archivo.h"
#include <vector>
class Juego
{
    public:
        FichasC *fichasglobal;
        TableroMD *tablero;
        Archivo *archi;
        NodoB *j1;
        NodoB *j2;
        int puntaje1;
        int puntaje2;
        void agregarFichas();
        Juego();
        vector <NodoM *> fichasjugadas;
        void insertarFichas(int);
        bool validarPalabra(string palabra);
        int puntear();
        int pedirX(int);
        int pedirY(int);
        void insertarFichas();
        void darFichas();
        virtual ~Juego();

    protected:

    private:
        bool turno1;
};

#endif // JUEGO_H
