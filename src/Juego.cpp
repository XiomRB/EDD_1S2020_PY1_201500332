#include "Juego.h"

Juego::Juego()
{
    this->archi = new Archivo();
    this->usuarios = new UsuariosA();
    this->fichasglobal = new FichasC();
    this->scoreboard = new PuntajesL();
    this->j1 = 0;
    this->j2 = 0;
    this->puntaje1 = 0;
    this->puntaje2 = 0;
    this->turno1 = true;
    this->fin = false;
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
    do{
        if(aux->getDato().find(palabra)!= string::npos) return true;
        aux = aux->getSig();
    }while(aux!=this->archi->dic->getPrimero());
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
        cout<<endl;
        cin>>l;
        ficha = this->j1->fichas->eliminar(l);
        fichasjugadas.push_back(new NodoM(x,y,ficha->getLetra(),ficha->getPunteo()));
    }
    else {
        this->j2->fichas->mostrar();
        cout<<endl;
        cin>>l;
        ficha = this->j2->fichas->eliminar(l);
        fichasjugadas.push_back(new NodoM(x,y,ficha->getLetra(),ficha->getPunteo()));
    }
    this->tablero->insertar(x,y,ficha->getLetra(),ficha->getPunteo());
    string tab = this->tablero->dibujar();
    this->archi->graficar("tablero",tab);
}

void Juego::jugar(){
    system("cls");
    if(turno1) cout<< "Turno " << j1->getUsuario()<<endl;
        else cout<< "Turno " << j2->getUsuario()<<endl;
    int op;
    cout<< "Desea 1) Intercambiar fichas    2) Crear palabra " <<endl;
    cin>>op;
    if(op ==1){//intercambia fichas
        this->intercambiarFichas();
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
            palabra.push_back(aux->getLetra());
        }
        if(!this->validarPalabra(palabra)){//si no se encuentra la palabra en el diccionario
            NodoM *ficha;
            for(int i = 0; i<fichasjugadas.size();i++){
                aux = fichasjugadas.at(i);
                ficha = this->tablero->eliminar(aux->getX(),aux->getY()); //eliminacion de cada ficha colocado
                cout<<aux->getLetra();
                if(turno1) j1->fichas->insertar(ficha->nn,ficha->getLetra(),j1->getUsuario()); //devolucion de fichas al jugador
                else j2->fichas->insertar(ficha->nn,ficha->getLetra(),j2->getUsuario());
            }
            cout<<"Palabra no valida"<<endl;
            palabra = this->tablero->dibujar();
            this->archi->graficar("tablero",palabra);
        }else{
            this->agregarFichas();
            cout<<"Palabra Valida"<<endl;
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
        if(aux->x == m->getX() && aux->y == m->getY()){//verificacion de casillas dobles o triples
            punteo += (m->nn * aux->punteo);
            encontrado = true;
        }
        j++;
    }
    if(!encontrado) punteo += m->nn;

    return punteo;
}

void Juego::agregarFichas(){
    NodoC *aux;
    NodoM *auxm;
    for(int i = 0;i<fichasjugadas.size();i++){
        auxm = fichasjugadas.at(i);
        if(&this->fichasglobal->getPrimero == 0){
            if(turno1) puntaje1 += this->puntear(auxm);
            else puntaje2 += this->puntear(auxm);
        }else{
            aux = this->fichasglobal->eliminar();
            if(turno1){
                j1->fichas->insertar(aux->getPunteo(),aux->getLetra(),j1->getUsuario());//agregar fichas al usuario
                puntaje1 += this->puntear(auxm);//dar puntaje
            }else {
                j2->fichas->insertar(aux->getPunteo(),aux->getLetra(),j2->getUsuario());
                puntaje2 += this->puntear(auxm);
            }
        }
    }
}

void Juego::Partida(){
    this->fichasglobal->limpiar();
    this->fichasglobal->crearCola();
    this->tablero = new TableroMD();
    this->darFichas();
    int op;
    do{
        system("cls");
        if(turno1) cout<< "Turno " << j1->getUsuario()<<endl;
        else cout<< "Turno " << j2->getUsuario()<<endl;
        cout<< "Desea 1) Jugar    2) Terminar juego    3)Ver Reportes"<<endl;
        cin>>op;
        if(!this->fichasglobal->getPrimero()==0 && op ==1)this->jugar();
        else if(op == 3){
            this->reportar();
        }else{
            op == 2;
            this->j1->puntaje->insertar(this->puntaje1);
            this->j2->puntaje->insertar(this->puntaje2);
        }
    }while(op==1 || op ==3);
}

void Juego::intercambiarFichas(){
    int f;
    char l;
    NodoC *aux;
    cout<< "Cuantas fichas desea intercambiar?" <<endl;
    cin>>f;
    for(int i =0; i<f; i++){
        aux = this->fichasglobal->eliminar();
        cout<< "Cual de sus fichas desea intercambiar?" <<endl;
        NodoLD *auxld;
        if(turno1){
            this->j1->fichas->mostrar();
            cout<<endl;
            cin>>l;
            auxld = j1->fichas->buscar(l);
            this->fichasglobal->insertar(auxld->getLetra(),auxld->getPunteo());
            j1->fichas->modificar(aux->getPunteo(),aux->getLetra(),auxld);
            cout<<"Ficha modificada"<<endl;
        }else{
            this->j2->fichas->mostrar();
            cin>>l;
            auxld = j2->fichas->buscar(l);
            this->fichasglobal->insertar(auxld->getLetra(),auxld->getPunteo());
            j2->fichas->modificar(aux->getPunteo(),aux->getLetra(),auxld);
        }
    }
}
//REPORTAR DATOS
void Juego::reportar(){
    int op;
    string reporte;
    string jugador="";
    NodoB *jug;
    do{
        system("cls");
        cout << "Que reporte desea ver? \n 1)Diccionario     2) Usuarios"<<endl;
        cout<< " 3)Scoreboard     4) Puntajes de un jugador "<<endl;
        cout<< " 5)Fichas de cada jugador    6) Fichas del juego"<<endl;
        cin>>op;
        switch(op){
            case 1 :
                if(this->archi->dic->getPrimero()!=0){
                    reporte = this->archi->dic->dibujarDiccionario();
                    this->archi->graficar("Diccionario",reporte);
                }else cout<< "No hay palabras en el diccionario"<<endl;
                break;
            case 2:
                if(this->usuarios->getRaiz()!=0){
                    this->archi->graficar("Usuarios",this->usuarios->dibujar());
                    this->archi->graficar("Inorder",this->usuarios->inorder());
                    this->archi->graficar("Preorder",this->usuarios->preorder());
                    this->archi->graficar("Postorder",this->usuarios->postorder());
                }else cout<< "No hay usuarios agregados"<<endl;
                break;
            case 3:
                if(this->scoreboard->getPrimero()==0) cout<< "Aun no se han jugado partidas"<<endl;
                else {
                    reporte  = this->scoreboard->dibujar();
                    this->archi->graficar("ScoreBoard",reporte);
                }
                break;
            case 4:
                cout<< "Que jugador desea ver"<<endl;
                getline(cin,jugador);
                jug = this->usuarios->getJugador(jugador);
                if(jug == 0) cout<<"No existe ese usuario"<<endl;
                else this->archi->graficar(jugador, jug->puntaje->dibujar());
                break;
            case 5:
                if(this->j1== 0 && this->j2 == 0) cout<< "No hay usuarios jugando";
                else{
                    reporte = "Fichas" + j1->getUsuario();
                    this->archi->graficar(reporte,this->j1->fichas->dibujar());
                    reporte = "Fichas" + j2->getUsuario();
                    this->archi->graficar(reporte,this->j2->fichas->dibujar());
                }
                break;
            case 6:
                if(this->fichasglobal->getPrimero()==0) cout<< "No hay fichas"<<endl;
                else this->archi->graficar("Fichas",this->fichasglobal->dibujar());
                break;
        }
        cout<<"Desea ver otro reporte?    1) Si    2)No" <<endl;
        cin>>op;
    }while(op==1);
}

Juego::~Juego()
{
    //dtor
}
