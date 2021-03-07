#include <iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<Disercion.h>
#include<PuntoFijo.h>

using namespace std;

int main()
{
    int op;
    Disercion A;
    PuntoFijo B;
    do{
    cout<<"Este programa calcula lo siguiente: \n"<<endl;
    cout<<"1) Una raiz de (e^-x)-x por el metodo Biseccion\n"<<endl;
    cout<<"2) Una raiz de cos(x) - X/2 + 1 por el metodo Punto Fijo\n"<<endl;
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
