#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

bool calculaEpsilon(double xi[2], double xs[2], int m, double eS);

//Gauss-Seidel para 2 incognitas, SIN fuerza bruta
int main(void){
    int i,j,intento=0,cifras;
    double x[2],xs[2],Valor,eS;
    double M[2][3] =

                    {   {16, 3, 11},
                        {7, -11, 13}
                    };
                    //Solucion (0.812182, -0.664975) Con 10 digitos

/*
                    {   {15, 10, -5},
                        {8, -10, 28}
                    };
                    //Solucion (1, -2) Con 10 digitos
*/
/*
                    {   {2, 1, 9},
                        {-2, -3, 11}
                    };
                    //Solucion (9.5, -10) Con 10 digitos
*/

    for(i=0;i<2;i++){
        x[i] = 0.0;
        xs[i] = x[i];
    }

    for(i=0;i<2;i++){
        for(j=0;j<3;j++)
            if(M[i][j]<0&&j<2)
                cout<<M[i][j]<<"x"<<j<<"\t";
            else if(M[i][j]>=0&&j==0)
                cout<<M[i][j]<<"x"<<j<<"\t";
            else if(M[i][j]>=0&&j>0&&j<2)
                cout<<"+"<<M[i][j]<<"x"<<j<<"\t";
            else
                cout<<"= "<<M[i][j];
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<2;i++)
        cout<< "x"<<i<<" = " << x[i] << endl;
    cout<<endl<<endl;
    cout<<"Con cuantas cifras significativas de precision? ";
    cin>>cifras;
    eS = 0.5*pow(10,(2-cifras));

    //Se comienza sustituyendo los valores iniciales de las variables, en el sistema de ecuaciones,
    //y sustituyendo los nuevos valores calculados, con forme se van calculando

    for(;;){
        cout<<"Intento"<<(++intento)<<endl;
        for(i=0;i<2;i++){
                xs[i] = M[i][2];
                cout<<"x"<<i<<" = ( "<<M[0][2];
            for(j=0;j<2;j++){
                if(i!=j){
                    cout<<" - ("<<M[i][j]<<" * "<<xs[j]<<") ";
                    xs[i] -= M[i][j]*xs[j];
                }
            }
            cout<<") / "<<M[i][i]<<" = ";
            xs[i] /= M[i][i];
            cout<<xs[i]<<endl;
        }

        cout<<"Sistema"<<endl;
        for(i=0;i<2;i++){
            Valor=0;
            for(j=0;j<2;j++){
                if(j<2-1)
                    cout<< xs[j]<<" * "<<M[i][j]<<" + ";
                else
                    cout<< xs[j]<<" * "<<M[i][j]<<" = ";
                Valor += xs[j]*M[i][j];
            }
            cout<<Valor<<" = "<<M[i][j]<< " ?"<<endl;
        }

        if(calculaEpsilon(x,xs,2,eS))
           break;

        for(int i=0;i<2;i++)
            x[i] = xs[i];

        cout<<endl<<endl<<endl;
    }

    //El proceso termina cuando se encuentran valores que cumplan con el sistema
    cout<<endl<<endl<<endl<<"Solucion:"<<endl;
    for(int i=0;i<2;i++)
        cout<< "x"<<i<<" = " << x[i] << endl;
    cout<<endl<<endl;


    return 0;
}

bool calculaEpsilon(double xi[2], double xs[2], int m, double eS){
    bool res=true;
    for(int i=0;i<m;i++)
        res = res && ((fabs(xs[i]-xi[i])/100) < eS);
    return res;
}
