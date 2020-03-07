#include "NodoL.h"

NodoL::NodoL(int punteo,string jugador)
{
    this->punteo = punteo;
    this->sig = 0;
    this->jugador = jugador;
}

int NodoL::getPunteo(){
    return this->punteo;
}

string NodoL::getJugador(){
    return this->jugador;
}

NodoL *NodoL::getSig(){
    return this->sig;
}

void NodoL::setPunteo(int punteo){
    this->punteo = punteo;
}
void NodoL::setSig(NodoL *sig){
    this->sig = sig;
}
NodoL::~NodoL()
{
    //dtor
}
