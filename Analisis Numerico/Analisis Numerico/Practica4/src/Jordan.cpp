#include "Jordan.h"

Jordan::Jordan(void){
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            R[i][j]= 0;
        }
    }
}
Jordan::~Jordan(void){}
void Jordan::pideleAlUsuarioTusDatos(void){
    cout<<"Introduce tu matriz"<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<"["<<i<<"]"<<"["<<j<<"] = ";
            cin>>R[i][j];
            cout<<endl;
        }
    }
}
void Jordan::muestraTusDatos(void){
    Jordan::calcula();
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<R[i][j]<<"\t\t";
        }
        cout<<"\n";
    }
    cout<<" x = "<<R[0][3]<<endl;
    cout<<" y = "<<R[1][3]<<endl;
    cout<<" z = "<<R[2][3]<<endl;
}
void Jordan::calcula(void){
    double r,q,o,t;
    r = R[0][0];
    q = R[1][0];
    o = R[2][0];
    for(int j=0; j<4; j++){
        R[0][j] = R[0][j] / r;
        if(q<=0)
            R[1][j] = R[0][j] + R[1][j];
        else
            R[1][j] = -R[0][j] + R[1][j];
        if(o<=0)
            R[2][j] = R[0][j] + R[2][j];
        else
            R[2][j] = -R[0][j] + R[2][j];
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
                S[i][j] = R[i][j];
        }
    }
    cout<<"ss = " <<S[0][1]<<endl;
    for(int j=0; j<4; j++){
        R[1][j] = R[1][j] / S[1][1];
        if(S[2][1]<=0)
            R[2][j] = R[1][j] * -S[2][1] + R[2][j];
        else
            R[2][j] = R[1][j] * S[2][1] + R[2][j];
        if(S[0][1]<=0)
            R[0][j] = R[1][j] * S[0][1] + R[0][j];
        else
            R[0][j] = R[1][j] * -S[0][1] + R[0][j];
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
                S[i][j] = R[i][j];
        }
    }
    for(int j=0; j<4; j++){
        R[2][j] = R[2][j] / S[2][2];
        if(S[1][2]<=0)
            R[1][j] = R[2][j] * S[1][2] + R[1][j];
        else
            R[1][j] = R[2][j] * -S[1][2] + R[1][j];
        if(S[0][2]<=0)
            R[0][j] = R[2][j] * S[0][2] + R[0][j];
        else
            R[0][j] = R[2][j] * -S[0][2] + R[0][j];


    }


}
