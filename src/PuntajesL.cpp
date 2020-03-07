#include "PuntajesL.h"

PuntajesL::PuntajesL()
{
    this->primero = 0;
}

string PuntajesL::intCadena(int n){
    stringstream s;
    s.str("");
    s<<n;
    return s.str();
}
NodoL *PuntajesL::getPrimero(){
    return this->primero;
}

void PuntajesL::insertar(int punteo,string jugador){
    NodoL *nuevo = new NodoL(punteo,jugador);
    if(primero==0){
        primero = nuevo;
    }else{
        if(this->primero->getPunteo()<=punteo){
            nuevo->setSig(this->primero);
            this->primero = nuevo;
        }else{
            NodoL * aux = this->primero;
            while(aux->getSig()!=0 && aux->getSig()->getPunteo()>=punteo){
                aux = aux->getSig();
            }
            nuevo->setSig(aux->getSig());
            aux->setSig(nuevo);
        }
    }
}

string PuntajesL::dibujar(){
    string dibujo = "rankdir = LR;\n";
    stringstream s;
    int i = 0;
    NodoL *aux = this->primero;
    while(aux!=0){
        dibujo += this->intCadena(i) + "[label = \"" + aux->getJugador() + "," + this->intCadena(aux->getPunteo()) + "\"];\n";
        aux = aux->getSig();
        i++;
    }
    i = 0;
    aux = this->primero;
    while(aux->getSig()!=0){
        dibujo += this->intCadena(i) + " -> " + this->intCadena(i+1) + ";\n";
        aux = aux->getSig();
        i++;
    }
    dibujo += this->intCadena(i) + " -> NULL ;\n";
    return dibujo;
}
PuntajesL::~PuntajesL()
{
    //dtor
}
