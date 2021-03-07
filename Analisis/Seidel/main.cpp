#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

bool calculaEpsilon(double xi[4], double xs[4], int m, double eS);

//Gauss-Seidel para 4 incognitas, SIN fuerza bruta
int main(void){
    int i,j,intento=0,cifras;
    double x[4],xs[4],Valor,eS;
    double M[4][5] =

                    {   {4, 3, 2, -1, 1},
                        {3, -4, 3, -2, 7},
                        {1, 2, 5, 1, 4},
                        {1, -2, -4, -8, 2}
                    };
                    //Solucion (-0.0952229, -0.571404, 1.19046, -0.714284) Con 10 digitos

/*
                    {   {5, 4, 3, -1, -10},
                        {1, 4, 2, -3, -16},
                        {-1, 2, 5, 1, -4},
                        {-3, 3, -1, 4, 20}
                    };
                    //Solucion (-0.206179, 0.150746, -1.75999, 4.29231) Con 10 digitos
*/
/*
                    {
                        {4, 1, 2, -1, 16},
                        {1, 6, 3, -1, -10},
                        {-1, 2, 8, 1, -4},
                        {-3, 3, -1, 4, 20}
                    };
                    //Solucion (7.24923, -0.697385, -0.765559, 10.7686) Con 10 digitos
*/

    for(i=0;i<4;i++){
        x[i] = 0.0;
        xs[i] = x[i];
    }

    for(i=0;i<4;i++){
        for(j=0;j<5;j++)
            if(M[i][j]<0&&j<4)
                cout<<M[i][j]<<"x"<<j<<"\t";
            else if(M[i][j]>=0&&j==0)
                cout<<M[i][j]<<"x"<<j<<"\t";
            else if(M[i][j]>=0&&j>0&&j<4)
                cout<<"+"<<M[i][j]<<"x"<<j<<"\t";
            else
                cout<<"= "<<M[i][j];
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<4;i++)
        cout<< "x"<<i<<" = " << x[i] << endl;
    cout<<endl<<endl;
    cout<<"Con cuantas cifras significativas de precision? ";
    cin>>cifras;
    eS = 0.5*pow(10,(4-cifras));

    //Se comienza sustituyendo los valores iniciales de las variables, en el sistema de ecuaciones,
    //y sustituyendo los nuevos valores calculados, con forme se van calculando

    for(;;){
        cout<<"Intento"<<(++intento)<<endl;
        for(i=0;i<4;i++){
                xs[i] = M[i][4];
                cout<<"x"<<i<<" = ( "<<M[0][4];
            for(j=0;j<4;j++){
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
        for(i=0;i<4;i++){
            Valor=0;
            for(j=0;j<4;j++){
                if(j<4-1)
                    cout<< xs[j]<<" * "<<M[i][j]<<" + ";
                else
                    cout<< xs[j]<<" * "<<M[i][j]<<" = ";
                Valor += xs[j]*M[i][j];
            }
            cout<<Valor<<" = "<<M[i][j]<< " ?"<<endl;
        }

        if(calculaEpsilon(x,xs,4,eS))
           break;

        for(int i=0;i<4;i++)
            x[i] = xs[i];

        cout<<endl<<endl<<endl;
    }

    //El proceso termina cuando se encuentran valores que cumplan con el sistema
    cout<<endl<<endl<<endl<<"Solucion:"<<endl;
    for(int i=0;i<4;i++)
        cout<< "x"<<i<<" = " << x[i] << endl;
    cout<<endl<<endl;


    return 0;
}

bool calculaEpsilon(double xi[4], double xs[4], int m, double eS){
    bool res=true;
    for(int i=0;i<m;i++)
        res = res && ((fabs(xs[i]-xi[i])/100) < eS);
    return res;
}
