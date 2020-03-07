#include <iostream>
#include <conio.h>
#include "FichasLD.h"
using namespace std;

FichasLD dic;
int main()
{
    dic.insertar(2,'l');
    dic.insertar(8,'a');
    dic.insertar(2,'u');
    dic.insertar(8,'r');
    dic.insertar(2,'o');
    dic.insertar(8,'p');
    cout<<dic.dibujar();
    getch();
    return 0;
}
