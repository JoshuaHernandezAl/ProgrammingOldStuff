#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
double **M;
void leerPts(double X[],double Y[],int n);
void muestraPts(double X[],double Y[],int n);
void interNewton(double X[],double Y[],int n, double x);
void diferenciaDivididas(double X[], double Y[],int n);
double bases(double x,double X[], int k);
double suma(double x,double X[], double Y[],int n);

int main()
{
    double* X;
    double* Y;
    int n;
    double x;
    cout<<"Ingresa el grado del polinomio: ";
    cin>>n;
    X=new double[n+1];
    Y=new double[n+1];
    cout<<"ingresa los puntos:"<<endl;
    leerPts(X,Y,n);
    cout<<"Punto a interpolar: ";
    cin>>x;
    interNewton(X,Y,n,x);

    return 0;
}
void leerPts(double X[],double Y[],int n){
    for(int i=0;i<n+1;i++){
        cout<<"X["<<i<<"]= ";
        cin>>X[i];
        cout<<"Y["<<i<<"]= ";
        cin>>Y[i];
    }
    muestraPts(X,Y,n);
}
void muestraPts(double X[],double Y[],int n){
    cout<<"X\t|Y"<<endl;
    for(int i=0;i<n+1;i++){
        cout<<X[i]<<"\t|"<<Y[i]<<endl;
    }
}
void interNewton(double X[],double Y[],int n, double x){
    double resul=0;
    M=new double*[n];
    for(int i=0;i<n;i++){
        M[i]=new double[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            M[i][j]=0;
    }
    diferenciaDivididas(X,Y,n);
    resul=suma(x,X,Y,n);
    cout<<"f("<<x<<")="<<resul<<endl;

}
void diferenciaDivididas(double X[], double Y[],int n){
    int k=0;
    for(int j=0;j<n;j++){
        k=0;
        for(int i=j; i<n;i++){
         if(j==0){
            M[i][j] = (Y[i+1]-Y[i])/(X[i+1]-X[k]);
            }
        else{
                M[i][j] = (M[i][j-1]-M[i-1][j-1])/(X[i+1]-X[k]);
            }
            k=k+1;
        }
    }
}
double bases(double x,double X[], int k){
    double e1=1;
    for(int i=0; i<=k;i++){
        e1=e1*(x - X[i]);
    }
    return e1;
}
double suma(double x,double X[], double Y[],int n){
    double s=Y[0];
    for(int i=1;i<n+1;i++){
        s=s+(bases(x,X,i-1)*M[i-1][i-1]);
    }
    return s;
}
