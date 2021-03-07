#include <iostream>
#include "Punto.h"

using namespace std;

int main()
{
    double pollo,gallina,Ar,Per;
    Punto A,B;
    A.modificaTusDatos();
    B.modificaTusDatos();
    pollo= A.dameTuX()-B.dameTuX();
    gallina= A.dameTuY()-B.dameTuY();
    Ar= pollo * gallina;
    Per= 2*pollo + 2*gallina;
    cout<<"Area del rectangulo "<<Ar<<" y su perimetro "<<Per<<endl;

    return 0;
}

