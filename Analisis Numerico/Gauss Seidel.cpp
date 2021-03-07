#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    cout.precision(4);
    cout.setf(ios::fixed);
    int n,i,j,k,flag=0,count=0;
    cout<<"\nIntroduzca el no. de ecuaciones\n";           
    cin>>n;                    //Entrada no. de ecuaciones
    double a[n][n+1];            //declarar una matriz 2d para almacenar los elementos de la matriz aumentada
    double x[n];                //declarar una matriz para almacenar los valores de las variables

    double eps,y;
    cout<<"\nIntroduzca los elementos de la matriz aumentada en cuanto a fila:\n";
    for (i=0;i<n;i++)
        for (j=0;j<=n;j++)
            cin>>a[i][j];
 // valores iniciales de las variables
    for (i=0;i<n;i++)
    
    for (i=0;i<n;i++)                    //Pivotización (parcial) para que las ecuaciones sean diagonalmente dominantes
        for (k=i+1;k<n;k++)
            if (abs(a[i][i])<abs(a[k][i]))
                for (j=0;j<=n;j++)
                {
                    double temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
                
    cout<<"Iteraciones"<<setw(10);
    for(i=0;i<n;i++)
      //  cout<<"x"<<i<<setw(18);
    cout<<"-------------------------";
    do                            //Realizar iteraciones para calcular x1,x2,...xn
    {
        cout<<"\n"<<count+1<<"."<<setw(16);
        for (i=0;i<n;i++)                //Bucle que calcula x1,x2,...xn
        {
            y=x[i];
            x[i]=a[i][n];
            for (j=0;j<n;j++)
            {
                if (j!=i)
                x[i]=x[i]-a[i][j]*x[j];
            }
            x[i]=x[i]/a[i][i];
            if (abs(x[i]-y)<=0.000001)            //Compare el valor  con el último valor

                flag++;
            cout<<x[i]<<setw(18);
        }
        cout<<"\n";
        count++;   
    }while(flag<n);                        //si los valores de todas las variables no difieren de sus valores previious con error más que eps entonces flag debe ser n y por lo tanto detener el bucle
   
    cout<<"\n La solucion es:\n";
    for (i=0;i<n;i++)
        cout<<"x"<<i<<" = "<<x[i]<<endl;       
        system("pause");
    return 0;
}
