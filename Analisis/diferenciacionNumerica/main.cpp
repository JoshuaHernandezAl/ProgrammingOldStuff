#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Polinomio.h"
void dAdelante(double x,double h,Polinomio P);
void  dAtras(double x,double h,Polinomio P);
void  dCentral(double x,double h,Polinomio P);
void  d2Adelante(double x,double h,Polinomio P);
void  d2Atras(double x,double h,Polinomio P);
void  d2Central(double x,double h,Polinomio P);
using namespace std;

int main()
{
    Polinomio P,dx,d2x;
    double x,h;
    P.ingresaPolinomio();
    system("cls");
    cout<<"Polinomio:"<<endl;
    P.muestraPolinomio();
    dx.deriva(P);
    cout<<endl;
    cout<<"Derivada polinomio:"<<endl;
    dx.muestraPolinomio();
    d2x.deriva(dx);
    cout<<endl<<"Segunda derivada:"<<endl;
    d2x.muestraPolinomio();
    cout<<endl<<"Ingresa x= ";
    cin>>x;
    cout<<"Ingresa h= ";
    cin>>h;
    cout<<"Evaluando analiticamente:"<<endl;
    cout<<"f'("<<x<<")= "<<dx.evalua(x)<<endl;
    cout<<"f''("<<x<<")= "<<d2x.evalua(x)<<endl<<endl<<endl;
    dAdelante(x,h,P);
    dCentral(x,h,P);
    dAtras(x,h,P);
    d2Adelante(x,h,P);
    d2Atras(x,h,P);
    d2Central(x,h,P);
    return 0;
}
void  dAdelante(double x,double h,Polinomio P ){
    double d;
    d=(P.evalua(x+h)-P.evalua(x))/h;
    cout<<"Hacia adelante f'("<<x<<")="<<d<<endl;
}
void  dAtras(double x,double h,Polinomio P){
    double d;
     d = (P.evalua(x) - P.evalua(x-h))/(h);
    cout<<"Hacia atras f'("<<x<<")="<<d<<endl;
}
void dCentral(double x,double h,Polinomio P){
    double d;
     d = (P.evalua(x + h) - P.evalua(x - h))/(2*h);
     cout<<"Hacia central f'("<<x<<")="<<d<<endl;
}
void d2Adelante(double x,double h,Polinomio P){
    double d;
    d = (P.evalua(x+(2*h)) - 2*P.evalua(x+h) + P.evalua(x))/(pow(h,2));
    cout<<"Hacia adelante f''("<<x<<")="<<d<<endl;
}
void d2Atras(double x,double h,Polinomio P){
    double d;
    d = (P.evalua(x) - 2*P.evalua(x-h) + P.evalua(x-2*h))/(pow(h,2));
    cout<<"Hacia atras f''("<<x<<")="<<d<<endl;
}
void d2Central(double x,double h,Polinomio P){
    double d;
     d = (P.evalua(x+h) - 2*P.evalua(x) + P.evalua(x-h))/(pow(h,2));
     cout<<"Hacia central f''("<<x<<")="<<d<<endl;
}
