#include <iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>


using namespace std;

class Biseccion
{
    private:
        float x0,xn;

    public:
        Biseccion(void);
        Biseccion(float x0, float xn);
        ~Biseccion(void);
        void pideleAlUsuarioTusDatos(void);
        void muestraTusDatos(void);


};
Biseccion::Biseccion(void){
    x0 = 0.0;
    xn = 0.0;
}

Biseccion::Biseccion(float x0, float xn){
    this->x0=x0;
    this->xn=xn;
}

Biseccion::~Biseccion(void){
}

void Biseccion::pideleAlUsuarioTusDatos(void){
    cout<<endl<<"Introduce el limite inferior"<<endl;
    cin>>x0;
    cout<<endl<<"Introduce el limite superior"<<endl;
    cin>>xn;
    
}

void Biseccion::muestraTusDatos(void){
    float xm,xm2,verificaInicial,verificaDos;
    xm=0.0;
    xm2=0.0;
    float errorRelativo=0;
    verificaInicial = (exp(-x0)-x0)*(exp(-xn)-xn);
    do{
        if(verificaInicial<0){
            xm = (x0 + xn) / 2;
            verificaDos = (exp(-x0)-x0)*(exp(-xm)-xm);
            if(verificaDos<0){
                xn = xm;
                xm2 = (x0 + xn) / 2;
            }
            else if(verificaDos==0){
                cout<<endl<<"La raiz es = "<<xm<<endl<<endl;
            }
            else if(verificaDos>0){
                x0 = xm;
                xm2 = (x0 + xn) / 2;
            }
            errorRelativo = fabs((xm2 - xm)/xm2);
        }
        else{
            cout<<endl<<"No se puede calcular una raiz en el intervalo dado"<<endl<<endl;
        }

    }while(errorRelativo >= 0.1);

    cout<<endl<<"La Raiz es = "<<xm2<<endl<<endl;
}
class Raiz
{
    private:
        int x0,xn;

    public:
        Raiz(void);
};
int main()
{
    Biseccion A;
    cout<<"Este programa obtiene la raiz de (e^-x)-x por el metodo Biseccion\n";
        A.pideleAlUsuarioTusDatos();
        A.muestraTusDatos();
    return 0;
}
