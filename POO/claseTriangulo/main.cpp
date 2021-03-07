#include <iostream>
#include "Triangulo.h"
using namespace std;

int main()
{
    Triangulo T1,T2(-2),T3;
    cout<<"T1:"<<endl;
    T1.muestraTusDatos();
    T1.modificaTuLado(3);
    T1.muestraTusDatos();
    cout<<"T2:"<<endl;
    T2.muestraTusDatos();
    cout<<"T3:"<<endl;
    T3.pideleAlUsuarioTusDatos();
    T3.muestraTusDatos();
    return 0;
}
