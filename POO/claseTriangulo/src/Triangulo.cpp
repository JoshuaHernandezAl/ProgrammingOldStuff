#include "Triangulo.h"

void Triangulo::verificaTuLado(void){
    if(lado<0)
        lado=0.0;

}
void Triangulo::calculaAltura(void){
    altura=sqrt(pow(lado,2)-pow((lado/2),2));
}
void Triangulo::calculaArea(void){
    area=(lado*altura)/2;
}
void Triangulo::calculaPerimetro(void){
    perimetro=lado*3;
}
Triangulo::Triangulo(void){
    lado=0.0;
    this->calculaAltura();
    this->calculaArea();
    this->calculaPerimetro();
}
Triangulo::~Triangulo(void){
}
Triangulo::Triangulo(double la){
    lado=la;
    this->verificaTuLado();
    this->calculaAltura();
    this->calculaArea();
    this->calculaPerimetro();
}
void Triangulo::pideleAlUsuarioTusDatos(void){
    cout<<"Dame tu lado: "<<endl;
    cin>>lado;
    this->verificaTuLado();
    this->calculaAltura();
    this->calculaArea();
    this->calculaPerimetro();
}
void Triangulo::muestraTusDatos(void){
    cout<<"Lado: "<<lado<<endl;
    cout<<"Altura: "<<altura<<endl;
    cout<<"Area: "<<area<<endl;
    cout<<"Perimetro: "<<perimetro<<endl;
}
double Triangulo::dameTuLado(void){
    return lado;
}
void Triangulo::modificaTuLado(double lado){
    this->lado=lado;
    this->verificaTuLado();
    this->calculaAltura();
    this->calculaArea();
    this->calculaPerimetro();
}
double Triangulo::dameTuArea(void){
    return area;
}
double Triangulo::dameTuPerimetro(void){
    return perimetro;
}
