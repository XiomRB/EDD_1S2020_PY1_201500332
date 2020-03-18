#include "NodoC.h"

NodoC::NodoC(char letra,int punteo)
{
    this->letra = letra;
    this->sig = 0;
    this->punteo = punteo;
}

int NodoC::getPunteo(){
    return this->punteo;
}

NodoC *NodoC::getSig(){
    return this->sig;
}

char NodoC::getLetra(){
    return this->letra;
}

void NodoC::setLetra(char letra){
    this->letra = letra;
}

void NodoC::setSig(NodoC *sig){
    this->sig = sig;
}
NodoC::~NodoC()
{
    //dtor
}
