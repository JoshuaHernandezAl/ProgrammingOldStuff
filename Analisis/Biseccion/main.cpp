#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void raices(void);
double evaluar(double x);
void biseccion(double a, double b, double eS);

int main()
{
    double a=0,b=0,eS,resul;
    int cifras;
        raices();
        cout<<"Ingresa los valores entre los cuales puede estar la raiz:"<<endl;
        cout<<"a=";
        cin>>a;
        cout<<"b=";
        cin>>b;
        cout<<"Cifras para el resultado: ";
        cin>>cifras;
        eS=0.5*(pow(10,2-cifras));
        biseccion(a,b,eS);
    return 0;
}
void raices(void){
    int a=3,b=6,c=-4;
    double x1,x2;
    x1=(-b + sqrt(pow(b,2)-4*a*c)) / (2*a);
    x2=(-b-sqrt(pow(b,2)-4*a*c))/(2*a);
    cout<<"Las raices calculadas son:"<<endl;
    cout<<"X1="<<x1<<",X2="<<x2<<endl;
}
double evaluar(double x){
    double y;
    y=3*pow(x,2)+6*x-4;
    return y;
}
void biseccion(double a, double b, double eS){
    double nuevo=0, anterior=0,eps=0,m=0;
    if(a==b && (evaluar(a)>(-eS)) && (evaluar(a)<eS))
        cout<<"La raiz esta en "<<a<<endl;
    else if((evaluar(a)>(-eS)) && (evaluar(a)<eS))
        cout<<"Raiz en"<<a<<endl;
    else if((evaluar(b)>(-eS)) && (evaluar(b)<eS))
        cout<<"Raiz en"<<b<<endl;
    else if ((evaluar(a)*evaluar(b))>0)
        cout<<"No hay raiz entre "<<a<<" y "<<b<<endl;
    else{
        cout<<"\n\na\t| b\t| m\t| epsilon\n\n";
        while(true){
            m = (b+a)/2;
      nuevo = m;
      cout<<"nuevo-->"<<nuevo<<endl;
      cout<<"anterior-->"<<anterior<<endl;
      //POner un if para hacer el valor abs, la funcion no esta haciendo el trabajo
      eps = ((nuevo-anterior)*100)/nuevo;
      if(eps<0){
        eps=-eps;}
      printf("%f\t| %f\t| %f\t| %f\n",a,b,m,eps);

      if (eps<eS){
        cout<<"\n Hay raíz en:"<<m<<endl;
        break;}
      else if (evaluar(a)*evaluar(m) < 0)
        b = m;
      else
        a = m;
      anterior = nuevo;
        }
    }
}
