#include "Archivo.h"

Archivo::Archivo()
{
    this->dic = new string[30];
    this->dimension  = 0;
}

void Archivo:: graficar(string nombre,string dibujo){
    ofstream archivo;
    string dot = nombre + ".dot";
    string png = nombre + ".png";
    archivo.open(dot,ios::out);
    if(archivo.fail()){
        cout<< "No se pudo crear el reporte"<<endl;
    }else{
        archivo<<"digraph g{\n";
        archivo<<dibujo;
        archivo<<"\n}";
        archivo.close();
    }
    string comando = "dot -Tpng " + dot + " -o " + png;
    system(comando.c_str());
    system(png.c_str());
}

Json Archivo::getJson(string ruta){
    Json json1;
    ifstream archivo;
    if(ruta.size() != 0){
        archivo.open("C:\\Users\\Oliveira Raymundo\\Desktop\\" + ruta);
        if(archivo.good()){
            archivo >> json1;
            archivo.close();
            return json1;
        }else{
            cout<<"El archivo de configuracion no ha podido abrirse"<<endl;
            return "";
        }
    }
    return "";
}

void Archivo::cargarData(string ruta){
    int c;
    Json json1 = this->getJson(ruta);
    this->dimension = json1.at("dimension");
    for(int d = 0; d < json1.at("diccionario").size(); d++){
        dic[d] = json1.at("diccionario")[d].at("palabra");
    }
    for(c = 0; c <json1.at("casillas").at("dobles").size(); c++){
        casillas[c].x = json1.at("casillas").at("dobles")[c].at("x");
        casillas[c].y = json1.at("casillas").at("dobles")[c].at("y");
        casillas[c].punteo = 2;
    }
    for(int t = 0; t<json1.at("casillas").at("triples").size();t++){
        casillas[c].x = json1.at("casillas").at("triples")[t].at("x");
        casillas[c].y = json1.at("casillas").at("triples")[t].at("y");
        casillas[c].punteo = 3;
        c++;
    }
    cout<<"Datos cargados con exito"<<endl;
}

Archivo::~Archivo()
{
    //dtor
}
