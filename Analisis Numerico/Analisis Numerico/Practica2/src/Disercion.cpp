#include "Disercion.h"

Disercion::Disercion(void){
    x0 = 0.0;
    xn = 0.0;
}

Disercion::Disercion(float x0, float xn){
    this->x0=x0;
    this->xn=xn;
}

Disercion::~Disercion(void){
}

void Disercion::pideleAlUsuarioTusDatos(void){
    cout<<"Introduce el limite inferior"<<endl;
    cin>>x0;
    cout<<"Introduce el limite superior"<<endl;
    cin>>xn;
}

void Disercion::muestraTusDatos(void){
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
                cout<<"La raiz es = "<<xm<<endl;
            }
            else if(verificaDos>0){
                x0 = xm;
                xm2 = (x0 + xn) / 2;
            }
            errorRelativo = fabs((xm2 - xm)/xm2);
        }
        else{
            cout<<"No se puede calcular una raiz en el intervalo dado"<<endl;
        }

    }while(errorRelativo >= 0.1);

    cout<<"La Raiz es = "<<xm2<<endl;
}

