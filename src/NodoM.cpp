#include "NodoM.h"

NodoM::NodoM(int x,int y, char letra,int p)
{
    this->abajo = 0;
    this->ant = 0;
    this->arriba = 0;
    this->sig = 0;
    this->x = x;
    this->y = y;
    this->letra = letra;
    this->nn = p;
}

NodoM *NodoM::getAnt(){
    return this->ant;
}

NodoM *NodoM::getSig(){
    return this->sig;
}

NodoM *NodoM::getAbajo(){
    return this->abajo;
}

NodoM *NodoM::getArriba(){
    return this->arriba;
}

int NodoM::getX(){
    return this->x;
}

int NodoM::getY(){
    return this->y;
}

char NodoM::getLetra(){
    return this->letra;
}

void NodoM::setAbajo(NodoM *nodo){
    this->abajo = nodo;
}

void NodoM::setArriba(NodoM *nodo){
    this->arriba = nodo;
}

void NodoM::setAnt(NodoM *nodo){
    this->ant = nodo;
}

void NodoM::setSig(NodoM *nodo){
    this->sig = nodo;
}

void NodoM::setX(int x){
    this->x = x;
}

void NodoM::setY(int y){
    this->y = y;
}

void NodoM::setLetra(char letra){
    this->letra = letra;
}
NodoM::~NodoM()
{
    //dtor
}
