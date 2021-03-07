#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Polinomio.h"
using namespace std;

int main(void){
    Polinomio P, PD;
    double x;

    cout<<"P"<<endl;P.ingresaPolinomio();
    PD.deriva(P);
    system("cls");

    cout<<"P = ";P.muestraPolinomio();
    cout<<endl;
    cout<<"P' = ";PD.muestraPolinomio();

    cout<<endl<<endl;
    cout<<"Ingresa x ";cin>>x;

    cout<<endl<<endl;
    cout<<"f ("<<x<<")  = "<<P.evalua(x)<<endl
        <<"f'("<<x<<")  = "<<PD.evalua(x)<<endl;

    return 0;
}
