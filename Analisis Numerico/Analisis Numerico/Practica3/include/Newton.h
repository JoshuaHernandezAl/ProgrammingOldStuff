#ifndef NEWTON_H
#define NEWTON_H
#include<iostream>
#include<math.h>

using namespace std;

class Newton
{
    private:
        double x,Er,converge,xn;

    public:
        Newton(void);
        ~Newton(void);
        void pideleAlUsuarioTusDatos(void);
        void muestraTusDatos(void);
        double f(double x);
        double f1(double x);
        double f2(double x);




};

#endif // NEWTON_H
