#include<iostream>
#include<stdio.h>
#include<cstdlib>

using namespace std;
class LU{
	private:
	 
	 
	  float A[25][25], B[25], X[25], L[25][25], Y[25], U[25][25],sum=0;
	  int i=0,j=0,k=0,n=0;
	 public:
	 	
	
	 	void OrdenMatriz();
	 	void Comprobacion();
		void InserteMatrices();	
		void op();	 
		void imprimir();
	
};

void LU::OrdenMatriz(){

system("color C");
cout <<endl;
cout <<endl;
cout << "Ingresa el orden de la matriz: ";
cin >> n;
}

void LU::Comprobacion(){

//Comprobacion de ingreso de un valor correcto para el orden de la matriz
if(n<=1){
    std::cout << std::endl;
    
    std::cout << "No ha ingresado un valor correcto. Cerrando el programa...";
    std::cout << std::endl;
    
} else {
    
    std::cout << "La matriz es de " << n << "x" << n <<".";
    std::cout << std::endl << std::endl;
}
}
    
void LU::InserteMatrices(){

	//Obtencion de los elementos de la matriz A de coeficientes
    cout<<"Ingrese los coeficientes de la matriz A de coeficientes: ";
    cout << endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout << "Ingrese el elemento A["<<i+1<<"]["<<j+1<<"]: ";
            cin >> A[i][j];
        cout<<endl;
        }
    }
    cout << endl;

    //Obtencion de los elementos de la matriz B
    cout << "Ingrese la matriz B:" << std::endl;
    for(i=0;i<n;i++){
        cout << "Ingrese el elemento B["<<i+1<<"]: ";
        cin >> B[i];
    }
}
  
  void LU::op(){
  
    //Descomposicion LU

    //Llenado de ceros y unos en posiciones conocidas
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            if(i>j){
              U[i][j]=0;    //Ceros debajo de la diagonal para la matriz U
            }
            else if(i==j){
              L[i][j]=1;    //Unos en la diagonal de L
            } else{
              L[i][j]=0;    //Ceros encima de la diagonal para la matriz L
            }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            sum=0;
            if(i<=j){               //Es decir, solo se llenan los elementos de la diagonal y encima de ella para U
                for(k=0;k<n;k++){
                    if(k!=i){
                        sum=sum+L[i][k]*U[k][j];
                    }else {
                        U[i][j]=A[i][j]-sum;               //Llenado de elementos restantes de U
                    }
                }
            } else{                 //Es decir, solo se llenan los elementos debajo de la diagonal para L
                for(k=0;k<n;k++){
                    if(k!=j){
                        sum=sum+L[i][k]*U[k][j];
                    }else {
                        L[i][j]=(A[i][j]-sum)/U[j][j];      //Llenado de elementos restantes de L
                    }
                }
            }
        }
    }
}
        
void LU::imprimir(){

		printf("\n\n L =");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)

                        printf ("%10.2f",L[i][j]);
            printf("\n    ");
    }

        printf("\n\n U =");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
                         printf ("%10.2f",U[i][j]);
            printf("\n    ");
    }

    Y[0]=B[0]/L[0][0];
    for(i=1;i<n;i++)
    {
        sum=0;
        for(j=0;j<i;j++)
        {
            sum=sum+Y[j]*L[i][j];

        }
        Y[i]=B[i]-sum;
    }
    printf("\n\n Y =");
    for(i=0;i<n;i++)
    {
                printf ("%10.2f",Y[i]);
            printf("\n    ");
    }

    X[n-1]=Y[n-1]/U[n-1][n-1];
    for(i=n-2;i>=0;i--){
        sum=0;
        for(j=n-1;j>i;j--)
            sum=sum+X[j]*U[i][j];
        X[i]=(Y[i]-sum)/U[i][i];
    }

    printf("\nLa solucion es :\n");
    for(i=0;i<n;i++)
        printf("\n x[%d] = %.2f ",i+1,X[i]);
    printf("\n\n");
}
int main(){
	
	LU A;
	A.OrdenMatriz();
	A.Comprobacion();
	A.InserteMatrices();
	A.op();
	A.imprimir();
	return 0;
}
