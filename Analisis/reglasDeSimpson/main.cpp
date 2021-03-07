#include <iostream>
#include "Polinomio.h"
#include <math.h>
double calculaSuma(double x0,double h,int n, Polinomio P);
using namespace std;

int main()
{
    Polinomio P;
    double x0=0,xn=0,h=0,integral=0,x1=0,x2=0;
    int op,n;
    P.ingresaPolinomio();
    P.muestraPolinomio();
    cout<<endl<<"Ingresa limite inferior: ";
    cin>>x0;
    cout<<"Ingresa limite superior: ";
    cin>>xn;
    cout<<"Selecccione la regla de simpson a utilizar:"<<endl
    <<"Simpson 1/3-->1)"<<endl<<"Simpson 3/8-->2)"<<endl;
    cin>>op;
    if(op==1){
        cout<<"Ingresa el numero de segmentos: ";
        cin>>n;
         h = (xn-x0)/n;
         cout<<"h="<<h<<endl;
         integral = (h/3)*(P.evalua(x0) + calculaSuma(x0,h,n,P) + P.evalua(xn));
    cout<<"integral="<<integral<<endl;
    }
    else{
    h = (xn-x0)/3;
    x1 = x0+h;
    x2 = x1+h;
    integral = (3*h/8)*(P.evalua(x0) + 3*P.evalua(x1) + 3*P.evalua(x2) + P.evalua(xn));
    cout<<"h="<<h<<endl;
    cout<<"integral="<<integral<<endl;

    }

    return 0;
}
double calculaSuma(double x0,double h,int n, Polinomio P){
     double s = 0;
  for (int i=1;i<n;i++){
    if (i%2!=0){
      s = s + 4*P.evalua(x0+(h*i));
    }
    else{
      s = s + 2*P.evalua(x0+(h*i));
  }
  }
  return s;
}
