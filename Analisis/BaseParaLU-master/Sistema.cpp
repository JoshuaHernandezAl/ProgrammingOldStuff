#include "Sistema.h"


void Sistema::reservaMemoria(void){
    E = new Ecuacion[m];
    M = new double*[m];
    for(int i=0;i<m;i++)
        M[i] = new double[n];
}
void Sistema::liberaMemoria(void){
    if(m!=0){
        delete[] E;

        for(int i=0;i<m;i++)
            delete[] M[i];
        delete[] M;

        m = 0;
        n = 0;
        E = NULL;
        M = NULL;
        //cout<<"Memoria liberada..."<<endl;
    }
}
Sistema::Sistema(void){
    m = 0;
    n = 0;
    E = NULL;
    M = NULL;
}
Sistema::Sistema(int tam){
    if(tam>0){
        m = tam;
        n = m+1;
        reservaMemoria();
    }
    else{
        m = 0;
        n = 0;
        E = NULL;
        M = NULL;
    }
}
Sistema::~Sistema(void){
    liberaMemoria();
}
void Sistema::pideDatos(void){
    liberaMemoria();
    cout<<"Cuantas ecuaciones ingresaras? ";
    cin>>m;
    if(m>0)
        n = m+1;
    else
        m=0;
    reservaMemoria();
    pideSistema();
}
void Sistema::pideSistema(void){
    for(int i=0;i<m;i++){
        cout<<"Ingresa ecuacion "<<i+1<<endl<<endl;
        E[i].ingresaEcuacion();
        system("cls");
    }
    rellenaMatriz();
}
void Sistema::muestraSistema(void){
    for(int i=0;i<m;i++){
        E[i].muestraEcuacion();cout<<endl;
    }
    cout<<endl<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<M[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
void Sistema::rellenaMatriz(void){
    for(int i=0;i<m;i++){
        rellenaFila(i);
    }
}
void Sistema::rellenaFila(int fila){
    NodoP* aux = E[fila].ini;
    int j=0;
    while(aux!=NULL){
        M[fila][j] = aux->dameDato().dameCoeficiente();
        aux = aux->dameSig();
        j++;
    }
}
void Sistema::GaussSeidel(void){
    int i,j,intento=0,cifras;
    double* x;
    double* xs;
    double Valor,eS;
    x=new double[m];
    xs=new double[m];
    for(i=0;i<4;i++){
        x[i] = 0.0;
        xs[i] = x[i];
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            if(M[i][j]<0&&j<m)
                cout<<M[i][j]<<"x"<<j<<"\t";
            else if(M[i][j]>=0&&j==0)
                cout<<M[i][j]<<"x"<<j<<"\t";
            else if(M[i][j]>=0&&j>0&&j<m)
                cout<<"+"<<M[i][j]<<"x"<<j<<"\t";
            else
                cout<<"= "<<M[i][j];
        cout<<endl;
    }
    cout<<endl;

    for(int i=0;i<m;i++)
        cout<< "x"<<i<<" = " << x[i] << endl;
    cout<<endl<<endl;
    cout<<"Con cuantas cifras significativas de precision? ";
    cin>>cifras;
    eS = 0.5*pow(10,(m-cifras));


     for(;;){
        cout<<"Intento"<<(++intento)<<endl;
        for(i=0;i<m;i++){
                xs[i] = M[i][m];
                cout<<"x"<<i<<" = ( "<<M[0][m];
            for(j=0;j<m;j++){
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
        for(i=0;i<m;i++){
            Valor=0;
            for(j=0;j<m;j++){
                if(j<m-1)
                    cout<< xs[j]<<" * "<<M[i][j]<<" + ";
                else
                    cout<< xs[j]<<" * "<<M[i][j]<<" = ";
                Valor += xs[j]*M[i][j];
            }
            cout<<Valor<<" = "<<M[i][j]<< " ?"<<endl;
        }
        bool res=true;
    for(int i=0;i<m;i++)
        res = res && ((fabs(xs[i]-x[i])/100) < eS);

        if(res)
           break;

        for(int i=0;i<m;i++)
            x[i] = xs[i];

        cout<<endl<<endl<<endl;
    }


    cout<<endl<<endl<<endl<<"Solucion:"<<endl;
    for(int i=0;i<m;i++)
        cout<< "x"<<i<<" = " << x[i] << endl;
    cout<<endl<<endl;
    delete x;
    delete xs;

}
void Sistema::Gauss(void){
    double Valor;
    string* incognita;
    int cont;
    double* X;
    X = new double[m];
        for(int i=0;i<m;i++)
            X[i] = 0;
    incognita = new string[m];
        NodoP* aux = E[0].ini;
        cont=0;
        while(aux!=NULL&&aux->dameSig()!=NULL){
            incognita[cont] = aux->dameDato().dameNombre();
            aux = aux->dameSig();
            cont++;
        }
    cout<<"Matriz: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<M[i][j]<<"\t\t";
        cout<<endl;
    }
    cout<<endl;
    cout<<"Triangulo inferior: "<<endl;
    for(int a=0;a<m-1;a++){
        for(int w=a+1;w<m;w++){
            Valor = (M[w][a]*-1)/M[a][a];

            for(int j=0;j<n;j++)
                M[w][j] = M[w][j] + (Valor*M[a][j]);
        }
        cout<<endl<<endl;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<M[i][j]<<"\t\t";
        cout<<endl;
    }
    cout<<endl;
    cout<<"1's"<<endl;
    for(int b=0;b<m;b++){
        Valor = M[b][b];
        for(int j=0;j<n;j++)
            M[b][j] = M[b][j] / Valor;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<M[i][j]<<"\t\t";
        cout<<endl;
    }
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=i+1;j--){
            M[i][m] = M[i][m] - M[i][j]*M[j][m];
        }
    }

    cout<<endl;
    for (int i=0;i<m;i++){
        X[i]=M[i][m];
    }
    for(int i=0;i<m;i++){
            cout << incognita[i]<<" = "<<X[i]<<endl;
        }
        printf("\n\n");

    delete[] X;

}
void Sistema::GaussJordan(void){
    double Valor;
    string* incognita;
    int cont;
    double* X;
    X = new double[m];
        for(int i=0;i<m;i++)
            X[i] = 0;
    incognita = new string[m];
        NodoP* aux = E[0].ini;
        cont=0;
        while(aux!=NULL&&aux->dameSig()!=NULL){
            incognita[cont] = aux->dameDato().dameNombre();
            aux = aux->dameSig();
            cont++;
        }
    cout<<"Matriz: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<M[i][j]<<"\t\t";
        cout<<endl;
    }
    cout<<endl;
    cout<<"Triangulo inferior: "<<endl;
    for(int a=0;a<m-1;a++){
        for(int w=a+1;w<m;w++){
            Valor = (M[w][a]*-1)/M[a][a];

            for(int j=0;j<n;j++)
                M[w][j] = M[w][j] + (Valor*M[a][j]);
        }
        cout<<endl<<endl;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<M[i][j]<<"\t\t";
        cout<<endl;
    }
    cout<<endl;
    cout<<"1's"<<endl;
    for(int b=0;b<m;b++){
        Valor = M[b][b];
        for(int j=0;j<n;j++)
            M[b][j] = M[b][j] / Valor;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<M[i][j]<<"\t\t";
        cout<<endl;
    }
    cout<<endl;
    cout<<"Triangulo Superior:"<<endl;
    for(int a=m-1;a>0;a--){
        for(int w=a-1;w>=0;w--){
            Valor=(M[w][a]*-1)/M[a][a];
            for(int j=0;j<n;j++){
                M[w][j]=M[w][j]+(Valor*M[a][j]);
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<M[i][j]<<"\t\t";
        cout<<endl;
    }
    cout<<endl;
    for (int i=0;i<m;i++){
        X[i]=M[i][m];
    }
    for(int i=0;i<m;i++){
            cout << incognita[i]<<" = "<<X[i]<<endl;
        }
        printf("\n\n");

    delete[] X;
}
void Sistema::LU(void){
    double Valor;
    double** A;
    double** L;
    double** U;
    double* X;
    double* Y;
    double* B;
    double** auxY;
    double** auxX;
    string* incognita;
    int cont;
    if(m!=0){
        printf("Sistema\n");
        muestraSistema();

        A = new double*[m];
        for(int i=0;i<m;i++)
            A[i] = new double[m];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                A[i][j] = 0;

        L = new double*[m];
        for(int i=0;i<m;i++)
            L[i] = new double[m];
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                if(i==j)
                    L[i][j] = 1;
                else
                    L[i][j] = 0;

        U = new double*[m];
        for(int i=0;i<m;i++)
            U[i] = new double[m];
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                U[i][j] = M[i][j];

        X = new double[m];
        for(int i=0;i<m;i++)
            X[i] = 0;
        Y = new double[m];
        for(int i=0;i<m;i++)
            Y[i] = 0;
        B = new double[m];
        for(int i=0;i<m;i++)
            B[i] = M[i][m];

        incognita = new string[m];
        NodoP* aux = E[0].ini;
        cont=0;
        while(aux!=NULL&&aux->dameSig()!=NULL){
            incognita[cont] = aux->dameDato().dameNombre();
            aux = aux->dameSig();
            cont++;
        }

        printf("L\n");
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++)
                printf("%lf\t",L[i][j]);
            printf("\n");
        }
        printf("\n\n");

        printf("U\n");
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++)
                printf("%lf\t",U[i][j]);
            printf("\n");
        }
        printf("\n\n");

        for(int i=0;i<m;i++)
            printf("B[%d] = %lf\n",i,B[i]);
        printf("\n\n");


        for(int h=0;h<m-1;h++){
            for(int k=h+1;k<m;k++){
                L[k][h] = U[k][h]/U[h][h];
                Valor = -1 * L[k][h];
                cout<<"(F"<<h<<" * "<<Valor<<") + F"<<k<<endl;
                for(int j=0;j<m;j++)
                    U[k][j] = U[k][j] + (Valor*U[h][j]);

                printf("L\n");
                for(int i=0;i<m;i++){
                    for(int j=0;j<m;j++)
                        printf("%lf\t",L[i][j]);
                    printf("\n");
                }
                printf("U\n");
                for(int i=0;i<m;i++){
                    for(int j=0;j<m;j++)
                        printf("%lf\t",U[i][j]);
                    printf("\n");
                }
                printf("\n\n");
            }
        }


        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                for(int k=0;k<m;k++)
                    A[i][j] += L[i][k]*U[k][j];

        printf("A = L*U\n");
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++)
                printf("%lf\t",A[i][j]);
            printf("\n");
        }
        printf("\n\n");

        //Se resuelve LY = B, para Y
        printf("De L*Y = B\n");
        /*
            YA!!
        */
        auxY=new double*[m];
        for(int i=0;i<m;i++)
            auxY[i] = new double[n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                auxY[i][j] = L[i][j];
            }
        }
        for(int i=0;i<m;i++){
            auxY[i][m]=B[i];
        }
        cout<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<auxY[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<"Impresion:"<<endl;
        for(int i=1;i<m;i++){
            double suma=0;
            for(int j=0;j<i;j++){
                suma+=auxY[i][j]*auxY[j][m];
            }
        auxY[i][m]=auxY[i][m]-suma;
        }

        cout<<endl;
        cout<<endl;
        for(int i=0;i<m;i++){
            Y[i]=auxY[i][m];
        }
        for(int i=0;i<m;i++)
            printf("Y[%d] = %lf\n",i,Y[i]);
        printf("\n\n");
        for(int i=0;i<m;i++)
            delete[] auxY[i];
        delete[] auxY;

        //Se resuelve UX = Y, para X
        printf("De U*X = Y, solucion al sistema:\n");
        /*
            YA!
        */
        auxX=new double*[m];
        for(int i=0;i<m;i++)
            auxX[i] = new double[n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                auxX[i][j] = 0;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                auxX[i][j] = U[i][j];
            }
        }
        for(int i=0;i<m;i++){
            auxX[i][m]=Y[i];
        }

    cout<<endl<<endl;

        double Valor;
        for(int b=0;b<m;b++){
        Valor = auxX[b][b];
        for(int j=0;j<n;j++)
            auxX[b][j] = auxX[b][j] / Valor;
    }
    for(int a=m-1;a>0;a--){
        for(int w=a-1;w>=0;w--){
            Valor=(auxX[w][a]*-1)/auxX[a][a];
            for(int j=0;j<n;j++){
                auxX[w][j]=auxX[w][j]+(Valor*auxX[a][j]);
            }
        }
    }
    for (int i=0;i<m;i++){
        X[i]=auxX[i][m];
    }
    cout<<endl;

        for(int i=0;i<m;i++){
            cout << incognita[i]<<" = ";
            printf("X[%d] = %lf\n",i,X[i]);
        }
        printf("\n\n");


        for(int i=0;i<m;i++)
            delete[] A[i];
        delete[] A;
        for(int i=0;i<m;i++)
            delete[] L[i];
        delete[] L;
        for(int i=0;i<m;i++)
            delete[] U[i];
        for(int i=0;i<m;i++)
            delete[] auxX[i];
        delete[] auxX;
        delete[] U;
        delete[] X;
        delete[] Y;
        delete[] B;
        delete[] incognita;
    }

}

