#include "TableroMD.h"

TableroMD::TableroMD()
{
    this->raiz = new NodoM(-1,-1,'R',-1);
    this->tam = 0;
}

NodoM *TableroMD::buscarCol(int x){
    NodoM *aux = this->raiz;
    while(aux!= 0){
        if(aux->getX() == x) return aux;
        aux = aux->getSig();
    }
    return 0;
}

NodoM *TableroMD::buscarFila(int y){
    NodoM *aux = this->raiz;
    while(aux!= 0){
        if(aux->getY() == y) return aux;
        aux = aux->getAbajo();
    }
    return 0;
}

NodoM *TableroMD::insertarCol(NodoM *nuevo,NodoM *cabezacol){
    NodoM *aux = cabezacol;
    while(aux->getSig()!=0){
        aux = aux->getSig();
        if(aux->getX()==nuevo->getX()){
            aux->setY(nuevo->getY());
            aux->setLetra(nuevo->getLetra());
            return aux;
        } else if(aux->getX() > nuevo->getX()){
            nuevo->setSig(aux);
            aux->getAnt()->setSig(nuevo);
            nuevo->setAnt(aux->getAnt());
            aux->setAnt(nuevo);
            return nuevo;
        }
    }
    if(aux->getSig()==0) {
        aux->setSig(nuevo);
        nuevo->setAnt(aux);
    }
    return nuevo;
}

NodoM *TableroMD::insertarFila(NodoM *nuevo,NodoM *cabezafila){
    NodoM *aux = cabezafila;
    while(aux->getAbajo()!=0){
        aux = aux->getAbajo();
        if(aux->getY()==nuevo->getY()){
            aux->setX(nuevo->getX());
            aux->setLetra(nuevo->getLetra());
            return aux;
        } else if(aux->getY() > nuevo->getY()){
            nuevo->setAbajo(aux);
            aux->getArriba()->setAbajo(nuevo);
            nuevo->setArriba(aux->getArriba());
            aux->setArriba(nuevo);
            return nuevo;
        }
    }
    if(aux->getAbajo()==0){
        aux->setAbajo(nuevo);
        nuevo->setArriba(aux);
    }
    return nuevo;
}

NodoM *TableroMD::crearCol(int x){
    NodoM *cabezacol = this->raiz;
    NodoM *col = insertarCol(new NodoM(x,-1,'C',this->tam),cabezacol);
    this->tam ++;
    return col;
}

NodoM *TableroMD::crearFila(int y){
    NodoM *cabezafila = this->raiz;
    NodoM *fila = insertarFila(new NodoM(-1,y,'F',this->tam),cabezafila);
    this->tam++;
    return fila;
}

void TableroMD::insertar(int x,int y, char letra){
    NodoM *nuevo = new NodoM(x,y,letra,this->tam);
    this->tam++;
    NodoM *nodocol = this->buscarCol(x);
    NodoM *nodofila = this->buscarFila(y);
    if(nodocol == 0 && nodofila == 0){
        nodocol = this->crearCol(x);
        nodofila = this->crearFila(y);
        nuevo = this->insertarCol(nuevo,nodofila);
        nuevo = this->insertarFila(nuevo,nodocol);
    }else if(nodocol == 0 && nodofila!=0){
        nodocol = this->crearCol(x);
        nuevo = this->insertarCol(nuevo,nodofila);
        nuevo = this->insertarFila(nuevo,nodocol);
    }else if(nodocol!=0 && nodofila==0){
        nodofila = this->crearFila(y);
        nuevo = this->insertarCol(nuevo,nodofila);
        nuevo = this->insertarFila(nuevo,nodocol);
    }else{
        nuevo = this->insertarCol(nuevo,nodofila);
        nuevo = this->insertarFila(nuevo,nodocol);
    }
}

NodoM *TableroMD::eliminar(int x,int y){
    NodoM *nodofila = this->buscarFila(y);
    while(nodofila!=0){
        if(nodofila->getX() == x){
            nodofila->getAnt()->setSig(nodofila->getSig());
            nodofila->getSig()->setAnt(nodofila->getAnt());
            nodofila->getArriba()->setAbajo(nodofila->getAbajo());
            nodofila->getAbajo()->setArriba(nodofila->getArriba());
            return nodofila;
        }
        nodofila = nodofila->getSig();
    }
    return 0;
}

string TableroMD::dibujar(){
    NodoM *aux = this->raiz;
    string dibujo = "";
    string lineal = "{ rank = same ";
    lineal += "\"Matriz\" ";
    while(aux->getSig()!=0){
        aux = aux->getSig();
        dibujo += this->intCadena(aux->nn) + " [label = \"" + this->intCadena(aux->getX()) + "\"];\n";
    }
    aux = this->raiz;
    while(aux->getAbajo()!=0){
        aux = aux->getAbajo();
        dibujo += this->intCadena(aux->nn) + " [label = \"" + this->intCadena(aux->getY()) + "\"];\n";
    }
    aux = this->raiz;
    while(aux->getAbajo()!=0){
        aux = aux->getAbajo();
        NodoM *aux3 = aux;
        while(aux3->getSig()!=0){
            aux3 = aux3->getSig();
            dibujo += this->intCadena(aux3->nn) + " [label = \"" + this->intCadena(aux3->getLetra()) + "\"];\n";
        }
    }
    //cabecera X
    aux = this->raiz;
    dibujo += "\"Matriz\"";
    while(aux->getSig() != 0){
        aux =aux->getSig();
        dibujo += " -> " + this->intCadena(aux->nn);
        lineal += this->intCadena(aux->nn) + " ";
    }
    lineal += "}";
    while(aux->getAnt()->getAnt() != 0){
        aux = aux->getAnt();
        dibujo += " -> " + this->intCadena(aux->nn);
    }
    dibujo += " -> \"Matriz\";\n";
    dibujo += lineal + "\n";
    lineal = "{ rank = same ";
    //filas
    aux = this->raiz->getAbajo();
    while(aux!=0){
        dibujo += this->intCadena(aux->nn);
        lineal += this->intCadena(aux->nn);
        NodoM *aux1 = aux;
        while(aux1->getSig()!=0){
            aux1 = aux1->getSig();
            dibujo += " -> " + this->intCadena(aux1->nn);
            lineal += " " + this->intCadena(aux1->nn);
        }
        while(aux1->getAnt()->getAnt()!=0){
            aux1 = aux1->getAnt();
            dibujo += " -> " + this->intCadena(aux1->nn);
        }
        dibujo += " -> " + this->intCadena(aux->nn) + ";\n";
        lineal += " }";
        dibujo += lineal + "\n";
        lineal = "{rank = same ";
        aux = aux->getAbajo();
    }
    //cabecera Y
    aux = this->raiz;
    dibujo += "\"Matriz\"";
    while(aux->getAbajo() !=0){
        aux = aux->getAbajo();
        dibujo += " -> " + this->intCadena(aux->nn);
    }
    while(aux->getArriba()->getArriba() !=0){
        aux = aux->getArriba();
        dibujo += " -> " + this->intCadena(aux->nn);
    }
    dibujo += " -> \"Matriz\";\n";
    //columnas
    aux = this->raiz->getSig();
    while(aux!=0){
        dibujo += this->intCadena(aux->nn);
        NodoM *aux2 = aux;
        while(aux2->getAbajo()!=0){
            aux2 = aux2->getAbajo();
            dibujo += " -> " + this->intCadena(aux2->nn);
        }
        while(aux2->getArriba()->getArriba()!=0){
            aux2 = aux2->getArriba();
            dibujo += " -> " + this->intCadena(aux2->nn);
        }
        dibujo += " -> " + this->intCadena(aux->nn) + ";\n";
        aux = aux->getSig();
    }
    return dibujo;
}

template <class T>
string TableroMD::intCadena(T n){
    stringstream s;
    s.str("");
    s<<n;
    return s.str();
}

TableroMD::~TableroMD()
{
    //dtor
}
