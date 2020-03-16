#include "Menu.h"

Menu::Menu()
{
    this->configurado = false;
    this->juego = new Juego();
    this->usuarios = new UsuariosA();
}

void Menu::inicio(){
    system("cls");
    cout<<"SCRABBLE"<<endl;
    cout<< "Bienvenido"<<endl;
    int op;
    do{
        cout<< "Elija una opcion:"<<endl;
        cout<< " 1. Configurar Juego \n 2. Jugar \n 3. Crear Usuario \n 4. Ver Reportes \n 5. Salir"<<endl;
        cin>>op;
        switch(op){
            case 1: this->configurar();
            break;
            case 2:
                if(configurado){
                    this->pedirJugadores();
                    this->juego->fichasglobal->crearCola();
                    this->jugar();
                }else {
                    system("cls");
                    cout<< "No ha configurado el tablero de juego"<<endl;
                    cout<< "Presione cualquier tecla para volver al menu"<<endl;
                    char i;
                    cin>>i;
                    inicio();
                }
            break;
            case 3: this->crearUsuario();
            break;
            case 4: this->reportar();
            break;
            case 5: exit(0);
            break;
            default:
                cout<< "Opcion incorrenta"<<endl;
                system("cls");
                break;
        }
    }while(op>1 && op<5);
}

void Menu::configurar(){
    system("cls");
    string ruta;
    cout<< "Escriba el nombre del archivo de configuracion"<<endl;
    getline(cin,ruta);
    getline(cin,ruta);
    this->juego->archi->cargarData(ruta);
    this->configurado = true;
    char i;
        cout<<"Presione cualquier tecla volver al menu de juego"<<endl;
        cin>>i;
    this->inicio();
}

void Menu::jugar(){
    cout<<"Jugadores cargados"<<endl;
}

void Menu::pedirJugadores(){
    system("cls");
    string j;
    string usuario1;
    string usuario2;
    do{
        j = "";
        fflush(stdin); //limpia el buffer
        cout<< "Elija jugador 1"<<endl;
        getline(cin,j);
        for(short i = 0; i <j.size(); i++){
            usuario1  += toupper(j[i]);
        }
        if(this->usuarios->getRaiz()==0){
            char l;
            cout<<"Aun no hay usuarios creados, vuelva al menu, para crear uno nuevo"<<endl;
            cout<<"Presione cualquier tecla para volver"<<endl;
            cin>>l;
            this->inicio();
        }else this->juego->j1 = this->usuarios->getJugador(usuario1);
        if(this->juego->j1 == 0) cout<< "El jugador no existe"<<endl;
    }while(this->juego->j1==0);
    system("cls");
    do{
        j = "";
        fflush(stdin);
        cout<< "Elija jugador 2"<<endl;
        getline(cin,j);
        for(short i = 0; i <j.size(); i++){
            usuario2  += toupper(j[i]);
        }
        if(usuario2.compare(usuario1) != 0) this->juego->j2 = this->usuarios->getJugador(usuario2);
    }while(this->juego->j2==0);
}

void Menu::crearUsuario(){
    system("cls");
    fflush(stdin);
    string u;
    cout<<"Escriba el nombre de usuario"<<endl;
    getline(cin,u);
    string usuario;
    for(short i = 0; i <u.size(); i++){
        usuario  += toupper(u[i]);
    }
    this->usuarios->insertar(usuario);
    cout<< "Usuario creado"<<endl;
    cout<< "Presione cualquier tecla para regresar"<<endl;
    cin>>u;
    this->inicio();
}

void Menu::reportar(){
    cout<<"Holi";
}
Menu::~Menu()
{
    //dtor
}
