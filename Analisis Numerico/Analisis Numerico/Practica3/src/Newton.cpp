#include "Newton.h"

Newton::Newton(void){
    x = 0.0;
}
Newton::~Newton(void){}
void Newton::pideleAlUsuarioTusDatos(void){
    cout<<"Introduce el valor de tu raiz"<<endl;
    cin>>x;
}

void Newton::muestraTusDatos(void){
    converge = fabs( (f(x)*f2(x)) / pow(f1(x),2));
        if(converge<1){
        do{
            xn = x - (f(x)/f1(x));
            Er = fabs((xn-x)/xn);
            x = xn;
        }while(Er>=0.001);
        cout<<"La raiz es = "<<x<<endl;
        }
        else
            cout<<"La raiz no converge"<<endl;
}

double Newton::f(double x){
    double res;
    res = pow(x,2)-7;
    return res;
}
double Newton::f1(double x){
    double res;
    res = 2*x;
    return res;
}
double Newton::f2(double x){
    double res;
    res = 2;
    return res;
}
