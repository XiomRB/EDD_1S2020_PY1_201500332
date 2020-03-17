#include "Juego.h"

Juego::Juego()
{
    this->archi = new Archivo();
    this->fichasglobal = new FichasC();
    this->tablero = new TableroMD();
    this->j1 = 0;
    this->j2 = 0;
    this->puntaje1 = 0;
    this->puntaje2 = 0;
    this->turno1 = true;
}

int Juego::pedirX(int dimension){
    int x;
    cout<< "Ingrese la coordenada x donde desea empezar su palabra" <<endl;
    cin>>x;
    if(x<dimension && x >0) return x;
    else return -1;
}
int Juego::pedirY(int dimension){
    int y;
    cout<< "Ingrese la coordenada y donde desea empezar su palabra" <<endl;
    cin>>y;
    if(y<dimension && y >0) return y;
    else return -1;
}

bool Juego::validarPalabra(string palabra){
    NodoLDC *aux = this->archi->dic->getPrimero();
    while(aux!=0){
        if(aux->getDato().find(palabra)!= string::npos) return true;
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

void Juego::insertarFichas(int dim){
    int x,y;
    do{
        x = pedirX(dim);
        if(x == -1) cout<< "La coordenada x supera la dimension del tablero" <<endl;
    }while(x == -1);
    do{
        y = pedirY(dim);
        if(y == -1) cout<< "La coordenada y supera la dimension del tablero" <<endl;
    }while(y == -1);
    char l;
    cout<<"Que ficha desea jugar?"<<endl;
    NodoLD *ficha;
    if(this->turno1) {
        this->j1->fichas->mostrar();
        cin>>l;
        ficha = this->j1->fichas->eliminar(l);
        fichasjugadas.push_back(new NodoM(x,y,ficha->getLetra(),ficha->getPunteo()));
    }
    else {
        this->j2->fichas->mostrar();
        cin>>l;
        ficha = this->j2->fichas->eliminar(l);
        fichasjugadas.push_back(new NodoM(x,y,ficha->getLetra(),ficha->getPunteo()));
    }
    this->tablero->insertar(x,y,ficha->getLetra(),ficha->getPunteo());
    string tab = this->tablero->dibujar();
    this->archi->graficar("tablero",tab);
}

void Juego::jugar(){
    int op;
    cout<< "Desea 1) Intercambiar fichas 2) Crear palabra" <<endl;
    cin>>op;
    if(op ==1){//intercambia fichas

    }else{//juega palabra
        this->fichasjugadas.clear();
        do{
            this->insertarFichas(this->archi->dimension);
            cout<< "Desea 1) Validar    2) Insertar Ficha"<<endl;
            cin>>op;
        }while(op == 2);//hasta que desee validar palabra
        string palabra = "";
        NodoM *aux;
        for(int i = 0;i<fichasjugadas.size();i++){//leer palabra
            aux = fichasjugadas.at(i);
            palabra += this->tablero->intCadena(aux->getLetra());
        }
        if(!this->validarPalabra(palabra)){//si no se encuentra la palabra en el diccionario
            NodoM *ficha;
            for(int i = 0; i<fichasjugadas.size();i++){
                aux = fichasjugadas.at(i);
                ficha = this->tablero->eliminar(aux->getX(),aux->getY()); //eliminacion de cada ficha colocado
                if(turno1) j1->fichas->insertar(ficha->nn,ficha->getLetra(),j1->getUsuario()); //devolucion de fichas al jugador
                else j2->fichas->insertar(ficha->nn,ficha->getLetra(),j2->getUsuario());
            }
            palabra = this->tablero->dibujar();
            this->archi->graficar("tablero",palabra);
        }else{
            this->agregarFichas();
        }
    }
    if(turno1) turno1 = false;
    else turno1 = true;
}

int Juego::puntear(NodoM* m){
    int punteo = 0;
    Casilla *aux;
    int j = 0;
    bool encontrado =  false;
    while(!encontrado && j < this->archi->casillas.size()){
        aux = this->archi->casillas.at(j);
        if(aux->x == m->getX() && aux->y == m->getY()){
            punteo += (m->nn * aux->punteo);
            encontrado = true;
        }
        j++;
    }
    if(!encontrado) punteo += auxm->nn;

    return punteo;
}

void Juego::agregarFichas(){
    NodoC *aux;
    NodoM *auxm;
    for(int i = 0;i<fichasjugadas.size(),i++){
        auxm = fichasjugadas.at(i);
        aux = this->fichasglobal->eliminar();
        if(turno1){
            j1->fichas->insertar(aux->getPunteo(),aux->getLetra(),j1->getUsuario());
            puntaje1 += this->puntear();
        }
        else {
            j2->fichas->insertar(aux->getPunteo(),aux->getLetra(),j2->getUsuario());
            puntaje2 += this->puntear();
        }
    }
}
Juego::~Juego()
{
    //dtor
}
