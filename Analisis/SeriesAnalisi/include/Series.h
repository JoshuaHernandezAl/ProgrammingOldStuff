#ifndef SERIES_H
#define SERIES_H

#include <math.h>
#include <iostream>
using namespace std;
class Series
{
    private:
        int x;
    public:
        Series(void);
        ~Series(void);
        int itereacionesE(int x);
        int iteracionesSen(int x);

};
int factorial(int n);

#endif // SERIES_H
