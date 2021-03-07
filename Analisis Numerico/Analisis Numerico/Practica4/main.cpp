#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<Gauss.h>
#include<Jordan.h>
using namespace std;

int main()
{
   Gauss A;
   Jordan B;
    int op;

    do{
    cout<<"Este programa calcula sistemas de ecuaciones: \n"<<endl;
    cout<<"1) Por el metodo de Gauss\n"<<endl;
    cout<<"2) Por el metodo de Gauss-Jordan\n"<<endl;
    cout<<"3) Salir\n"<<endl;
    cout<<"Cual es tu opcion?\n"<<endl;
    cin>>op;

    switch(op){
    case 1:
        A.pideleAlUsuarioTusDatos();
        A.muestraTusDatos();
        break;
    case 2:
        B.pideleAlUsuarioTusDatos();
        B.muestraTusDatos();
        break;
    case 3:
        cout<<"Hasta pronto"<<endl;
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;  }
    system("pause");
    system("cls");
    }while(op!=3);
    return 0;
}
