#ifndef SADEN_H
#define SADEN_H
#include<iostream>

using namespace std;

class Saden
{
    private:
        float A[3][3],B[3][3];


    public:
        Saden(void);
        ~Saden(void);
        void pideleAlUsuarioTusDatos(void);
        void muestraTusDatos(void);
        void calcula(void);


};

#endif // SADEN_H
