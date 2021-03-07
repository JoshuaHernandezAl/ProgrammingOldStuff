#include <iostream>
#include "Series.h"
using namespace std;

int main()
{
    Series S,S2;
    int iteraciones,it;
    iteraciones=S.itereacionesE(2);
    cout<<"Las iteraciones necesarias para e fueron: "<<iteraciones<<endl;
    it=S2.iteracionesSen(45);
    cout<<"Las iteraciones necesarias para sen fueron: "<<it;
    return 0;
}
