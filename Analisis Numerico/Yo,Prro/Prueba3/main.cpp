#include <iostream>
#include<math.h>
using namespace std;
class Newton
{
    private:
        double x,Er,Er0,converge,xn;

    public:
        Newton(void);
        ~Newton(void);
        void pideleAlUsuarioTusDatos(void);
        void muestraTusDatos(void);
        double f(double x);
        double f1(double x);
        double f2(double x);
};
Newton::Newton(void){
    x = 0.0;
    Er0=0.0;
}
Newton::~Newton(void){}
void Newton::pideleAlUsuarioTusDatos(void){
    cout<<"Introduce el valor de tu X0"<<endl;
    cin>>x;
    cout<<"Introduce el Valor de tu Error"<<endl;
    cin>>Er0;
    cout<<endl;
}

void Newton::muestraTusDatos(void){
    converge = fabs( (f(x)*f2(x)) / pow(f1(x),2));
        if(converge<1){
        do{
            xn = x - (f(x)/f1(x));
            Er = fabs((xn-x)/xn);
            x = xn;
        }while(Er>=Er0);
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
int main()
{
    Newton A;
    cout<<"Este programa obtiene la raiz de la expresion x^2 - 7 por el metodo de Newton-Rapson"<<endl<<endl;
    A.pideleAlUsuarioTusDatos();
    A.muestraTusDatos();
    return 0;
}

