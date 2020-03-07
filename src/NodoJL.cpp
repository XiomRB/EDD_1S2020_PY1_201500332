#include "NodoJL.h"

NodoJL::NodoJL(int punteo)
{
    this->punteo = punteo;
    this->sig = 0;
}

int NodoJL::getPunteo(){
    return this->punteo;
}

NodoJL *NodoJL::getSig(){
    return this->sig;
}

void NodoJL::setPunteo(int punteo){
    this->punteo = punteo;
}
void NodoJL::setSig(NodoJL *sig){
    this->sig = sig;
}

NodoJL::~NodoJL()
{
    //dtor
}
