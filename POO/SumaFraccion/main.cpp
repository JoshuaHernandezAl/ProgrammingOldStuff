#include <iostream>
#include <stdlib.h>
#include "Fraccion.h"
Fraccion sumaFraccion( Fraccion A, Fraccion B);
Fraccion restaFraccion(Fraccion A, Fraccion B);
Fraccion multiFraccion(Fraccion A, Fraccion B);
Fraccion divisionFraccion(Fraccion A, Fraccion B);
int menu(void);
void opciones(int op);
using namespace std;

int main()
{
    int op;
    do{
        op=menu();
        opciones(op);
    }while(op!=5);
    return 0;
}
void opciones(int op){
    Fraccion A,B,C,E,F,D;
    switch(op){
        case 1:
        A.pideleAlUsuarioTusDatos();
        B.pideleAlUsuarioTusDatos();
        C=sumaFraccion(A,B);
        C.muestraTusDatos();
        cout<<endl;
        system("pause");
        system("cls");
break;
    case 2:
        A.pideleAlUsuarioTusDatos();
        B.pideleAlUsuarioTusDatos();
        D=restaFraccion(A,B);
        D.muestraTusDatos();
        cout<<endl;
        system("pause");
        system("cls");
break;
    case 3:
        A.pideleAlUsuarioTusDatos();
        B.pideleAlUsuarioTusDatos();
        E=multiFraccion(A,B);
        E.muestraTusDatos();
        cout<<endl;
        system("pause");
        system("cls");
break;
    case 4:
        A.pideleAlUsuarioTusDatos();
        B.pideleAlUsuarioTusDatos();
        F=divisionFraccion(A,B);
        F.muestraTusDatos();
        cout<<endl;
        system("pause");
        system("cls");
break;
    case 5: cout<<"Adios"<<endl;
break;
    default: cout<<"Opcion no valida"<<endl;
    cout<<endl;
    system("pause");
        system("cls");
    }
}
Fraccion sumaFraccion( Fraccion A, Fraccion B){
    Fraccion C;
    C.modificaTuNum(A.dameTuNum()*B.dameTuDen()+A.dameTuDen()*B.dameTuNum());
    C.modificaTuDen(A.dameTuDen()*B.dameTuDen());
    return C;
}
Fraccion restaFraccion(Fraccion A, Fraccion B){
    Fraccion C;
    C.modificaTuNum(A.dameTuNum()*B.dameTuDen()- A.dameTuDen()*B.dameTuNum());
    C.modificaTuDen(A.dameTuDen()*B.dameTuDen());
    return C;
}
Fraccion multiFraccion(Fraccion A, Fraccion B){
    Fraccion C;
    C.modificaTuNum(A.dameTuNum()*B.dameTuNum());
    C.modificaTuDen(A.dameTuDen()*B.dameTuDen());
    return C;
}
Fraccion divisionFraccion(Fraccion A, Fraccion B){
    Fraccion C;
    C.modificaTuNum(A.dameTuNum()*B.dameTuDen());
    C.modificaTuDen(A.dameTuDen()*B.dameTuNum());
    return C;
}
int menu(void){
    int op;
    cout<<"1.-Suma"<<endl<<"2.-Resta"<<endl<<"3.-Multiplicaicon"<<endl<<"4.-Division"<<endl<<"5.-Salir"<<endl<<"Que operacion desea realizar?"<<endl;
    cin>>op;
    system("cls");
    return op;
}
/*Fraccion A,B,C,E,F,D;
    A.pideleAlUsuarioTusDatos();
    B.pideleAlUsuarioTusDatos();
    cout<<"Suma de A +B"<<endl;
    C=sumaFraccion(A,B);
    C.muestraTusDatos();
    cout<<endl;
    cout<<"Resta de A - B"<<endl;
    D=restaFraccion(A,B);
    D.muestraTusDatos();
    cout<<endl;
    cout<<"Multiplicacion de  A * B"<<endl;
    E=multiFraccion(A,B);
    E.muestraTusDatos();
    cout<<endl;
    cout<<"Division de A/B"<<endl;
    F=divisionFraccion(A,B);
    F.muestraTusDatos();
    cout<<endl;*/
