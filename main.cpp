#include <iostream>
#include <conio.h>
#include "TableroMD.h"

using namespace std;

TableroMD a;
int main()
{
    a.insertar(2,8,'e',1);
    a.insertar(3,6,'f',2);
    a.insertar(7,2,'c',3);
    a.insertar(1,8,'e',3);
    a.insertar(9,5,'f',5);
    a.insertar(9,2,'c',10);
    cout<< a.dibujar()<<endl;
    return 0;
}
