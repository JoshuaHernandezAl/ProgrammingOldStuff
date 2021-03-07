#ifndef GAUSS_H
#define GAUSS_H
#include<iostream>

using namespace std;

class Gauss
{
    private:
        double M[4][4];
        double N[4][4];


    public:
        Gauss(void);
        ~Gauss(void);
        void pideleAlUsuarioTusDatos(void);
        void muestraTusDatos(void);
        void calcula(void);
        void calculaDos(void);


};

#endif // GAUSS_H
