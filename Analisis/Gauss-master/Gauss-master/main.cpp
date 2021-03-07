#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Sistema.h"
using namespace std;
int main(void){
    Fraccion Valor, w, x, y, z;
    Fraccion M[4][5] =
                {   {Fraccion(1,1), Fraccion(3,1), Fraccion(1,1), Fraccion(3,1), Fraccion(14,1)},
                    {Fraccion(4,1), Fraccion(-2,1), Fraccion(-3,1), Fraccion(1,1), Fraccion(20,1)},
                    {Fraccion(2,1), Fraccion(1,1), Fraccion(-1,1), Fraccion(-1,1), Fraccion(9,1)},
                    {Fraccion(1,1), Fraccion(2,1), Fraccion(-1,1), Fraccion(-2,1), Fraccion(3,1)}
                };
/*
                {   {Fraccion(2,1), Fraccion(1,1), Fraccion(-1,1), Fraccion(2,1), Fraccion(5,1)},
                    {Fraccion(4,1), Fraccion(5,1), Fraccion(-3,1), Fraccion(6,1), Fraccion(9,1)},
                    {Fraccion(-2,1), Fraccion(5,1), Fraccion(-2,1), Fraccion(6,1), Fraccion(4,1)},
                    {Fraccion(4,1), Fraccion(11,1), Fraccion(-4,1), Fraccion(8,1), Fraccion(2,1)}
                };
*/
/*                {   {Fraccion(1,1), Fraccion(2,1), Fraccion(5,1), Fraccion(1,1), Fraccion(4,1)},
                    {Fraccion(3,1), Fraccion(-4,1), Fraccion(3,1), Fraccion(-2,1), Fraccion(7,1)},
                    {Fraccion(1,1), Fraccion(-2,1), Fraccion(-4,1), Fraccion(-1,1), Fraccion(2,1)},
                    {Fraccion(4,1), Fraccion(3,1), Fraccion(2,1), Fraccion(-1,1), Fraccion(1,1)}
                };
*/

    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++)
            cout<<M[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl<<endl;

//-----------------------------------------------------
    Valor = (M[1][0]*-1)/M[0][0];
    cout<<"(F0 * "<<Valor<<") + F1"<<endl;
    for(int j=0;j<5;j++)
        M[1][j] = M[1][j] + (Valor*M[0][j]);
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++)
            cout<<M[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl<<endl;

    Valor = (M[2][0]*-1)/M[0][0];
    cout<<"(F0 * "<<Valor<<") + F2"<<endl;
    for(int j=0;j<5;j++)
        M[2][j] = M[2][j] + (Valor*M[0][j]);
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++)
            cout<<M[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl<<endl;

    Valor = (M[3][0]*-1)/M[0][0];
    cout<<"(F0 * "<<Valor<<") + F3"<<endl;
    for(int j=0;j<5;j++)
        M[3][j] = M[3][j] + (Valor*M[0][j]);
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++)
            cout<<M[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl<<endl;

//---------------------------------------------

    Valor = (M[2][1]*-1)/M[1][1];
    cout<<"(F1 * "<<Valor<<") + F2"<<endl;
    for(int j=0;j<5;j++)
        M[2][j] = M[2][j] + (Valor*M[1][j]);
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++)
            cout<<M[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl<<endl;

    Valor = (M[3][1]*-1)/M[1][1];
    cout<<"(F1 * "<<Valor<<") + F3"<<endl;
    for(int j=0;j<5;j++)
        M[3][j] = M[3][j] + (Valor*M[1][j]);
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++)
            cout<<M[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl<<endl;

//-------------------------------------------------

    Valor = (M[3][2]*-1)/M[2][2];
    cout<<"(F2 * "<<Valor<<") + F3"<<endl;
    for(int j=0;j<5;j++)
        M[3][j] = M[3][j] + (Valor*M[2][j]);
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++)
            cout<<M[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl<<endl;

//------------------------------------------------

    Valor = M[0][0];
    for(int j=0;j<5;j++)
        M[0][j] = M[0][j] / Valor;

    Valor = M[1][1];
    for(int j=0;j<5;j++)
        M[1][j] = M[1][j] / Valor;

    Valor = M[2][2];
    for(int j=0;j<5;j++)
        M[2][j] = M[2][j] / Valor;

    Valor = M[3][3];
    for(int j=0;j<5;j++)
        M[3][j] = M[3][j] / Valor;

    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++)
            cout<<M[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl<<endl;

//-------------------------------------------

    z = M[3][4];
    y = M[2][4] - M[2][3]*z;
    x = M[1][4] - M[1][3]*z - M[1][2]*y;
    w = M[0][4] - M[0][3]*z - M[0][2]*y - M[0][1]*x;

    cout<<"w = "<<w<<endl
        <<"x = "<<x<<endl
        <<"y = "<<y<<endl
        <<"z = "<<z<<endl;

    cout<<endl<<endl;
    return 0;
}
