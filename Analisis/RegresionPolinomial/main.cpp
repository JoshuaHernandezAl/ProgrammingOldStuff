#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

using namespace std;

void regresionP(int puntos);
int main()
{
    int puntos;
    cout<<"Ingresa el numero de puntos (x,y) que se aproximaran por el metodo: "<<endl;
    cin>>puntos;
    regresionP(puntos);
    return 0;
}
void regresionP(int puntos){
    int *x,*y;
    double *x2,*x3,*x4,*xy,*xxy;
    double sx=0,sy=0,sx2=0,sx3=0,sx4=0,sxy=0,sxxy=0;
    x=new int[puntos];
    y=new int[puntos];
    x2=new double[puntos];
    x3=new double[puntos];
    x4=new double[puntos];
    xy=new double[puntos];
    xxy=new double[puntos];
    cout<<"X: "<<endl;
    for(int i=0;i<puntos;i++){
        cout<<"x"<<i<<"= ";
        cin>>x[i];
    }
    cout<<"Y: "<<endl;
    for(int i=0;i<puntos;i++){
        cout<<"y"<<i<<"= ";
        cin>>y[i];
    }
    cout<<endl;
    cout<<"X^2: "<<endl;
    for(int i=0;i<puntos;i++){
        x2[i]=pow(x[i],2);
    }
    cout<<endl;
    cout<<"X^3: "<<endl;
    for(int i=0;i<puntos;i++){
        x3[i]=pow(x[i],3);
    }
    cout<<endl;
    cout<<"X^4: "<<endl;
    for(int i=0;i<puntos;i++){
        x4[i]=pow(x[i],4);
    }
    cout<<endl;
    cout<<"XY: "<<endl;
    for(int i=0;i<puntos;i++){
        xy[i]=x[i]*y[i];
    }
    cout<<endl;
    cout<<"(X^2)Y: "<<endl;
    for(int i=0;i<puntos;i++){
        xxy[i]=x2[i]*y[i];
    }
    cout<<endl;
    cout<<"x \t|y \t|x^2 \t|x^3 \t|x^4 \t|xy \t|(x^2)y"<<endl;
    for(int i=0;i<puntos;i++){
        cout<<x[i]<<"\t|"<<y[i]<<"\t|"<<x2[i]<<"\t|"<<x3[i]<<"\t|"<<x4[i]<<"\t|"<<
        xy[i]<<"\t|"<<xxy[i]<<endl;
        sx=sx+x[i];
        sy=sy+y[i];
        sx2=sx2+x2[i];
        sx3=sx3+x3[i];
        sx4=sx4+x4[i];
        sxy=sxy+xy[i];
        sxxy=sxxy+xxy[i];
    }
    cout<<endl;
    cout<<"Sumas: "<<endl;
    cout<<"x \t|y \t|x^2 \t|x^3 \t|x^4 \t|xy \t|(x^2)y"<<endl;
    cout<<sx<<"\t|"<<sy<<"\t|"<<sx2<<"\t|"<<sx3<<"\t|"<<sx4<<"\t|"<<
    sxy<<"\t|"<<sxxy<<endl;
    cout<<endl;
    double sist[3][4];
    sist[0][0]=puntos;
    sist[0][1]=sx;
    sist[0][2]=sx2;
    sist[0][3]=sy;
    sist[1][0]=sx;
    sist[1][1]=sx2;
    sist[1][2]=sx3;
    sist[1][3]=sxy;
    sist[2][0]=sx2;
    sist[2][1]=sx3;
    sist[2][2]=sx4;
    sist[2][3]=sxxy;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<sist[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;cout<<endl;cout<<endl;
    double Valor;
    int m, n;
    m=3;
    n=m+1;
    Valor = (sist[1][0]*-1)/sist[0][0];
    for(int j=0;j<4;j++)
        sist[1][j] = sist[1][j] + (Valor*sist[0][j]);

    Valor = (sist[2][0]*-1)/sist[0][0];
    for(int j=0;j<4;j++)
        sist[2][j] = sist[2][j] + (Valor*sist[0][j]);

/*------------------------------------------*/

    Valor = (sist[2][1]*-1)/sist[1][1];
    for(int j=0;j<4;j++)
        sist[2][j] = sist[2][j] + (Valor*sist[1][j]);

/*------------------------------------------------*/

    Valor = sist[0][0];
    for(int j=0;j<4;j++)
        sist[0][j] = sist[0][j] / Valor;

    Valor = sist[1][1];
    for(int j=0;j<4;j++)
        sist[1][j] = sist[1][j] / Valor;

    Valor = sist[2][2];
    for(int j=0;j<4;j++)
        sist[2][j] = sist[2][j] / Valor;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++)
            cout<<sist[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl<<endl;

/*-------------------------------------------*/
double a0=1,a1=1,a2=1;
    a2 = sist[2][3];
    a1 = sist[1][3] - sist[1][2]*a2;
    a0 = sist[0][3] - sist[0][1]*a1 - sist[0][2]*a2;

    cout<<"a0 = "<<a0<<endl
        <<"a1 = "<<a1<<endl
        <<"a2 = "<<a2<<endl;

    cout<<endl<<endl;

    cout<<"Ecuacion: "<<endl<<
    "y="<<a2<<"x^2 ";
    if(a1>=0)
        cout<<"+";
    cout<<a1<<"x ";
    if(a0>=0)
        cout<<"+";
    cout<<a0;
    cout<<endl<<endl;
};
