#include <iostream>
#include "Punto.h"
#include <math.h>
using namespace std;

int main()
{
    double r,ar,per;
    Punto A,B;
    cout<<"Centro de la circunferencia"<<endl;
    A.modificaTusDatos();
    cout<<"Punto en la circunferencia"<<endl;
    B.modificaTusDatos();
    r=sqrt(pow(A.dameTuX()-B.dameTuX(),2)+pow(A.dameTuY()-B.dameTuY(),2));
    ar=M_PI*pow(r,2);
    per=2*M_PI*r;
    cout<<"El area de circulo dado es: "<<ar<<" y su perimetro es: "<<per<<endl;
    return 0;
}
