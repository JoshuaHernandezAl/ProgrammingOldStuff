#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void raices(void);
double evaluar(double x);
double dv(double x);
void NewtonRaphson(double xi,double eS);

using namespace std;

int main()
{
    double x,eS;
    int cifras;
    raices();
    cout<<"Ingresa un punto cercano a la raiz:";
    cin>>x;
    cout<<"Precision del calculo:";
    cin>>cifras;
    eS=0.5*pow(10,2-cifras);
    NewtonRaphson(x,eS);
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
double dv(double x){
    return 6*x+6;
}
void NewtonRaphson(double xi,double eS){
    double eps=0,xs;
    printf("\n\nxi\t\t| x i+1\t\t\n\n");
    while (true){
        xs=xi-(evaluar(xi)/dv(xi));
        eps = ((xs-xi)*100)/xs;
        if(eps<0){
        eps=-eps;}
        printf("%f\t| %f\t\n",xi,xs);
        if(eps<eS){
            cout<<"raiz en:"<<xs<<endl;
            break;
        }
        xi=xs;
    }

}
