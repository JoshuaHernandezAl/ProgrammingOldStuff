#include <iostream>
#include "Punto.h"
#include "RectanguloP.h"
using namespace std;

int main()
{
    Punto AP(0,0),BP(2,2);
    RectanguloP R1,R2(AP,BP),R3(2,2,4,4);
    cout<<R2.dameTuAltura()<<endl<<R2.dameTuArea()<<endl
    <<R2.dameTuBase()<<endl<<R2.dameTuPerimetro()<<endl;
    return 0;
}
