#include "RectanguloP.h"

void RectanguloP::verificaDimensiones(void){
    if(A.dameTuX()==B.dameTuX() || A.dameTuY()==B.dameTuY()){
        this->A.modificaTuX(0.0);
        this->A.modificaTuY(0.0);
        this->B.modificaTuX(0.0);
        this->B.modificaTuY(0.0);
    }
}
RectanguloP::RectanguloP(void){
}
RectanguloP::RectanguloP(Punto A, Punto B){
    this->A=A;
    this->B=B;
    verificaDimensiones();
}
RectanguloP::RectanguloP (double xA, double yA, double xB, double yB){
    this->A.modificaTuX(xA);
    this->A.modificaTuY(yA);
    this->B.modificaTuX(xB);
    this->B.modificaTuY(yB);
    verificaDimensiones();
}
RectanguloP::~RectanguloP(void){
}
void RectanguloP::muestraTusDatos(void){
    cout<<this->A<<endl<<this->B<<endl
    <<"Base: "<<this->dameTuBase()<<endl
    <<"Altura: "<<this->dameTuAltura()<<endl
    <<"Area: "<<this->dameTuArea()<<endl
    <<"Perimetro: "<<this->dameTuPerimetro()<<endl;
}
void RectanguloP::pideleAlUsuarioTusDatos(void){
    cout<<"A: "<<endl;
    cin>>this->A;
    cout<<"B: "<<endl;
    cin>>this->B;
    verificaDimensiones();
}
double RectanguloP::dameTuBase(void){
    return fabs(A.dameTuX()-B.dameTuX());
}
double RectanguloP::dameTuAltura(void){
    return fabs(A.dameTuY()-B.dameTuY());
}
double RectanguloP::dameTuArea(void){
    return this->dameTuBase()*this->dameTuAltura();
}
double RectanguloP::dameTuPerimetro(void){
    return (2*this->dameTuBase())+ (2*this->dameTuAltura());
}
