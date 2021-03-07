#include <iostream>
#include <math.h>
using namespace std;
class matrix
{
	private:
		int f;
		double zala[100][100];
		double mimo[100][100];
		double res[100];
		double dd[100];
		double xx[100];
		double a,b,c,d,e;
	public:
		matrix()
		{
			a,b,c=0;
		}
		
	int paro()
	{
		return(f);
	}
	void solicitud()
	{
		cout<<"Cual es el tamaño de tu matriz nxn?"<<endl;
		cin>>f;
	}
	void llenado ()
      {
           for (int i=0; i<=f-1; i++)
               for (int j=0; j<=f-1; j++)
               {
               	cout<<"Ingresa el digito ("<<i+1<<","<<j+1<<")"<<endl;
               		double n;
               		cin>>n;
                   zala [i][j]=n;
                   
               }
               }
               
    void llenadoR ()
      {
           for (int i=0; i<=f-1; i++)
           {
               	cout<<"Ingresa el resultado de la fila "<<i+1<<endl;
               		double n;
               		cin>>n;
                    res[i]=n;
           }
               }
               
 void imprimir ()
       {
            for(int i=0; i<=f-1; i++)
            {
            for (int j=0; j<=f-1; j++)
            {
                    cout<<"   "<<zala[i][j];
                    
                    }
                    cout<<endl;
                    }
        }
        
	
	void copia()
	{
	    for (int i=0; i<=f-1; i++)
               for (int j=0; j<=f-1; j++)
               {
                   mimo [j][i]=zala[i][j];
	            }
	            
	}
    
    void impcopia()
    {

       
            for(int i=0; i<=f-1; i++)
            {
            for (int j=0; j<=f-1; j++)
            {
                    cout<<"   "<<mimo[i][j];
                    
                    }
                    cout<<endl;
                    }
        
    }
    
    
    void matd()
    {
    	dd[0]=res[0]/zala[0][0];
    	dd[1]=(res[1]-(zala[1][0]*dd[0]))/zala[1][1];
    	dd[2]=(res[2]-(zala[2][0]*dd[0])-(zala[2][1]*dd[1]))/zala[2][2];
    	for(int i=0; i<=2; i++)
    	{
    		cout<<"D"<<i<<"= "<<dd[i]<<endl;
		}
	}
		
		void afectazala()
		{
			zala[0][0]=sqrt(zala[0][0]);
			zala[1][0]=(zala[1][0]/zala[0][0]);
			zala[1][1]=sqrt(zala[1][1]-pow(zala[1][0],2));
			zala[2][0]=(zala[2][0]/zala[0][0]);
			zala[2][1]=((zala[2][1]-(zala[1][0]*zala[2][0]))/zala[1][1]);
			zala[2][2]=sqrt(zala[2][2]-pow(zala[2][0],2)-pow(zala[2][1],2));
			zala[0][1]=zala[0][2]=zala[1][2]=0;	
	}
	
	void ultres()
	{
		xx[2]=dd[2]/mimo[2][2];
		xx[1]=(dd[1]-(mimo[1][2]*xx[2]))/mimo[1][1];
		xx[0]=(dd[0]-(mimo[0][1]*xx[1])-(mimo[0][2]*xx[2]))/mimo[0][0];
		
		for(int i=0; i<=2; i++)
    	{
    		cout<<"X"<<i<<"= "<<xx[i]<<endl;
		}
	}
	
	};

main()
{
    matrix c;
	int a=0;
	int b=0;
	int s=0;
	int m=0;
	c.solicitud();
	s=c.paro();
	s=s-1;
	m=s-1;
	cout<<"----------------------------------------------------------"<<endl;
	cout<<"Ingresa solo los DATOS DE LA MATRIZ"<<endl;
	c.llenado();
		cout<<"----------------------------------------------------------"<<endl;
	cout<<"Ingresa solo los RESULTADOS DE CADA COLUMNA"<<endl;
	c.llenadoR();
		cout<<"----------------------------------------------------------"<<endl;
	cout<<"Tu matriz es: "<<endl;
	c.imprimir();
	c.afectazala();
		cout<<"----------------------------------------------------------"<<endl;
	cout<<"La matriz L es: "<<endl;
	c.imprimir();
		cout<<"----------------------------------------------------------"<<endl;
	c.copia();
	cout<<"La transpuesta es:"<<endl;
	c.impcopia();
		cout<<"----------------------------------------------------------"<<endl;
	cout<<"Los valores de D son: "<<endl;
	c.matd();
		cout<<"----------------------------------------------------------"<<endl;
	cout<<"Los resultados son: "<<endl;
	c.ultres();
	system("pause");
}

