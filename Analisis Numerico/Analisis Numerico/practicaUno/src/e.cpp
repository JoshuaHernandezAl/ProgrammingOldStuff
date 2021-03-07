#include "e.h"

e::e(void){
    x = 0;
}

e::e(int x){
    this->x=x;
}

e::~e(void){
}

void e::pideleAlUsuarioTusDatos(void){
    cout<<"Introduce la potencia a la que quieres elevar e"<<endl;
    cin>>x;
}

void e::muestraTusDatos(void){
    double i;
    double valor=0;
    double errorAbsoluto=0;
    double valor2 = 0;
    i=0;
    do{
        valor = pow(x,i) / fact(i);
        valor2 += valor;
        errorAbsoluto = (exp(x) - valor2) * 100;
        i++;
    }while(errorAbsoluto > 0.00000000);
    cout<<"e ^ "<<x<<" = "<<valor2<<endl;

}



int fact(int a){
  int F = 1;
    int i;
    for(i=1; i<=a; i++){
        F = F*i;
    }
    return F;

}
