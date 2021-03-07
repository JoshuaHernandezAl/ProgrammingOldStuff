#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

class euler{
      private:  double xi,yi,h,xf,n;
      public:   void lee();
                double f(double , double);
                double metodo();
};
void euler::lee()
{   cout<<"------Metodo de Euler mejorado------------"<<endl;
    cout<<"Ingresa los siguientes valores: "<<endl;
	do{
		cout<<"Ingresa xi: ";
		cin>>xi;
		cout<<"Ingresa yi: ";
		cin>>yi;
		cout<<"Ingresa h: ";
		cin>>h;
		cout<<"Ingresa xf: ";
		cin>>xf;
		cout<<"Ingresa numero de iteraciones: ";
		cin>>n;
	}while(xi>xf||h<=0);
}
double euler::f(double x, double y)
{
	return x+(1/5)*y;
}
double euler::metodo()
{   
	double yp,yc,aux;
	int i;
    cout<<"resultado= "<<yi<<endl;
    for(i=0;i<=n;i++){	
	aux=xi+h;
	yp=yi+h*f(xi,yi);
	yc=yi+(h*(f(xi,yi)+f(aux,yp)))/2;
	 if(xi<xf)
	  {
		yi=yc;
        xi=aux;
	    aux=xi+i*h;
		yp=yc;
	  }i++;
 cout<<"Resultado= "<<yc<<i<<endl;
 
                    }
}
int main()
{
    euler obj;
    obj.lee();
    obj.metodo();
    system("pause");
    return 0;
}
