#ifndef LN_H
#define LN_H
#include<iostream>
#include<math.h>
using namespace std;

class Ln
{
    private:
        int x;
        double valor;

    public:
        Ln(void);
        Ln(int x);
        ~Ln(void);
        void pideleAlUsuarioTusDatos(void);
        void muestraTusDatos(void);

};

#endif // LN_H
