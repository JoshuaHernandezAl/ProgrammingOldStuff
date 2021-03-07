#include <iostream>
#include "Rectangulo.h"
using namespace std;

int main()
{
    Rectangulo R1(-3,2),R2,R3(2,4);
    R1.muestraTusDatos();
    R2.muestraTusDatos();
    R2.pideleAlUsuarioTusDatos();
    R2.muestraTusDatos();
    R1.modificaTuAltura(2);
    R1.modificaTuBase(3);
    R1.muestraTusDatos();
    cout<<R3.dameTuBase()<<endl<<R3.dameTuAltura()<<endl<<R3.dameTuArea()<<endl<<R3.dameTuPerimetro()<<endl;
    return 0;
}
