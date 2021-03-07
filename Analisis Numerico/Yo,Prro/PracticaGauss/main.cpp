#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;
class Gauss
{
    private:
        double M[4][4];
        double N[4][4];


    public:
        Gauss(void);
        ~Gauss(void);
        void pideleAlUsuarioTusDatos(void);
        void muestraTusDatos(void);
        void calcula(void);
        void calculaDos(void);
};
Gauss::Gauss(void){
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            M[i][j]= 0;
        }
    }
}
Gauss::~Gauss(void){}
void Gauss::pideleAlUsuarioTusDatos(void){
    cout<<"Introduce tu matriz"<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<"["<<i<<"]"<<"["<<j<<"] = ";
            cin>>M[i][j];
            cout<<endl;
        }
    }

}
void Gauss::calculaDos(void){
    double r,q,o,t;
    r = M[0][0];
    q = M[1][0];
    o = M[2][0];
    for(int j=0; j<4; j++){
        M[0][j] = M[0][j] / r;
        if(q<=0)
            M[1][j] = M[0][j] + M[1][j];
        else
            M[1][j] = -M[0][j] + M[1][j];
        if(o<=0)
            M[2][j] = M[0][j] + M[2][j];
        else
            M[2][j] = -M[0][j] + M[2][j];
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
                N[i][j] = M[i][j];
        }
    }
    for(int j=0; j<4; j++){
        M[1][j] = M[1][j] / N[1][1];
        if(N[2][1]<=0)
            M[2][j] = M[1][j] * -N[2][1] + M[2][j];
        else
            M[2][j] = M[1][j] * N[2][1] + M[2][j];
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
                N[i][j] = M[i][j];
        }
    }
    for(int j=0; j<4; j++){
        M[2][j] = M[2][j] / N[2][2];
    }
}
void Gauss::muestraTusDatos(void){
    double x,y,z;
    Gauss::calculaDos();
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<M[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<endl;
    z = M[2][3];
    y = M[1][3] - z*M[1][2];
    x = M[0][3] - M[0][1]*y - M[0][2]*z;
    cout<<" z = "<<z<<endl;
    cout<<" y = "<<y<<endl;
    cout<<" x = "<<x<<endl;
}
int main()
{
   Gauss A;
    cout<<"Este programa calcula sistemas de ecuaciones por el metodo de Gauss\n"<<endl;
        A.pideleAlUsuarioTusDatos();
        A.muestraTusDatos();
    return 0;
}

