#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

using namespace std;
class Rapson
{
    private:
        float Xo, Xn, E, Er;

    public:
        Rapson();
        void LeerDatos();
        void Operar ();
        void MostrarDatos();
};
class grafico{
      public:
              int maxx;
              int maxy;
              float x,y;
              int xc, yc;              
              grafico(void){
                      maxx = 0;
                      maxy =0;
                      }
                      void grafica(void);
};
Rapson::Rapson(){
    Xo = 0.0;
    Xn = 0.0;
    E = 0.0;
    Er =0.0;
}

void Rapson::LeerDatos(){
    cout<<"Dame tu Xo:"<<endl;
    cin>>Xo;
    cout<<"Dame tu Error:"<<endl;
    cin>>E;
}
void Rapson::Operar(){
    do{
        Xn = ((Xo) - ((pow(Xo,2)- (7))/(2*Xo)));
        Er = (Xn-Xo)/Xn;
        if (Er<0){
            Er= Er*-1;
}
       Xo= Xn;


    }
 while (Er>E);
}

void Rapson::MostrarDatos(){
    cout<<"Este es tu resultado"<<Xn;
}


void grafico::grafica(){   
  	     xc=300;
         yc=280;
	  	for(x=-15;x<=600;x=x+0.01){
	  		y=(pow(x,2)-7);
	  		
	  		putpixel(50*x+xc,yc-20*y,GREEN);
		  }
	  	setbkcolor(BLUE);   
        setcolor(GREEN); 
		  line(50,280,600,280);
		  line(300,50,300,500);
		  setcolor(WHITE);
		  outtextxy(400,100,"Funcion y= x^2 - 7");
		  setcolor(WHITE);
		  outtextxy(310,50,"y");
		  outtextxy(600,250,"X");
    } 
int main( )
{
	
	Rapson R1;
    R1.LeerDatos();
    R1.Operar();
    R1.MostrarDatos();
    initwindow(1400,1000,"Win Bgim");
    grafico uno;
    uno.grafica();
    delay(2000);
    getch();
    closegraph( );
	return( 0 );
}
