#include <iostream>
#include <stdlib.h>
#include "Punto.h"
using namespace std;
template<typename T>
T* aray(int n, T algo);
template<typename T>
void leerArreglo(T *X, int n);
template<typename T>
void muestraArreglo(T *X,int n);
template<typename T>
void sumaArreglo(T *X, T *Y, T *Z, int n);
template<typename T>
void restaArreglo(T *X, T *Y, T *Z, int n);
int main()
{
    int n1,n2,n3,n4;
    Punto *A,*B,*C,*D, algo;
    cout<<"Dame n1"<<endl;
    cin>>n1;
    cout<<"Dame n2"<<endl;
    cin>>n2;
    if(n1!=n2)
        cout<<"No se pueden realizar las operaciones con los arreglos"<<endl;
    else if(n1<=0)
        cout<<"Error al reviservarse memoria..."<<endl;
    else{
        n3=n1;
        n4=n2;
        A=aray(n1,algo);
        B=aray(n2,algo);
        C=aray(n3,algo);
        D=aray(n4,algo);
        system("cls");
        cout<<"A:"<<endl;
        leerArreglo(A,n1);
        cout<<"B:"<<endl;
        leerArreglo(B,n2);
        sumaArreglo(A,B,C,n3);
        restaArreglo(A,B,D,n4);
        cout<<"A:"<<endl;
        muestraArreglo(A,n1);
        cout<<"B:"<<endl;
        muestraArreglo(B,n2);
        cout<<"C:"<<endl;
        muestraArreglo(C,n3);
        cout<<"D:"<<endl;
        muestraArreglo(D,n4);
    }
    return 0;
}
template<typename T>
T* aray(int n, T algo){
    T* A;
    A=new T[n];
    return A;
}
template<typename T>
void leerArreglo(T *X, int n){
    int i;
    for(int i=0;i<n;i++){
        cout<<"X["<<i<<"]"<<endl;
        cin>>X[i];
    }
}
template<typename T>
void muestraArreglo(T *X,int n){
    int i;
    for(i=0;i<n;i++)
    cout<<X[i]<<endl;
}
template<typename T>
void sumaArreglo(T *X, T *Y, T *Z, int n){
    int i;
    for(i=0;i<n;i++)
        Z[i]=X[i]+Y[i];
}
template<typename T>
void restaArreglo(T *X, T *Y, T *Z, int n){
    int i;
    for(i=0;i<n;i++)
        Z[i]=X[i]-Y[i];
}
