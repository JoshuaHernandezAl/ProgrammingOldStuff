#include "Termino.h"

Termino::Termino(void){
}
Termino::Termino(double c, string N){
    coeficiente = c;
    Nombre = N;
}
void Termino::pideDatos(void){
    cout<<"Dame coeficiente "<<endl;cin>>coeficiente;
    cout<<"Dame Nombre ";cin>>Nombre;
}
void Termino::muestraDatos(void){
    if(coeficiente!=0){
        if(coeficiente == -1 && Nombre!="~"){
            cout<<"-"<<Nombre;
        }
        else if(coeficiente == 1 && Nombre!="~"){
            cout<<Nombre;
        }
        else if(Nombre=="~"){
            cout<<coeficiente;
            //printf("%lf",coeficiente);
        }
        else if(coeficiente==1){
//            printf("%lf",coeficiente);
//            cout<<Nombre;
            cout<<coeficiente<<Nombre;
        }
        else{
//            printf("%lf",coeficiente);
//            cout<<Nombre;
            cout<<coeficiente<<Nombre;
        }
    }
}
double Termino::dameCoeficiente(void){
    return coeficiente;
}
void Termino::modificaCoeficiente(double c){
    coeficiente = c;
}
string Termino::dameNombre(void){
    return Nombre;
}
void Termino::modificaNombre(string N){
    Nombre = N;
}
istream& operator>>(istream& teclado, Termino& Derecho){
    Derecho.pideDatos();
    return teclado;
}
ostream& operator<<(ostream& monitor, Termino Derecho){
    Derecho.muestraDatos();
    return monitor;
}
bool operator==(Termino Izquierdo, Termino Derecho){
    return  Izquierdo.dameCoeficiente() == Derecho.dameCoeficiente()
            &&
            Izquierdo.dameNombre() == Derecho.dameNombre();
}
bool operator!=(Termino Izquierdo, Termino Derecho){
    return  Izquierdo.dameCoeficiente() != Derecho.dameCoeficiente()
            ||
            Izquierdo.dameNombre() != Derecho.dameNombre();
}

