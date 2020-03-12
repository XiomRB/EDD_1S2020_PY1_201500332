#include "NodoB.h"

NodoB::NodoB(string u)
{
    this->der = 0;
    this->izq = 0;
    this->usuario = u;
    this->fichas = new FichasLD();
    this->puntaje = new PuntajesJugador();
}

void NodoB::setDer(NodoB *n){
    this->der = n;
}
void NodoB::setIzq(NodoB *n){
    this->izq = n;
}
NodoB *NodoB::getDer(){
    return this->der;
}
NodoB *NodoB::getIzq(){
    return this->izq;
}
string NodoB::getUsuario(){
    return this->usuario;
}
NodoB::~NodoB()
{
    //dtor
}
