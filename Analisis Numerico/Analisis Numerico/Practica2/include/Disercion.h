#ifndef DISERCION_H
#define DISERCION_H
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

class Disercion
{
    private:
        float x0,xn;

    public:
        Disercion(void);
        Disercion(float x0, float xn);
        ~Disercion(void);
        void pideleAlUsuarioTusDatos(void);
        void muestraTusDatos(void);


};

#endif // DISERCION_H
