#include<graphics.h>
#include<windows.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

using namespace std;

class grafico
{ public: 
          int x,y;
          grafico ()
          {
                  x=0;
                  y=0;
          }
           void grafica();
};

void grafico::grafica(){
     for(x=60; x<600; x++){
               y=250+sin(2*x*M_PI/360)*200;
               putpixel(x,y,GREEN);
     }
     setcolor(YELLOW);
     line(10,250,600,250);
     line(20,10,20,450);
     setcolor(RED);
     outtextxy(5,4,"Funcion y=sin(x)");
     setcolor(BLUE);
     outtext(2,2,"y");
     outtextxy(600,250,"x");
     };
     
 int main()
 {
     initwindow(1400,1800,"WinBgim");
     grafico uno;
     uno.grafica();
     delay(2000);
     getch();
     closegraph();
     return 0;
     
}        
