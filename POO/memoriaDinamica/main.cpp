#include <iostream>
#include <stdlib.h>
using namespace std;
void leerArreglo(double *X, int n);
void mostrarArreglo(double *X, int n);
void sumaArreglos(double *X, double *Y, double *Z, int n);
void restaArreglos(double *X, double *Y, double *Z, int n);
int main()
{
    double *A=NULL,*B=NULL,*C=NULL,*D=NULL;
    int i=0,n1=0,n2=0;
    cout<<"Dame n1: "<<endl;
    cin>>n1;
    cout<<"Dame n2: "<<endl;
    cin>>n2;
    cout<<"A= "<<A<<endl;
    cout<<"B= "<<B<<endl;
    if(n1>0 && n2>0 && n1==n2){
     A=new double[n1];
     B=new double[n2];
     C=new double[n1];
     D=new double[n2];
    }
    cout<<"A= "<<A<<endl;
    cout<<"B= "<<B<<endl;
    if(A==NULL || B==NULL)
        cout<<"Error! no hay memoria"<<endl;
    else{
        leerArreglo(A,n1);
        leerArreglo(B,n2);
        system("cls");
        sumaArreglos(A,B,C,n1);
        restaArreglos(A,B,D,n2);
        system("cls");
        cout<<"A: "<<endl;
        mostrarArreglo(A,n1);
        cout<<"B: "<<endl;
        mostrarArreglo(B,n2);
        cout<<"C: "<<endl;
        mostrarArreglo(C,n1);
        cout<<"D: "<<endl;
        mostrarArreglo(D,n2);
        delete[] A;
        delete[] B;
        delete[] C;
        delete[] D;
    }

    return 0;
}

void leerArreglo(double *X, int n){
    int i=0;
    for(i=0;i<n;i++){
        cout<<"Ingresa X["<<i<<"]"<<endl;
        cin>>X[i];
    }
}
void mostrarArreglo(double *X, int n){
    int i=0;
    for(i=0;i<n;i++){
        cout<<X[i]<<endl;
    }
}
void sumaArreglos(double *X, double *Y, double *Z, int n){
    int i;
    for(i=0;i<n;i++)
        Z[i]=X[i]+Y[i];
}
void restaArreglos(double *X, double *Y, double *Z, int n){
    int i;
    for(i=0;i<n;i++)
        Z[i]=X[i]-Y[i];
}
