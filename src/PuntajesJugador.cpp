#include "PuntajesJugador.h"

PuntajesJugador::PuntajesJugador()
{
    this->primero = 0;
}

string PuntajesJugador::intCadena(int n){
    stringstream s;
    s.str("");
    s<<n;
    return s.str();
}
NodoJL *PuntajesJugador::getPrimero(){
    return this->primero;
}

void PuntajesJugador::insertar(int punteo){
    NodoJL *nuevo = new NodoJL(punteo);
    if(primero==0){
        primero = nuevo;
    }else{
        if(this->primero->getPunteo()<=punteo){
            nuevo->setSig(this->primero);
            this->primero = nuevo;
        }else{
            NodoJL * aux = this->primero;
            while(aux->getSig()!=0 && aux->getSig()->getPunteo()>=punteo){
                aux = aux->getSig();
            }
            nuevo->setSig(aux->getSig());
            aux->setSig(nuevo);
        }
    }
}

string PuntajesJugador::dibujar(){
    string dibujo = "rankdir = LR;\n";
    stringstream s;
    int i = 0;
    NodoJL *aux = this->primero;
    while(aux!=0){
        dibujo += this->intCadena(i) + "[label = \"" + this->intCadena(aux->getPunteo()) + "\"];\n";
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
    dibujo += this->intCadena(i) + ";\n";
    return dibujo;
}

PuntajesJugador::~PuntajesJugador()
{
    //dtor
}
