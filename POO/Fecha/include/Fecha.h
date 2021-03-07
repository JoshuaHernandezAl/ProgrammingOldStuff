#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;

class Fecha
{
    private:
        int d,m,a;
        void verificaDatos();
    public:
        Fecha(void);
        Fecha(int d, int m, int a);
        ~Fecha(void);
        void pideleAlUsuarioTusDatos(void);
        void muestraTusDatos(void);
        int dameTuD(void);
        void modificaTuD(int d);
        int dameTuM(void);
        void modificaTuM(int m);
        int dameTuA(void);
        void modificaTuA(int a);
        void modificaTusDatos(int d, int m, int a);
};

#endif // FECHA_H
