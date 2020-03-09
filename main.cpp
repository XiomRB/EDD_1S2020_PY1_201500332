#include <iostream>
#include <conio.h>
#include "UsuariosA.h"
using namespace std;

UsuariosA t;
int main()
{
    t.insertar("gaby");
    t.insertar("olga");
    t.insertar("ana");
    t.insertar("ale");
    t.insertar("elias");
    t.insertar("vicky");
    cout<<t.dibujar();
    return 0;
}
