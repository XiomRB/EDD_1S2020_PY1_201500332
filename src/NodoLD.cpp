#include "NodoLD.h"

NodoLD::NodoLD(char letra, int punteo)
{
    this->sig = 0;
    this->ant = 0;
    this->letra = letra;
    this->punteo = punteo;
}

NodoLD *NodoLD::getAnt(){
    return this->ant;
}

NodoLD *NodoLD::getSig(){
    return this->sig;
}

int NodoLD::getPunteo(){
    return this->punteo;
}

char NodoLD::getLetra(){
    return this->letra;
}
void NodoLD::setPunteo(int punteo){
    this->punteo = punteo;
}

void NodoLD::setLetra(char letra){
    this->letra = letra;
}
void NodoLD::setAnt(NodoLD *nodo){
    this->ant = nodo;
}

void NodoLD::setSig(NodoLD *nodo){
    this->sig = nodo;
}
NodoLD::~NodoLD()
{
    //dtor
}
