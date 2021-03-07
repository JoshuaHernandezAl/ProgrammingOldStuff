#include <iostream>
#include "Polinomio.h"
#include <stdlib.h>
#include <math.h>
using namespace std;
double calculaSuma(double x0, double h, int n, Polinomio P);
int main()
{
    Polinomio P;
    double x0,xn,h, integral;
    int n;
    P.ingresaPolinomio();
    P.muestraPolinomio();
    cout<<endl<<"Ingresa limite inferior: ";
    cin>>x0;
    cout<<"Ingresa limite superior: ";
    cin>>xn;
    cout<<"Ingresa numero de segmentos: ";
    cin>>n;
    h=(xn-x0)/n;
    cout<<"h="<<h<<endl;
    integral = h*(P.evalua(x0) + 2*calculaSuma(x0,h,n,P) + P.evalua(xn))/2;
    cout<<endl<<"Resultado= "<<integral<<endl;
    int op;
    double real,error;
    cout<<"Usted esta provando al vereacidad del programa"<<endl<<"1)SI \n2)NO"<<endl;
    cin>>op;
    if(op==1){
    cout<<"A fin de probar el programa,si usted tiene el resultado de la "<<endl<<"integral introducida proporcione "
    <<"el valor real para llevar a cabo la estimacion de error"<<endl<<"Real: ";
    cin>>real;
    error=fabs((real-integral)/real)*100;
    cout<<"Error del resultado= "<<error<<endl;
    exit(0);
    }
    else{
        cout<<"Adios"<<endl;
    exit(0);
    }
    return 0;
}
double calculaSuma(double x0, double h, int n, Polinomio P){
    double s;
      s = 0;
  for (int i=1;i<n;i++)
    s = s+P.evalua(x0+(h*i));
  return s;
}
