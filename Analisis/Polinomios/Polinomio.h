#ifndef POLINOMIO_H
#define POLINOMIO_H


#include <iostream>
#include <math.h>
#include "Complejo.h"
#include "NodoP.h"
using namespace std;
class Polinomio{
private:
    NodoP* ini;
public:
    Polinomio(void);
    ~Polinomio(void);
    bool estaVacio(void);
    void muestraPolinomio(void);
    void eliminaPolinomio(void);
    void insertaTermino(Termino A);
    void insertaTermino(float c, int e);
    bool eliminaTermino(Termino A);
    bool eliminaTermino(float c, int e);
    void ingresaPolinomio(void);
    void suma(Polinomio& P1, Polinomio& P2);
    void resta(Polinomio& P1, Polinomio& P2);
    void multiplica(Polinomio& P1, Polinomio& P2);
    void deriva(Polinomio& P);
    float evalua(double x);
    Complejo evalua(Complejo x);
};


#endif // POLINOMIO_H
