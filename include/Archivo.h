#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "../json.hpp"
#include "Casilla.h"
#include "DiccionarioLDC.h"
#include <vector>

using namespace std;
using Json = nlohmann::json;
class Archivo
{
    public:
        Archivo();
        void graficar(string,string);
        virtual ~Archivo();
        Json getJson(string);
        int dimension;
        DiccionarioLDC *dic;
        vector<Casilla *> casillas;
        void cargarData(string);
    protected:

    private:
};

#endif // ARCHIVO_H
