#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
float calculaSerieE(float x,int n);
long long factorial(int valor);
int main(void){
    float x, e;
    int n;
    cout<<"Ingresa x ";cin>>x;
    cout<<"Ingresa n ";cin>>n;
    e = calculaSerieE(x,n);
    cout<<endl<<endl<<"e^" <<x<<" = "<<e<<endl;
    return 0;
}
float calculaSerieE(float x,int n){
    float e=0,epsilon,nuevo,anterior;
    int i;
    cout<<endl<<endl
        <<"Termino  "<<"| e\t\t"<<"| epsilon"<<endl<<endl;

    for(i=0;i<=n;i++){
        e += pow(x,i) / factorial(i);
        nuevo = e;
        if(i!=0){
            epsilon = (nuevo-anterior)*100/nuevo;
            printf("%d\t | %f\t| %f %%\n",i,e,epsilon);
        }
        else
            printf("%d\t | %f\t|\n",i,e);
        anterior = nuevo;
    }
    return e;
}
long long factorial(int valor){
    long long f=1;
    int i;
    for(i=1;i<=valor;i++)
        f *= i;
    return f;
}
