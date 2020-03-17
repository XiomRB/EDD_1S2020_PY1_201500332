#include "FichasLD.h"

FichasLD::FichasLD()
{
    this->ultimo = 0;
    this->primero = 0;
}

void FichasLD::insertar(int punteo,char letra,string jugador){
    NodoLD *nuevo = new NodoLD(letra,punteo,jugador);
    if(this->primero ==0) {
        this->primero = nuevo;
        this->ultimo = nuevo;
    }
    else{
        nuevo->setAnt(this->ultimo);
        this->ultimo->setSig(nuevo);
        this->ultimo = nuevo;
    }
}

NodoLD *FichasLD::eliminar(char n){
    if(this->primero!=0){
        NodoLD *aux = this->primero;
        while(n != aux->getLetra()){
            aux = aux->getSig();
        }
        aux->getAnt()->setSig(aux->getSig());
        aux->getSig()->setAnt(aux->getAnt());
        aux->setAnt(0);
        aux->setSig(0);
        return aux;
    }
    return 0;
}

void FichasLD::mostrar(){
    NodoLD *aux = this->primero;
    while(aux!=0){
        cout<< aux->getLetra() << " ";
        aux = aux->getSig();
    }
}

void FichasLD::modificar(int punteo,char letra,int n){
    if(this->primero!=0){
        NodoLD *aux = this->primero;
        int i = 0;
        while(i<n){
            aux = aux->getSig();
            i++;
        }
        aux->setLetra(letra);
        aux->setPunteo(punteo);
    }
}

string FichasLD::dibujar(){
    string dibujo="rankdir = LR;\n";
    NodoLD *aux = this->primero;
    int i = 0;
    while(aux!=0){
        dibujo += intCadena(i) + "[label = \"" + aux->getLetra() + "\"];\n";
        i++;
        aux = aux->getSig();
    }
    i = 0;
    aux = this->primero;
    while(aux->getSig() !=0){
        dibujo += intCadena(i) + " -> " + intCadena(i+1) + ";\n";
        i++;
        aux = aux->getSig();
    }
    dibujo += intCadena(i) + " -> NULL;\n";
    return dibujo;
}

string FichasLD::intCadena(int n){
    stringstream s;
    s.str("");
    s<<n;
    return s.str();
}

FichasLD::~FichasLD()
{
    //dtor
}
