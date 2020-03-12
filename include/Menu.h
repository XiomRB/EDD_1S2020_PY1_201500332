#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include "FichasC.h"
#include "TableroMD.h"
#include "Archivo.h"
#include <stdlib.h>
#include "UsuariosA.h"

using namespace std;

class Menu
{
    public:
        Menu();
        FichasC *fichasjuego;
        TableroMD *tablero;
        Archivo *arch;
        NodoB *jugador1;
        NodoB *jugador2;
        UsuariosA *usuarios;
        void pedirJugadores();
        bool configurado;
        void inicio();
        void configurar();
        void jugar();
        void crearUsuario();
        void reportar();
        virtual ~Menu();

    protected:

    private:
};

#endif // MENU_H
