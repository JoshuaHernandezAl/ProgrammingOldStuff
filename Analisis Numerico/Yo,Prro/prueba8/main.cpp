#include <iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

class EulerM{
    private:
        double x0,y0,h,x,y,y1;
    public:
        EulerM(void);
        ~EulerM(void);
        void pideleAlUsuarioTusDatos(void);
        void muestraTusDatos(void);
		double f(double, double);
};
EulerM::EulerM(void){
    x0 = 0.0;
    h=0.0;
    y0=0.0;
    x=0;
    y=0;
    y1=0;
}
EulerM::~EulerM(void){
}

void EulerM::pideleAlUsuarioTusDatos(void){
    do{
		cout<<"Ingrese condiciones iniciales:"<<endl;
		cout<<"x0= ";
		cin>>x0;
		cout<<"y0= ";
		cin>>y0;
		cout<<"h:";
		cin>>h;
		cout<<"Ingrese valor x= ";
		cin>>x;
	}while(x0>x || h<=0);
}

void EulerM::muestraTusDatos(void){
	float x1;
	x1=0;
    do{
    	x1=x0+h;
		y1=y0+(h*f(x0,y0));
		y=y0+((h*(f(x0,y0)+f((x0+h),y1)))/2);
		x0=x1;
		y0=y;
		cout<<y0<<endl;
	}while(x0<x);
	cout<<endl<<"y("<<x<<")= "<<y<<endl;
}

double EulerM::f(double x,double y){
	return (x+(1/(5*y)));
}

int main(){
    EulerM B;
    cout<<"Programa de Euler Mejorado"<<endl<<endl;
        B.pideleAlUsuarioTusDatos();
        B.muestraTusDatos();
    return 0;
}
