//Método de Rugenkutta 4to orden
#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

class Rugenkutta{
      private: double xi,yi,h,xf,n;
      public:  void Datos();
               double f(double , double);
               double rk4();
};
void Rugenkutta::Datos()
{   cout<<"-----------Metodo de Rugenkutta de 4to Orden------------"<<endl;
	do{
        cout<<"Ingresa los siguientes valores: "<<endl;
		cout<<"Ingresa xi: ";
		cin>>xi;
		cout<<"Ingresa yi: ";
		cin>>yi;
		cout<<"Ingresa h: ";
		cin>>h;
		cout<<"Ingresa xf: ";
		cin>>xf;
		cout<<"Ingresa numero de Iteraciones: ";
		cin>>n;
	 }while(xi>xf||h<=0);
}
double Rugenkutta::f(double x, double y)
{
	return x+2*x*y;
}
double Rugenkutta::rk4()
{
    double k1,k2,k3,k4,yf,s;
    int i;
    cout<<"Resultado="<<yi<<endl;
    for(i=0;i<n;i++){
    k1=h*f(xi,yi);
     k2=h*f(xi+(0.5)*h,yi+(0.5)*k1);
     k3=h*f(xi+(0.5)*h,yi+(0.5)*k2);
     k4=h*f(xi+h,yi+k3);
     yf=yi+((0.166667)*(k1+2*k2+2*k3+k4));
     if(xi<xf)
      {
       yi=yf;
       xi=xi+h;
      }
cout<<"Resultado= "<<yf<<endl;
                    }
}
int main()
{
    Rugenkutta obj;
    obj.Datos();
    obj.rk4();
    system("pause");
    return 0;
}

