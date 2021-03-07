#ifndef CIRCULOP_H
#define CIRCULOP_H
#include "Punto.h"
#include <iostream>
#include <math.h>
using namespace std;

class CirculoP
{
    private:
        Punto C,P;
    public:
        CirculoP(void);
        CirculoP(Punto C, Punto P);
        CirculoP(double xC,double yC, double xP, double yP);
        ~CirculoP(void);
        void muestraTusDatos(void);
        void pideleALUsuarioTusDatos(void);
        Punto dameTuC(void);
        void modificaTuC(Punto C);
        Punto dameTuP(void);
        void modificaTuP(Punto P);
        double dameTuArea(void);
        double dameTuPerimetro(void);
        double dameTuRadio(void);
        double dameTuDiametro(void);
};

#endif // CIRCULOP_H
