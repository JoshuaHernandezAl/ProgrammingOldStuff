#include<conio.h>
#include<math.h>
#define e 2.71818283
#define max 15
#include<iostream>

using namespace std;

float d(float g)
{ return pow(2,g);}

float f(float j)
{float fun=pow(e,j);
return fun;}

int main()
{
float R[70][70];
int k,m;
float a,b,h,aux;
cout<<"\n";
cout<<" METODO DE ROSEMBERG PARA APROXIMACION DE INTEGRALES"<<endl<<endl;
cout<<" Numero de Iteraciones: ";
cin>>k;
cout<<" Ingresar limite inferior: ";
cin>>a;
cout<<" Ingresar limite superior: ";
cin>>b;
h=b-a;

cout<<"\n";
R[0][0]=(h/d(1))*(f(a)+f(b));

cout<<R[0][0];
m=2;
//llena la columna R[k][0] con los valores correspondientes
for(int i=1;i<k;i++)
{aux=0;
for (int n=1;n<m;n++){
aux=aux+f(a+((2*n)*h/d(m)));}
R[i][0]=(1/2)*(R[i-1][0]+(h/d(m-1)*aux));
m=m+1;}

//imprime la columna 0
cout<<endl;
for(int i=0;i<k-1;i++){
cout<<R[i][0];cout<<endl;}

// llena las demas columnas con los valores respectivos
for(int i=1;i<k-1;i++){
for(int j=1;j<k-1;j++){
R[i][j]=R[i][j-1]+((R[i][j-1]- R[i-1][j-1])/(pow(4,j-1)-1));
}
}
cout<<"\n";
cout<<"\n";
//Imprime la matriz de orden k con los valores a las aproximaciones
cout<<"MATRIZ QUE MUESTRA LAS SOLUCIONES";
cout<<"\n";cout<<"\n";
for(int i=0;i<k-1;i++){
for(int j=0;j<k-1;j++){
cout <<R[i][j] << " ";}}


getch();

}
