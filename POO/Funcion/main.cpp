#include <iostream>
#include <math.h>
#include "Punto.h"
using namespace std;
double f(double x);
double gradosARadianes(double grados);
int main()
{
    Punto A;
    double ini,fin,paso;
    cout<<"Dame inicio ";
    cin>>ini;
    cout<<"Dame fin ";
    cin>>fin;
    cout<<"Dame incremento: ";
    cin>>paso;
    cout<<"x\tf(x)"<<endl<<endl;
    for(A.modificaTuX(ini);A.dameTuX()<=fin;A.modificaTuX(A.dameTuX()+ paso)){
        A.modificaTuY(f(A.dameTuX()));
        cout<<A.dameTuX()<<"\t\t"<<A.dameTuY()<<endl;
    }

    return 0;
}
double f(double x){
    return cos(gradosARadianes(x));
}
double gradosARadianes(double grados){
    return grados*M_PI/180;
}
