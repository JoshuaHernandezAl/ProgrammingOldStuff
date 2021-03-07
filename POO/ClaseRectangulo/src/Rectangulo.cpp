#include "Rectangulo.h"

void Rectangulo::calculaArea(void){
    area=base*altura;
}
void Rectangulo::calculaPerimetro(void){
    perimetro=2*base+2*altura;
}
void Rectangulo::verificaBaseYAltura(void){
    if(base<0 || altura<0){
        base=0.0;
        altura=0.0;
    }
}
Rectangulo::Rectangulo(void){
    base=0.0;
    altura=0.0;
    this->calculaArea();
    this->calculaPerimetro();
}
Rectangulo::~Rectangulo(void){
}
Rectangulo::Rectangulo(double b, double h){
    base=b;
    altura=h;
    this->verificaBaseYAltura();
    this->calculaArea();
    this->calculaPerimetro();
}
void Rectangulo::pideleAlUsuarioTusDatos(void){
    cout<<"Dame tu base: "<<endl;
    cin>>base;
    cout<<"Dame tu altura: "<<endl;
    cin>>altura;
    this->verificaBaseYAltura();
    this->calculaArea();
    this->calculaPerimetro();
}
void Rectangulo::muestraTusDatos(void){
    cout<<"Base: "<<base<<endl;
    cout<<"Altura: "<<altura<<endl;
    cout<<"Area: "<<area<<endl;
    cout<<"Perimetro: "<<perimetro<<endl;
}
double Rectangulo::dameTuAltura(void){
    return altura;
}
double Rectangulo::dameTuArea(void){
    return area;
}
double Rectangulo::dameTuBase(void){
    return base;
}
double Rectangulo::dameTuPerimetro(void){
    return perimetro;
}
void Rectangulo::modificaTuBase(double b){
    this->base=b;
    this->verificaBaseYAltura();
    this->calculaArea();
    this->calculaPerimetro();
}
void Rectangulo::modificaTuAltura(double h){
    this->altura=h;
    this->verificaBaseYAltura();
    this->calculaArea();
    this->calculaPerimetro();
}
