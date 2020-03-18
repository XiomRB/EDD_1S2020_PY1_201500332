#ifndef JUEGO_H
#define JUEGO_H
#include "NodoB.h"
#include "FichasC.h"
#include "TableroMD.h"
#include "Archivo.h"
#include <vector>
#include "PuntajesL.h"
#include "UsuariosA.h"
class Juego
{
    public:
        FichasC *fichasglobal;
        UsuariosA *usuarios;
        TableroMD *tablero;
        Archivo *archi;
        NodoB *j1;
        NodoB *j2;
        int puntaje1;
        int puntaje2;
        void agregarFichas();
        PuntajesL *scoreboard;
        void Partida();
        Juego();
        void jugar();
        void intercambiarFichas();
        vector <NodoM *> fichasjugadas;
        void insertarFichas(int);
        bool validarPalabra(string palabra);
        int puntear(NodoM *);
        int pedirX(int);
        int pedirY(int);
        void insertarFichas();
        void reportar();
        void darFichas();
        virtual ~Juego();
        bool fin;

    protected:

    private:
        bool turno1;
};

#endif // JUEGO_H
