#ifndef TRIANGULO_H
#define TRIANGULO_H

#include <iostream>
#include <math.h>
using namespace std;
class Triangulo
{
    private:
        double area,perimetro,altura,lado;
        void calculaArea(void);
        void calculaPerimetro(void);
        void calculaAltura(void);
        void verificaTuLado(void);
    public:
        Triangulo(void);
        Triangulo (double la);
        ~Triangulo(void);
        void pideleAlUsuarioTusDatos(void);
        void muestraTusDatos(void);
        double dameTuLado(void);
        void modificaTuLado(double lado);
        double dameTuArea(void);
        double dameTuPerimetro(void);

};

#endif // TRIANGULO_H
