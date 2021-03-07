#ifndef RECTANGULO_H
#define RECTANGULO_H

#include <iostream>
using namespace std;
class Rectangulo
{
    private:
        double area,perimetro,base,altura;
        void calculaArea(void);
        void calculaPerimetro(void);
        void verificaBaseYAltura(void);
    public:
        Rectangulo(void);
        Rectangulo (double b,double h);
        ~Rectangulo(void);
        void pideleAlUsuarioTusDatos(void);
        void muestraTusDatos(void);
        double dameTuBase(void);
        double dameTuAltura(void);
        double dameTuArea(void);
        double dameTuPerimetro(void);
        void modificaTuBase(double b);
        void modificaTuAltura(double h);

};

#endif // RECTANGULO_H
