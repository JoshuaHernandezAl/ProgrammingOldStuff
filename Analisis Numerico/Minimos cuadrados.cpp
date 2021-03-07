
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
class MC
{
      private:
              int i,j,N,P;
              float x[20], y[20],xy[20],x2[20],X,Y,Sx,Sy,Sxy,Sx2,m,b;
      public:
             MC ();
             void Lee ();
             void Metodo ();
             void Mostrar ();
};
MC::MC ()
{   
           m=b=0.0;
           N=P=i=j=0;
           for (i=0;i<20;i++)
           {
               x[i]=y[i]=xy[i]=x2[i]=0.0;
           }
               
}
void MC::Lee ()
{
     cout<<"\n Introduzca el número de datos que ingresará"<<endl;
     cin>>N;
     cout<<"Introduzca los valores de X, seguidos de los de Y"<<endl;
     for(i=0;i<N;i++)
     {
                                       cout<<"X["<<i+1<<"]  ";
                                       cin>>x[i];
                                       cout<<"y["<<i+1<<"]  ";
                                       cin>>y[i];
     }
     cout<<endl;    
     cout<<"Introduzca el valor inicial de X"<<endl;
     cin>>X;
}
void MC::Metodo ()
{
     for (i=0;i<N;i++)
     {
             xy[i]=x[i]*y[i];
             x2[i]= pow (x[i],2);
     }
     for (i=0;i<N;i++)
     {
         Sx=Sx+x[i];
         Sy=Sy+y[i];
         Sxy=Sxy+xy[i];
         Sx2=Sx2+x2[i];
     }
     m=((N*Sxy)-(Sx*Sy))/((N*Sx2)-(pow (Sx,2))); ; cout<<m<<endl;
     b =((Sy*Sx2)-(Sx*Sxy))/((N*Sx2)-(pow (Sx,2)));
     Y=(m*X)+b; cout<<Y<<endl;
} 
void MC::Mostrar ()
{
    
        
}
int main()
{
MC O; 
cout<<"Método de Mínimos Cuadrados"<<endl;
O.Lee ();
O.Metodo ();
//cout<<endl;
//cout<<"La solución es:"<<endl;
//O.Mostrar ();
system("PAUSE");
}
