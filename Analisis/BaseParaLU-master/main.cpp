#include "Sistema.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(void){
    Sistema S;
    int op=0;
    S.pideDatos();
    cout<<"elige el metodo por el cual se resolvera el sistema: "<<endl;
    do{
        cout<<"1.-Gauss"<<endl<<"2.-Gauss-Jordan"<<
        endl<<"3.-Gauss-Seidel"<<endl<<"4.- LU"<<endl;
        cin>>op;
    }while(op==0);
    switch(op){
        case 1:
            S.Gauss();
            break;
        case 2:
            S.GaussJordan();
            break;
        case 3:
            S.GaussSeidel();
            break;
        case 4:
            S.LU();
            break;
    }
    return 0;
}
