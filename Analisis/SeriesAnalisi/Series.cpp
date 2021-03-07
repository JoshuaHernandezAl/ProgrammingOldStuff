#include "Series.h"

Series::Series(void){
}
Series::~Series(void){
}
int Series::itereacionesE(int x){
    double t,s=0;
    long double Ea;
    int i=0;
    do{
        t=pow(x,i)/factorial(i);
        s+=t;
        Ea=fabs(exp(x)-s);
        i++;
    }while(Ea>=0.00001);
    cout<<"t="<<t<<endl;
    cout<<"s="<<s<<endl;
    cout<<"Ea="<<Ea<<endl;
    return (i-1);
}
int Series::iteracionesSen(int x){
    double seno=0,angulo;
    angulo=x*M_PI/180;
    int i=0;
    long double Ea;
    do{
        seno=seno+(pow(-1,i)*pow(angulo,2*i+1)/factorial(2*i+1));
        cout<<"seno="<<seno<<endl;
        Ea=fabs(sin(angulo)-seno);
        cout<<"Ea="<<Ea<<endl;
        i++;
    }while(Ea>=0.00001);
    cout<<"seno="<<seno<<endl;
    cout<<"Ea="<<Ea<<endl;
    return (i-1);
}
int factorial(int n){
    if(n==0){
        n=1;
    }
    else{
        n=n*factorial(n-1);
    }
    return n;
}
