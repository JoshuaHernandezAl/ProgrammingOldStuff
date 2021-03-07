#include "Complejo.h"

Complejo::Complejo(void){
    real = 0.0;
    imaginario = 0.0;
}
Complejo::Complejo(float r, float i){
    real = r;
    imaginario = i;
}
void Complejo::pideDatos(void){
    cout<<"Dame mi real ";cin>>real;
    cout<<"Dame mi imaginario ";cin>>imaginario;
}
void Complejo::muestraDatos(void){
    printf("%lf",real);
    if(imaginario<0)
        printf("%lf",imaginario);
    else
        printf("+%lf",imaginario);
    printf("i");
}
double Complejo::dameTuReal(void){
    return real;
}
void Complejo::modificaTuReal(double r){
    real = r;
}
double Complejo::dameTuImaginario(void){
    return imaginario;
}
void Complejo::modificaTuImaginario(double i){
    imaginario = i;
}
Complejo Complejo::operator=(Complejo A){
    real = A.dameTuReal();
    imaginario = A.dameTuImaginario();
    Complejo copia(real,imaginario);
    return copia;
}
Complejo suma(Complejo A, Complejo B){
    Complejo R(
               A.dameTuReal()+B.dameTuReal()
               ,
               A.dameTuImaginario()+B.dameTuImaginario()
            );
    return R;
}
Complejo resta(Complejo A, Complejo B){
    Complejo R(
               A.dameTuReal()-B.dameTuReal()
               ,
               A.dameTuImaginario()-B.dameTuImaginario()
            );
    return R;
}
Complejo multiplica(Complejo A, Complejo B){
    Complejo R(
               A.dameTuReal()*B.dameTuReal()
               -
               A.dameTuImaginario()*B.dameTuImaginario()
               ,
               A.dameTuReal()*B.dameTuImaginario()
               +
               A.dameTuImaginario()*B.dameTuReal()
            );
    return R;
}
Complejo divide(Complejo A, Complejo B){
    Complejo R(
        (A.dameTuReal()*B.dameTuReal() + A.dameTuImaginario()*B.dameTuImaginario())
        /
        (pow(B.dameTuReal(),2)+pow(B.dameTuImaginario(),2))
        ,
        (A.dameTuImaginario()*B.dameTuReal()-A.dameTuReal()*B.dameTuImaginario())
        /
        (pow(B.dameTuReal(),2)+pow(B.dameTuImaginario(),2))
    );
    return R;
}
Complejo operator+(Complejo A, Complejo B){
    return suma(A,B);
}
Complejo operator-(Complejo A, Complejo B){
    return resta(A,B);
}
Complejo operator*(Complejo A, Complejo B){
    return multiplica(A,B);
}
Complejo operator/(Complejo A, Complejo B){
    return divide(A,B);
}

Complejo pow(Complejo A, int n){
    Complejo R(1,0);
    if(n<=0)
        return R;
    else if(n==1)
        return A;
    else{
        for(int i=1;i<=n;i++)
            R = R*A;
        return R;
    }
}
double fabs(Complejo A){
    return sqrt(pow(A.dameTuReal(),2)+pow(A.dameTuImaginario(),2));
}
istream& operator>>(istream& teclado, Complejo& Derecho){
    Derecho.pideDatos();
    return teclado;
}
ostream& operator<<(ostream& monitor, Complejo Derecho){
    Derecho.muestraDatos();
    return monitor;
}


