#include "Fecha.h"

void Fecha::verificaDatos(void){
    if(d<=0 ||d>31 || m<=0 || m>12 || a<=0){
        d=1;
        m=1;
        a=2018;
    }
}
Fecha:: Fecha(void){
    d=1;
    m=1;
    a=2018;
}
Fecha::Fecha(int d, int m, int a){
    this->d=d;
    this->m=m;
    this->a=a;
    verificaDatos();
}
Fecha::~Fecha(void){
}
void Fecha::pideleAlUsuarioTusDatos(void){
    cout<<"Dame el dia: "<<endl;
    cin>>d;
    cout<<"Dame el mes: "<<endl;
    cin>>m;
    cout<<"Dame el año: "<<endl;
    cin>>a;
    verificaDatos();
}
void Fecha::muestraTusDatos(void){
    cout<<d<<"/"<<m<<"/"<<a<<endl;
}
int Fecha::dameTuD(void){
    return d;
}
void Fecha::modificaTuD(int d){
    this->d=d;
    verificaDatos();
}
int Fecha::dameTuM(void){
    return m;
}
void Fecha::modificaTuM(int m){
    this->m=m;
    verificaDatos();
}
int Fecha::dameTuA(void){
    return a;
}
void Fecha::modificaTuA(int a){
    this->a=a;
    verificaDatos();
}
void Fecha::modificaTusDatos(int d, int m, int a){
    this->d=d;
    this->m=m;
    this->a=a;
    verificaDatos();
}
