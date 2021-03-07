#ifndef TERMINO_H
#define TERMINO_H

#include <iostream>
#include <stdio.h>
using namespace std;

class Termino{
private:
    double coeficiente;
    string Nombre;
public:
    Termino(void);
    Termino(double c, string N);
    void pideDatos(void);
    void muestraDatos(void);
    double dameCoeficiente(void);
    void modificaCoeficiente(double c);
    string dameNombre(void);
    void modificaNombre(string N);
};
istream& operator>>(istream& teclado, Termino& Derecho);
ostream& operator<<(ostream& monitor, Termino Derecho);
bool operator==(Termino Izquierdo, Termino Derecho);
bool operator!=(Termino Izquierdo, Termino Derecho);

#endif // TERMINO_H
