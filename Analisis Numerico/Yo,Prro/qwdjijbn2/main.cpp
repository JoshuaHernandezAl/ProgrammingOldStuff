#include<graphics.h>
#include<windows.h>
 
#include<stdlib.h>
#include<math.h>
#include<conio.h>

using namespace std;

class grafico
   {
      public:
      int x, y;
      grafico()
         {
            x = 0;
            y = 0;
         }
            void grafica();
   };

void grafico::grafica()
     {
         for(x = 5;x < 725; x++)
         {
            y=235-sin(2*x*M_PI/360)*100;
            putpixel(x,y,GREEN);
         }

         setcolor(YELLOW);
         line(1,225,800,225);
         line(5,0,5,450);         
         setcolor(RED);
         outtextxy(15,4,"Funcion y=sin(x)");
                  setcolor(BLUE);
          outtextxy(2,2,"y");
           outtextxy(800,250,"x");                 
        
     }

int main(){
      initwindow(900,500,"WinBgim");
      grafico uno;
      uno.grafica();
      delay(2000);
      getch();
      closegraph();
      return 0;
   }


