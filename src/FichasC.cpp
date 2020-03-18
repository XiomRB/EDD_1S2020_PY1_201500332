#include "FichasC.h"

FichasC::FichasC()
{
    this->primero = 0;
    this->ultimo = 0;
}

NodoC *FichasC::getPrimero(){
    return this->primero;
}

void FichasC:: insertar(char letra,int punteo){
    NodoC *nuevo = new NodoC(letra,punteo);
    if(primero==0){
        this->primero = nuevo;
        this->ultimo = nuevo;
    }else{
        this->ultimo->setSig(nuevo);
        this->ultimo = nuevo;
    }
}
void FichasC::limpiar(){
    this->primero = 0;
}

NodoC *FichasC::eliminar(){
    NodoC *eliminado = primero;
    if(this->primero!=0){
        this->primero = this->primero->getSig();
    }
    return eliminado;
}

void FichasC::crearCola(){
    int rango[25] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char letras[25] = {'A','B','C','D','E','F','G','H','I','J','L','M','N','Ñ','O','P','Q','R','S','T','U','V','X','Y','Z'};
    int i =0;
    char l = ' ';
    while(i <95){
        l = letras[rand()%25];
        if(l == 'A' && rango[0]<12){
            this->insertar(l,1);
            rango[0]++;
            i++;
        }else if(l == 'B' && rango[1]<2){
            this->insertar(l,3);
            rango[1]++;
            i++;
        }else if(l == 'C' && rango[2]<4){
            this->insertar(l,3);
            rango[2]++;
            i++;
        }else if(l == 'D' && rango[3]<5){
            this->insertar(l,2);
            rango[3]++;
            i++;
        }else if(l == 'E' && rango[4]<12){
            this->insertar(l,1);
            rango[4]++;
            i++;
        }else if(l == 'F' && rango[5]<1){
            this->insertar(l,4);
            rango[5]++;
            i++;
        }else if(l == 'G' && rango[6]<2){
            this->insertar(l,2);
            rango[6]++;
            i++;
        }else if(l == 'H' && rango[7]<2){
            this->insertar(l,4);
            rango[7]++;
            i++;
        }else if(l == 'I' && rango[8]<6){
            this->insertar(l,1);
            rango[8]++;
            i++;
        }else if(l == 'J' && rango[9]<1){
            this->insertar(l,8);
            rango[9]++;
            i++;
        }else if(l == 'L' && rango[10]<4){
            this->insertar(l,1);
            rango[10]++;
            i++;
        }else if(l == 'M' && rango[11]<2){
            this->insertar(l,3);
            rango[11]++;
            i++;
        }else if(l == 'N' && rango[12]<5){
            this->insertar(l,1);
            rango[12]++;
            i++;
        }else if(l == 'Ñ' && rango[13]<1){
            this->insertar(l,8);
            rango[13]++;
            i++;
        }else if(l == 'O' && rango[14]<9){
            this->insertar(l,1);
            rango[14]++;
            i++;
        }else if(l == 'P' && rango[15]<2){
            this->insertar(l,3);
            rango[15]++;
            i++;
        }else if(l == 'Q' && rango[16]<1){
            this->insertar(l,5);
            rango[16]++;
            i++;
        }else if(l == 'R' && rango[17]<5){
            this->insertar(l,1);
            rango[17]++;
            i++;
        }else if(l == 'S' && rango[18]<6){
            this->insertar(l,1);
            rango[18]++;
            i++;
        }else if(l == 'T' && rango[19]<4){
            this->insertar(l,1);
            rango[19]++;
            i++;
        }else if(l == 'U' && rango[20]<5){
            this->insertar(l,1);
            rango[20]++;
            i++;
        }else if(l == 'V' && rango[21]<1){
            this->insertar(l,4);
            rango[21]++;
            i++;
        }else if(l == 'X' && rango[22]<1){
            this->insertar(l,8);
            rango[22]++;
            i++;
        }else if(l == 'Y' && rango[23]<1){
            this->insertar(l,4);
            rango[23]++;
            i++;
        }else if(l == 'Z' && rango[24]<1){
            this->insertar(l,10);
            rango[24]++;
            i++;
        }
    }
}
template <class T>
string FichasC::intCad(T n){
    stringstream s;
    s.str("");
    s<<n;
    return s.str();
}
string FichasC::dibujar(){
    string dibujo = "cola [shape = none, margin = 0, label=<";
    dibujo += "\n <TABLE BORDER = \"0\" CELLBORDER = \"1\" CELLSPACING=\"0\"> \n";
    NodoC *aux = this->primero;
    while(aux!=0){
        dibujo += "<TR> <TD>" + this->intCad(aux->getLetra()) + ", " + this->intCad(aux->getPunteo()) + "</TD></TR>\n";
        aux = aux->getSig();
    }
    dibujo += "</TABLE>>];\n";
    return dibujo;
}

FichasC::~FichasC()
{
    //dtor
}
