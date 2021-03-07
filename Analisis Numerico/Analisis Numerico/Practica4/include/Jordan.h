#ifndef JORDAN_H
#define JORDAN_H
#include<iostream>

using namespace std;

class Jordan
{
    private:
        double R[4][4];
        double S[4][4];


    public:
        Jordan(void);
        ~Jordan(void);
        void pideleAlUsuarioTusDatos(void);
        void muestraTusDatos(void);
        void calcula(void);

};

#endif // JORDAN_H
