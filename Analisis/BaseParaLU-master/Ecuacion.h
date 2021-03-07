#ifndef ECUACION_H
#define ECUACION_H


#include <iostream>
#include <stdio.h>
#include <math.h>
#include "NodoP.h"
using namespace std;

class Ecuacion{
friend class Sistema;

protected:
    NodoP* ini;
public:
    Ecuacion(void);
    ~Ecuacion(void);
    bool estaVacio(void);
    void muestraEcuacion(void);
    void eliminaEcuacion(void);
    void insertaTermino(Termino A);
    void insertaTermino(double c, string N);
    bool eliminaTermino(Termino A);
    bool eliminaTermino(double c, string N);
    void ingresaEcuacion(void);
};


#endif // ECUACION_H
