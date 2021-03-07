#ifndef E_H
#define E_H
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;
class e
{
    private:
        double x;
        double valor;

    public:
        e(void);
        e(int x);
        ~e(void);
        void pideleAlUsuarioTusDatos(void);
        void muestraTusDatos(void);



};

int fact(int a);
#endif // E_H
