#include <iostream>
#include "CirculoP.h"
#include "Punto.h"
using namespace std;

int main()
{
    Punto CP(1,1),PP(2,2);
    CirculoP C1,C2(0,0,1,1),C3(CP,PP);
    cout<<C2.dameTuArea()<<endl<<C2.dameTuDiametro()
    <<endl<<C2.dameTuPerimetro()<<endl<<C2.dameTuRadio();
    return 0;
}
