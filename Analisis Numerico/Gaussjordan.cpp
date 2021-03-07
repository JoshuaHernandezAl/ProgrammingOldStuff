
#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>

#define   SIZE   10

using namespace std;

int main()
{
	 float a[SIZE][SIZE], x[SIZE], ratio;
	 int i,j,k,n;

     /* Ajuste de precisión y escritura de valores de punto flotante en notación de punto fijo */
     cout<< setprecision(3)<< fixed;

	 /* entrada */
	 /* 1. Número de incógnitas */
	 cout<<"Ingresa numero de incognitas: ";
	 cin>>n;

	 /* 2. Número de Matrices */
	 cout<<"Ingresa datos de la  matriz: "<< endl;
	 for(i=1;i<=n;i++)
	 {
		  for(j=1;j<=n+1;j++)
		  {
			   cout<<"a["<< i<<"]"<< j<<"]= "<<"\t\t"; 
			   cin>>a[i][j];
		  }
		  cout<<"\n";
	 }
    /* Método de Gauss Jordan */
     for(i=1;i<=n;i++)
     {
          if(a[i][i] == 0.0)
          {
               cout<<"Error";
               exit(0);
          }
          for(j=1;j<=n;j++)
          {
               if(i!=j)
               {
                    ratio = a[j][i]/a[i][i];
                    for(k=1;k<=n+1;k++)
                    {
                        a[j][k] = a[j][k] - ratio*a[i][k];
                    }
               }
          }
     }
     /* Solucion */
     for(i=1;i<=n;i++)
     {
        x[i] = a[i][n+1]/a[i][i];
     }

	 cout<< endl<<"Solution: "<< endl;
	 for(i=1;i<=n;i++)
	 {
	  	cout<<"x["<< i<<"] = "<< x[i]<< endl;
	 }
	 
     system("pause");
	 return(0);
}
