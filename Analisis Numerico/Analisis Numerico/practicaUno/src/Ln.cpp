#include "Ln.h"
Ln::Ln(void){
    x = 0;
}

Ln::Ln(int x){
    this->x=x;
}

Ln::~Ln(void){
}

void Ln::pideleAlUsuarioTusDatos(void){
    cout<<"Introduce el valor de x"<<endl;
    cin>>x;
}

void Ln::muestraTusDatos(void){
    double i;
    double valor=0;
    double errorAbsoluto=0;
    double valor2 = 0;
    i=0;
    do{
        valor = pow(-1,i+1)*pow(x,i) / i;
        valor2 += valor;
        errorAbsoluto = (log(x) - valor2) * 100;
        i++;
    }while(errorAbsoluto >= 0.000000001);
    cout<<"Ln(1 + "<<x<<") = "<<valor2<<endl;

}

