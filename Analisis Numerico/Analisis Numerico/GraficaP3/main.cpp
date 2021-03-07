
#include <iostream>
#include <graphics.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

using namespace std;

class grafico{

public:
	int x,y;
	grafico(){
	x=0;
	y=0;
	}
	void grafica();
};

void grafico::grafica(){
     for(x=-300;x<300;x++){
     y=(pow(x,2)-7)*-1;
     putpixel(x+300,y+250,YELLOW);}
     setcolor(BLUE);
     line(0,250,600,250);
     line(300,0,300,500);
     setcolor(RED);
     outtextxy(20,4,"Funcion x^2-7");  
     outtextxy(20,50,"La raiz es = 2.64");
     setcolor(WHITE);
     outtextxy(310,4,"y");
     outtextxy(580,260,"x");
}

                                                                                                                              

int main(){
    
       initwindow(600,500,"WinBigm");
        grafico uno;
        uno.grafica();
        delay(2000);
        getch();  
        closegraph();
    
	return 0;
}
