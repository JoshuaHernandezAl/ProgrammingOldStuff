#include <iostream>
#include <math.h>
#include "Punto.h"
using namespace std;

int main()
{
    float r1,r2;
    Punto A,B,O;
    cout<<"A:"<<endl;
    A.modificaTusDatos();
    cout<<"B:"<<endl;
    B.modificaTusDatos();
    r1=sqrt(pow((A.dameTuX()-O.dameTuX()),2)+pow((A.dameTuY()-O.dameTuY()),2));
    r2=sqrt(pow((B.dameTuX()-O.dameTuX()),2)+pow((B.dameTuY()-O.dameTuY()),2));
    if(r1>r2)
        cout<<"La distancia de B al origen es la mas corta"<<endl;
    else if(r2>r1)
        cout<<"La distancia de A al origen es la mas corta"<<endl;
    else
        cout<<"A y B son puntos equidistantes al origen"<<endl;
    return 0;
}
