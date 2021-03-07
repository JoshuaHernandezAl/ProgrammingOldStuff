#include <iostream>

#include <graphics.h>

using namespace std;

int main( )
{
	initwindow( 640 , 480 , "WinBGIm" );
	
	
	
    
	outtextxy( 0 , 0 , "Hello WinBGIm!" );
    
	bgiout << "Hello WinBGIm-Stream!" ;
	outstreamxy( 0 , 15 ); 
	
    
    
    
    
	while( !kbhit() ); 
  
    
    
	closegraph( );
    
	return( 0 );
}
