#include <iostream>
#include "Punto.h"

using namespace std;

int main()
{
    Punto A,B;
    Punto C;
    float m;
    cout<<"coordenadas del punto A:"<<endl;
    A.modificaTusDatos();
    cout<<"coordenadas del punto B:"<<endl;
    B.modificaTusDatos();
    m=(A.dameTuY()-B.dameTuY())/(A.dameTuX()-B.dameTuX());
    cout<<"La pendiente de la recta que pasa por los puntos A("<<A.dameTuX()<<","<<A.dameTuY()<<") y B("
    <<B.dameTuX()<<","<<B.dameTuY()<<") es igual a "<<m<<endl;
    return 0;
}
