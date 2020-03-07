#include "NodoLDC.h"

NodoLDC::NodoLDC(string dato)
{
    this->ant = 0;
    this ->sig = 0;
    this->dato = dato;
}
void NodoLDC::setDato(string dato){
    this->dato = dato;
}
void NodoLDC::setAnt(NodoLDC *nodo){
    this->ant = nodo;
}
void NodoLDC::setSig(NodoLDC *nodo){
    this->sig = nodo;
}
NodoLDC *NodoLDC::getAnt(){
    return this->ant;
}
string NodoLDC::getDato(){
    return this->dato;
}
NodoLDC *NodoLDC::getSig(){
    return this->sig;
}
NodoLDC::~NodoLDC()
{
    //dtor
}
