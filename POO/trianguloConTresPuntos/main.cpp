#include <iostream>
#include "Punto.h"
#include <math.h>
using namespace std;

int main()
{
    float b,h,area,per,d1,d2;
    Punto A,B,C;
    cout<<"Dame las coordenadas de la base del triangulo"<<endl;
    A.modificaTusDatos();
    B.modificaTusDatos();
    cout<<"Dame el tercer punto"<<endl;
    C.modificaTusDatos();
    if(A.dameTuY()!=B.dameTuY())
        cout<<"Lo siento no puedo realizar este calculo"<<endl;
    else{
        b=fabs(A.dameTuX()-B.dameTuX());
        h=fabs(C.dameTuY()-B.dameTuY());
        area=(b*h)/2;
        d1=sqrt(pow(A.dameTuX()-C.dameTuX(),2)+pow(A.dameTuY()-C.dameTuY(),2));
        d2=sqrt(pow(B.dameTuX()-C.dameTuX(),2)+pow(B.dameTuY()-C.dameTuY(),2));
        per=b+d1+d2;
        cout<<"El area del triangulo es: "<<area<<" y el perimetro es: "<<per<<endl;
    }
    return 0;
}
