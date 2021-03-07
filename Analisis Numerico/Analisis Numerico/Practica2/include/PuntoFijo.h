#ifndef PUNTOFIJO_H
#define PUNTOFIJO_H
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

class PuntoFijo
{
    private:
        float xo;
    public:
        PuntoFijo(void);
        PuntoFijo(float xo);
        ~PuntoFijo(void);
        void pideleAlUsuarioTusDatos(void);
        void muestraTusDatos(void);



};

#endif // PUNTOFIJO_H
