#include <iostream>

using namespace std;
void pidePuntos(int n, double X[], double Y[]);
void muestraPuntos(double X[], double Y[], int n);
double Lf(double X[], double Y[], int x, int n);
double L(double X[], double x, int i, int n);

int main()
{
    int n=0;
    double* X;
    double* Y;
    X=new double[n+1];
    Y=new double[n+1];
    double res=0, x=0;
    cout <<"Ingrese el gardo del polinomio: ";
    cin>>n;
    pidePuntos(n, X,Y);
    cout<<"Valor a interpolar: ";
    cin>>x;
    res=Lf(X,Y,x,n);
    cout<<"El punto interpolado por Lagrange es: "<<res<<endl;
    return 0;
}
void pidePuntos(int n, double X[], double Y[]){

    double res=0;
    for(int i=0;i<n+1;i++){
        cout<<"Ingresa x"<<i<<"= ";
        cin>>X[i];
        cout<<"Ingresa y"<<i<<"= ";
        cin>>Y[i];
    }
    muestraPuntos(X,Y,n);
}
void muestraPuntos(double X[], double Y[], int n){
    cout<<"X\t\t|Y"<<endl;
    for(int i=0;i<n+1;i++){
        cout<<X[i]<<"\t\t "<<Y[i]<<endl;
    }
}
double Lf(double X[], double Y[], int x, int n){
    double suma=0;
    for(int i=0;i<n+1;i++){
        suma=suma+(L(X,x,i,n)*Y[i]);
    }
    return suma;
}
double L(double X[], double x, int i, int n){
    double p=1;
    for(int j=0; j<n+1;j++){
        if(j!=i){
            p=p*((x-X[j])/(X[i]-X[j]));
        }
    }
    return p;
}
