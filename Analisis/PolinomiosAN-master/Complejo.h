#ifndef COMPLEJO_H
#define COMPLEJO_H


#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
class Complejo{
private:
    double real;
    double imaginario;
public:
    Complejo(void);
    Complejo(float r, float i);
    void pideDatos(void);
    void muestraDatos(void);
    double dameTuReal(void);
    void modificaTuReal(double r);
    double dameTuImaginario(void);
    void modificaTuImaginario(double i);
    Complejo operator=(Complejo A);
};
Complejo suma(Complejo A, Complejo B);
Complejo resta(Complejo A, Complejo B);
Complejo multiplica(Complejo A, Complejo B);
Complejo divide(Complejo A, Complejo B);
Complejo pow(Complejo A, int n);
double fabs(Complejo A);
istream& operator>>(istream& teclado, Complejo& Derecho);
ostream& operator<<(ostream& monitor, Complejo Derecho);
Complejo operator+(Complejo A, Complejo B);
Complejo operator-(Complejo A, Complejo B);
Complejo operator*(Complejo A, Complejo B);
Complejo operator/(Complejo A, Complejo B);


#endif // COMPLEJO_H
