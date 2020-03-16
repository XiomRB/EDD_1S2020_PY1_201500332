#include "Juego.h"

Juego::Juego()
{
    this->archi = new Archivo();
    this->fichasglobal = new FichasC();
    this->tablero = new TableroMD();
    this->j1 = 0;
    this->j2 = 0;
}

int Juego::pedirX(int dimension){
    int x;
    cout<< "Ingrese la coordenada x donde desea empezar su palabra" <<endl;
    cin>>x;
    if(x<dimension && x >0) return x;
    else return 0;
}
int Juego::pedirY(int dimension){
    int y;
    cout<< "Ingrese la coordenada y donde desea empezar su palabra" <<endl;
    cin>>y;
    if(y<dimension && y >0) return y;
    else return 0;
}

bool Juego::validarPalabra(string palabra){
    NodoLDC *aux = this->archi->dic->getPrimero();
    while(aux!=0){
        if(palabra.compare(aux->getDato())==0) return true;
        else aux = aux->getSig();
    }
    return false;
}

void Juego::darFichas(){
    NodoC *ficha;
    for(int i =0;i<7;i++){
        ficha = this->fichasglobal->eliminar();
        this->j1->fichas->insertar(ficha->getPunteo(),ficha->getLetra(),j1->getUsuario());
        ficha = this->fichasglobal->eliminar();
        this->j2->fichas->insertar(ficha->getPunteo(),ficha->getLetra(),j2->getUsuario());
    }
}

void Juego::insertarFichas(){
    vector<NodoM> fichasjugadas;

}

Juego::~Juego()
{
    //dtor
}
