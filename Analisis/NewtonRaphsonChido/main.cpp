#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
//Metodo de la secante

void raices(void);
double evaluar(double x);
void secante(double xi,double x0, double eS);

using namespace std;

int main()
{
    double x,eS,b;
    int cifras;
    raices();
    cout<<"Ingresa dos punto cercano a la raiz:\n";
    cout<<"a=";
    cin>>x;
    cout<<"b=";
    cin>>b;
    cout<<"Precision del calculo:";
    cin>>cifras;
    eS=0.5*pow(10,2-cifras);
    secante(x,b,eS);
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

void secante(double xi,double x0, double eS){
    double eps=0,xs;
    printf("\n\nxi\t\t| x i+1\t\t\n\n");
    while (true){
        xs=xi-((evaluar(xi)*(xi-x0))/(evaluar(xi)-evaluar(x0)));
        eps = ((xs-xi)*100)/xs;
        if(eps<0){
        eps=-eps;}
        printf("%f\t| %f\t\n",xi,xs);
        if(eps<eS){
            cout<<"raiz en:"<<xs<<endl;
            break;
        }
        xi=x0;
        x0=xs;
    }

}
