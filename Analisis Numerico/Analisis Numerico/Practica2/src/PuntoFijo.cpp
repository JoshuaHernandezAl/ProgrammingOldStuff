#include "PuntoFijo.h"

PuntoFijo::PuntoFijo(void){
    xo = 0.0;
}
PuntoFijo::PuntoFijo(float xo){
    this->xo=xo;
}
PuntoFijo::~PuntoFijo(void){
}
void PuntoFijo::pideleAlUsuarioTusDatos(void){
    cout<<"Introduce el valor de tu aproximacion"<<endl;
    cin>>xo;
}
void PuntoFijo::muestraTusDatos(void){
    double errorRelativo;
    double radian,converge,raiz;
    radian = xo *(M_PI / 180);
    converge = fabs(-sin(radian) + 1/2);
    do{
        if(converge<1){
            raiz = cos(radian) + radian/2 + 1;
            errorRelativo = fabs((raiz - radian));
            radian = raiz;
        }
        else{
            cout<<"La aproximacion no converge"<<endl;
        }

    }while(errorRelativo >= 0.01);

    cout<<"La raiz es = "<<raiz<<endl;
}
