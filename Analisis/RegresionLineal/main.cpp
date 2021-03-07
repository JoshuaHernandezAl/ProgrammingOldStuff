#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
void minimosC(int puntos);
int main()
{
    int puntos;
    cout<<"Ingresa el numero de puntos (x,y) que se aproximaran por el metodo: "<<endl;
    cin>>puntos;
    minimosC(puntos);
    return 0;
}
void minimosC(int puntos){
    int *x, *y;
    double xp=0, yp,*xmc,*pxy,*xm,*ym,sumaxmc=0,sumapxy=0, a0,a1;
    x=new int[puntos];
    y=new int[puntos];
    xm=new double[puntos];
    xmc=new double[puntos];
    pxy=new double[puntos];
    ym=new double[puntos];

    cout<<"X: "<<endl;
    for(int i=0;i<puntos;i++){
        cout<<"x"<<i<<"= ";
        cin>>x[i];
    }
    cout<<"Y: "<<endl;
    for(int i=0;i<puntos;i++){
        cout<<"y"<<i<<"= ";
        cin>>y[i];
    }
    cout<<"x \t|y"<<endl;
    for(int i=0;i<puntos;i++){
        cout<<x[i]<<"\t|"<<y[i]<<endl;
    }
    cout<<endl;
    for(int i=0;i<puntos;i++){
        xp=xp+x[i];
    }
    xp=xp/puntos;
    cout<<"Xmedia= "<<xp<<endl;
    cout<<endl;
    for(int i=0;i<puntos;i++){
        yp=yp+y[i];
    }
    yp=yp/puntos;
    cout<<"Ymedia= "<<yp<<endl;

    cout<<"X-Xmedia: "<<endl;

    for(int i=0;i<puntos;i++){
      xm[i]= x[i]-xp;
    }
    for(int i=0;i<puntos;i++){
     cout<<xm[i]<<endl;
    }
    cout<<endl;
    cout<<"Y-Ymedia: "<<endl;
    for(int i=0;i<puntos;i++){
      ym[i]= y[i]-yp;
    }
    for(int i=0;i<puntos;i++){
     cout<<ym[i]<<endl;
    }
    cout<<endl;
    cout<<"(X-Xmedia)^2: "<<endl;
    for(int i=0;i<puntos;i++){
        xmc[i]=pow(xm[i],2);
    }
    for(int i=0;i<puntos;i++){
        cout<<xmc[i]<<endl;
    }
    cout<<endl;
    cout<<"(X-Xmedia)*(Y-Ymedia): "<<endl;

    for(int i=0;i<puntos;i++){
        pxy[i]=xm[i]*ym[i];
    }
    for(int i=0;i<puntos;i++){
        cout<<pxy[i]<<endl;
    }
    cout<<endl;
    cout<<"Suma (X-Xmedia)^2: "<<endl;
    for(int i=0;i<puntos;i++){
        sumaxmc=sumaxmc+xmc[i];
    }
    cout<<endl<<sumaxmc<<endl;
    cout<<endl;
    cout<<"Suma (X-Xmedia)*(Y-Ymedia): "<<endl;
    for(int i=0;i<puntos;i++){
        sumapxy=sumapxy+pxy[i];
    }
    cout<<endl<<sumapxy<<endl;
    cout<<endl;

    a1=sumapxy/sumaxmc;
    a0=yp-(a1*xp);
    cout<<"Ecuacion:"<<endl;
    cout<<"y="<<a0;
    if(a1>=0){
        cout<<"+";
    }
    cout<<a1<<"x";
};
