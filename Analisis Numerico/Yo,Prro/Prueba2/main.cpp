#include <iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

class PuntoFijo{
    private:
        float xo;
    public:
        PuntoFijo(void);
        PuntoFijo(float xo);
        ~PuntoFijo(void);
        void pideleAlUsuarioTusDatos(void);
        void muestraTusDatos(void);
};
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
    converge = fabs(exp(radian)-2);
    do{
        if(converge<1){
            raiz = exp(radian)-(2*radian);
            errorRelativo = fabs((raiz - radian));
            radian = raiz;
        }
        else{
            cout<<"La aproximacion no converge"<<endl;
        }

    }while(errorRelativo >= 0.01);

    cout<<"La raiz es = "<<raiz<<endl;
}

int main()
{
    int op;
    PuntoFijo B;
    do{
    cout<<"Este programa calcula lo siguiente: \n"<<endl;
    cout<<"1) Una raiz de (e^x)-3x por el metodo Punto Fijo\n"<<endl;
    cout<<"2) Salir\n"<<endl;
    cout<<"Cual es tu opcion?\n"<<endl;
    cin>>op;

    switch(op){
    case 1:
        B.pideleAlUsuarioTusDatos();
        B.muestraTusDatos();
        break;
    case 2:
        cout<<"Hasta pronto"<<endl;
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;  }
    system("pause");
    system("cls");
    }while(op!=2);
    return 0;
}
