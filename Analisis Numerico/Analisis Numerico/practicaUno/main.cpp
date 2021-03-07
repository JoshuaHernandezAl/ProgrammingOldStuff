#include <iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<e.h>
using namespace std;

int main()
{
    int op;
    e A;
    do{
    cout<<"Este programa calcula lo siguiente: \n"<<endl;
    cout<<"1) El valor de e a la x potencia\n"<<endl;
    cout<<"2) Salir\n"<<endl;
    cout<<"Cual es tu opcion?\n"<<endl;
    cin>>op;

    switch(op){
    case 1:
        A.pideleAlUsuarioTusDatos();
        A.muestraTusDatos();
        break;

    case 2:
        cout<<"Hasta pronto"<<endl;
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;  }
    system("pause");
    system("cls");
    }while(op!=2);
    return 0;
}

