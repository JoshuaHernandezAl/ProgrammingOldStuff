#ifndef RECTANGULOP_H
#define RECTANGULOP_H
#include "Punto.h"
#include <math.h>
#include <iostream>
using namespace std;

class RectanguloP
{
    private:
        Punto A,B;
        void verificaDimensiones(void);
    public:
        RectanguloP(void);
        RectanguloP(Punto A, Punto B);
        RectanguloP (double xA, double yA, double xB, double yB);
        ~RectanguloP(void);
        void muestraTusDatos(void);
        void pideleAlUsuarioTusDatos(void);
        double dameTuBase(void);
        double dameTuAltura(void);
        double dameTuArea(void);
        double dameTuPerimetro(void);
};

#endif // RECTANGULOP_H
