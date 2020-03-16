#include "DiccionarioLDC.h"

DiccionarioLDC::DiccionarioLDC()
{
    this->primero = 0;
    this->ultimo = 0;
}

bool DiccionarioLDC::vacia(){
    if(this->primero==0) return true;
    else return false;
}
NodoLDC *DiccionarioLDC::getPrimero(){
    return this->primero;
}

void DiccionarioLDC::insertar(string p){
    string palabra = "";
    for(short i = 0; i <p.size(); i++){
        palabra  += toupper(p[i]);
    }
    NodoLDC *nuevo = new NodoLDC(palabra);
    if(this->vacia()){
        this->primero = nuevo;
        this->ultimo = nuevo;
        this->primero->setSig(this->ultimo);
        this->ultimo->setAnt(this->primero);
    }else{
        nuevo->setAnt(this->ultimo);
        this->ultimo->setSig(nuevo);
        this->ultimo = nuevo;
    }
    this->ultimo->setSig(this->primero);
    this->primero->setAnt(this->ultimo);
}

void DiccionarioLDC::eliminar(){
    this->primero = 0;
    this->primero->setSig(0);
    this->ultimo = 0;
    this->ultimo->setAnt(0);
}

bool DiccionarioLDC::buscar(string palabra){
    if(this->vacia()) return false;
    else{
            NodoLDC *aux = this->primero;
        do{
            if(palabra.compare(aux->getDato())==0) return true;
            aux = aux->getSig();
        }while(aux != this->primero);
    }
    return false;
}

string DiccionarioLDC::dibujarDiccionario(){
    NodoLDC *aux = this->primero;
    stringstream s;
    int i = 0;
    string n="";
    string dibujo = "node [shape = record];\n";
    do{
        s.str("");
        s<<i;
        n = s.str();
        dibujo += n + "[label = \"<f0>|<f1> " + aux->getDato() + "|<f2> \"" + ";\n";
        aux = aux->getSig();
        i++;
    }while(aux != this->primero);
    aux = this->primero;
    i = 0;
    string n1 = "";
    do{
        s.str("");
        s<<i;
        n = s.str();
        s.str("");
        i++;
        s<<i;
        n1 = s.str();
        i--;
        dibujo += n + "->" + n1 + ";\n";
        aux = aux->getSig();
        i++;
    }while(aux != this->ultimo);
    aux = this->ultimo;
    do{
        s.str("");
        s<<i;
        n = s.str();
        s.str("");
        i--;
        s<<i;
        n1 = s.str();
        i++;
        dibujo += n+ "->" + n1 + ";\n";
        aux = aux->getAnt();
        i--;
    }while(aux != this->primero);
    return dibujo;
}

DiccionarioLDC::~DiccionarioLDC()
{
    //dtor
}
