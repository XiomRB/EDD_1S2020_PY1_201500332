#include "FichasC.h"

FichasC::FichasC()
{
    this->primero = 0;
    this->ultimo = 0;
}

void FichasC:: insertar(char letra){
    NodoC *nuevo = new NodoC(letra);
    if(primero==0){
        this->primero = nuevo;
        this->ultimo = nuevo;
    }else{
        this->ultimo->setSig(nuevo);
        this->ultimo = nuevo;
    }
}

NodoC *FichasC::eliminar(){
    NodoC *eliminado = primero;
    if(this->primero!=0){
        this->primero = this->primero->getSig();
    }
    return eliminado;
}

void FichasC::crearCola(){
    char letras[25] = {'A','B','C','D','E','F','G','H','I','J','L','M','N','Ñ','O','P','Q','R','S','T','U','V','X','Y','Z'};

}


FichasC::~FichasC()
{
    //dtor
}
