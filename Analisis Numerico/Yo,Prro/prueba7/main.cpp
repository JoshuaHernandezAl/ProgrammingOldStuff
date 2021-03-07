#include <iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

class RungeKutta
{
    private:
        float h,xo,yo;
    public:
        RungeKutta(void);
        ~RungeKutta(void);
        void pideleAlUsuarioTusDatos(void);
        void muestraTusDatos(void);

};
RungeKutta::RungeKutta(void){
    xo = 0.0;
    h=0.0;
    yo=0.0;
}
RungeKutta::~RungeKutta(void){
}

void RungeKutta::pideleAlUsuarioTusDatos(void){
    cout<<"Introduce el valor de Xo"<<endl;
    cin>>xo;
    cout<<endl;
    cout<<"Introduce el valor de Yo"<<endl;
    cin>>yo;
    cout<<endl;
    cout<<"Introduce el valor de h"<<endl;
    cin>>h;
    cout<<endl;
}
void RungeKutta::muestraTusDatos(void){
    int op;
    float k1,k2,k3,k4,y,x;
    k1=k2=k3=k4=y=x=0;
	do{
    cout<<"1) Resolver por Segundo Orden\n"<<endl;
    cout<<"2) Resolver por Cuarto Orden\n"<<endl;
    cout<<"3) Salir\n"<<endl;
    cout<<"Cual es tu opcion?\n"<<endl;
    cin>>op;
    cout<<endl;
    switch(op){
    case 1:
    	cout<<"x-y"<<endl;
    	cout<<xo<<"-"<<yo<<endl;
		do{
			x=xo+h;
			k1=h*(xo+(2*xo*yo));
			k2=h*((xo+h)+(2*(xo+h)*(yo+k1)));
			xo=x;
			cout<<x<<"-";
			y=(yo)+((k1+k2)/2);
			cout<<y<<endl;
			yo=y;
    	}while(x<1);
		system("pause");
		exit(1);
        break;
    case 2:
        cout<<"x-y"<<endl;
    	cout<<xo<<"-"<<yo<<endl;
		do{
			x=xo+h;
			k1=h*(xo+(2*xo*yo));
			k2=h*((xo+(h/2))+(2*(xo+(h/2))*(yo+(k1/2))));
			k3=h*((xo+(h/2))+(2*(xo+(h/2))*(yo+(k2/2))));
			k4=h*((xo+h)+(2*(xo+h)*(yo+k3)));
			xo=x;
			cout<<x<<"-";
			y=yo+((k1+(2*k2)+(2*k3)+k4)/6);
			cout<<y<<endl;
			yo=y;
    	}while(x<1);
		system("pause");
		exit(1);
        break;
    case 3:
        cout<<"Hasta pronto"<<endl;
        system("pause");
    	exit(1);
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;  }
    system("pause");
    system("cls");
    }while(op!=3);
}

int main(){
    RungeKutta B;
    cout<<"Programa de Ruge-Kutta"<<endl<<endl;
        B.pideleAlUsuarioTusDatos();
        B.muestraTusDatos();
    return 0;
}
