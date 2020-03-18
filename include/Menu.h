#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Juego.h"

using namespace std;

class Menu
{
    public:
        Menu();
        Juego *juego;
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
