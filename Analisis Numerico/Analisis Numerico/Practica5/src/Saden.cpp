#include "Saden.h"

Saden::Saden(void){
    for(int i= 0; i<3; i++){
        for(int j=0; j<3; j++){
            A[i][j] = 0;
        }
    }
}
Saden::~Saden(void){}
void Saden::pideleAlUsuarioTusDatos(void){
    cout<<"Introduce tu sistema de ecuaciones"<<endl;
    for(int i= 0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<"["<<i<<"]["<<j<<"] =";
            cin>>A[i][j];
        }
    }
    Saden::calcula();

}
void Saden::muestraTusDatos(void){

}
void Saden::calcula(void){
    for(int i= 0; i<3; i++){
        for(int j=0; j<3; j++){
            if(fabs(A[0][0]) > fabs(A[i][j+1]) + fabs(A[i][j+2]))

        }
    }

}
