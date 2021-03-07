#ifndef SISTEMA_H
#define SISTEMA_H


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Ecuacion.h"
using namespace std;
class Sistema{
private:
    int m,n;
    Ecuacion* E;
    double** M;

    void reservaMemoria(void);
    void liberaMemoria(void);
    void rellenaMatriz(void);
    void rellenaFila(int fila);
    bool calculaEpsilon(double* xi, double* xs, double eS);
public:
    Sistema(void);
    Sistema(int tam);
    ~Sistema(void);
    void pideDatos(void);
    void pideSistema(void);
    void muestraSistema(void);
    void LU(void);
    void Gauss(void);
    void GaussJordan(void);
    void GaussSeidel(void);
};
#endif // SISTEMA_H
