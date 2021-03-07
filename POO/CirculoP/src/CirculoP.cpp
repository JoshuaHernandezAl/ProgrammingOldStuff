#include "CirculoP.h"

CirculoP::CirculoP(void){
}
CirculoP::CirculoP(Punto C, Punto P){
    this->C=C;
    this->P=P;
}
CirculoP::CirculoP(double xC,double yC, double xP, double yP){
    this->C.modificaTuX(xC);
    this->C.modificaTuY(yC);
    this->P.modificaTuX(xP);
    this->P.modificaTuY(yP);
}
CirculoP::~CirculoP(void){
}
void CirculoP::muestraTusDatos(void){
    cout<<this->C<<endl<<this->P<<endl
    <<"Radio: "<<this->dameTuRadio()<<endl
    <<"Diametro: "<<this->dameTuDiametro()<<endl
    <<"Area: "<<this->dameTuArea()<<endl
    <<"Perimetro: "<<this->dameTuPerimetro()<<endl;
}
void CirculoP::pideleALUsuarioTusDatos(void){
    cout<<"C: "<<endl;
    cin>>C;
    cout<<"P: "<<endl;
    cin>>P;
}
Punto CirculoP::dameTuC(void){
    return C;
}
void CirculoP::modificaTuC(Punto C){
    this->C=C;
}
Punto CirculoP::dameTuP(void){
    return P;
}
void CirculoP::modificaTuP(Punto P){
    this->P=P;
}
double CirculoP::dameTuArea(void){
    return M_PI*pow(this->dameTuRadio(),2);
}
double CirculoP::dameTuPerimetro(void){
    return M_PI*this->dameTuDiametro();
}
double CirculoP::dameTuRadio(void){
    return distanciaEntre(this-> C, this->P);
}
double CirculoP::dameTuDiametro(void){
    return 2*this->dameTuRadio();
}
