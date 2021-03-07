#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

bool calculaEpsilon(double xi[3], double xs[3], int m, double eS);

//Gauss-Seidel para 3 incognitas, SIN fuerza bruta
int main(void){
    int i,j,intento=0,cifras;
    double x[3],xs[3],Valor,eS;
    double M[3][4] =

                    {   {7, -1, 2, 42},
                        {4, 5, -2, -14},
                        {3, 1, 4, 28}
                    };
                    //Solucion (4, -4, 5) Con diez digitos

/*
                    {   {4, -1, -1, 3},
                        {-2, 6, 1, 9},
                        {-1, 1, 7, -6}
                    };
                    //Solucion (1, 2, -1) Con diez digitos
*/
/*
                    {   {1, 2, -2, -15},
                        {1, -4, 1, 18},
                        {2, 1, -5, -21}
                    };
                    //Solucion (-1, -4, 3) Con diez digitos
*/

    for(i=0;i<3;i++){
        x[i] = 0.0;
        xs[i] = x[i];
    }

    for(i=0;i<3;i++){
        for(j=0;j<4;j++)
            if(M[i][j]<0&&j<3)
                cout<<M[i][j]<<"x"<<j<<"\t";
            else if(M[i][j]>=0&&j==0)
                cout<<M[i][j]<<"x"<<j<<"\t";
            else if(M[i][j]>=0&&j>0&&j<3)
                cout<<"+"<<M[i][j]<<"x"<<j<<"\t";
            else
                cout<<"= "<<M[i][j];
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<3;i++)
        cout<< "x"<<i<<" = " << x[i] << endl;
    cout<<endl<<endl;
    cout<<"Con cuantas cifras significativas de precision? ";
    cin>>cifras;
    eS = 0.5*pow(10,(3-cifras));

    //Se comienza sustituyendo los valores iniciales de las variables, en el sistema de ecuaciones,
    //y sustituyendo los nuevos valores calculados, con forme se van calculando

    for(;;){
        cout<<"Intento"<<(++intento)<<endl;
        for(i=0;i<3;i++){
                xs[i] = M[i][3];
                cout<<"x"<<i<<" = ( "<<M[0][3];
            for(j=0;j<3;j++){
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
        for(i=0;i<3;i++){
            Valor=0;
            for(j=0;j<3;j++){
                if(j<3-1)
                    cout<< xs[j]<<" * "<<M[i][j]<<" + ";
                else
                    cout<< xs[j]<<" * "<<M[i][j]<<" = ";
                Valor += xs[j]*M[i][j];
            }
            cout<<Valor<<" = "<<M[i][j]<< " ?"<<endl;
        }

        if(calculaEpsilon(x,xs,3,eS))
           break;

        for(int i=0;i<3;i++)
            x[i] = xs[i];

        cout<<endl<<endl<<endl;
    }

    //El proceso termina cuando se encuentran valores que cumplan con el sistema
    cout<<endl<<endl<<endl<<"Solucion:"<<endl;
    for(int i=0;i<3;i++)
        cout<< "x"<<i<<" = " << x[i] << endl;
    cout<<endl<<endl;


    return 0;
}

bool calculaEpsilon(double xi[3], double xs[3], int m, double eS){
    bool res=true;
    for(int i=0;i<m;i++)
        res = res && ((fabs(xs[i]-xi[i])/100) < eS);
    return res;
}
