#include <stdio.h>
#include <iostream>

#include <graphics.h>

using namespace std;

#define random(range) (rand() % (range))

#define ESC     0x1b                    /* Define the escape key        */
#define TRUE    1                       /* Define some handy constants  */
#define FALSE   0                       /* Define some handy constants  */
#define PI      3.14159                 /* Define a value for PI        */
#define ON      1                       /* Define some handy constants  */
#define OFF     0                       /* Define some handy constants  */

#define NFONTS 11

char *Fonts[NFONTS] = {
  "DefaultFont",   "TriplexFont",   "SmallFont",
  "SansSerifFont", "GothicFont", "ScriptFont", "SimplexFont", "TriplexScriptFont",
  "ComplexFont", "EuropeanFont", "BoldFont"
};

char *LineStyles[] = {
  "SolidLn",  "DottedLn",  "CenterLn",  "DashedLn",  "UserBitLn"
};

char *FillStyles[] = {
  "EmptyFill",  "SolidFill",      "LineFill",      "LtSlashFill",
  "SlashFill",  "BkSlashFill",    "LtBkSlashFill", "HatchFill",
  "XHatchFill", "InterleaveFill", "WideDotFill",   "CloseDotFill"
};

char *TextDirect[] = {
  "HorizDir",  "VertDir"
};

char *HorizJust[] = {
  "LeftText",   "CenterText",   "RightText"
};

char *VertJust[] = {
  "BottomText",  "CenterText",  "TopText"
};

struct PTS {
  int x, y;
};      /* Structure to hold vertex points      */

int    GraphDriver;             /* The Graphics device driver           */
int    GraphMode;               /* The Graphics mode value              */
double AspectRatio;             /* Aspect ratio of a pixel on the screen*/
int    MaxX, MaxY;              /* The maximum resolution of the screen */
int    MaxColors;               /* The maximum # of colors available    */
int    ErrorCode;               /* Reports any graphics errors          */
struct palettetype palette;             /* Used to read palette info    */

void changetextstyle(int font, int direction, int charsize)
{
  int ErrorCode;

  graphresult();                        /* clear error code             */
  settextstyle(font, direction, charsize);
  ErrorCode = graphresult();            /* check result                 */
  if( ErrorCode != grOk ){              /* if error occured             */
    closegraph();
    printf(" Graphics System Error: %s\n", grapherrormsg( ErrorCode ) );
    exit( 1 );
  }
}

void DrawBorder(void)
{
  struct viewporttype vp;

  setcolor( MaxColors - 1 );            /* Set current color to white   */

  setlinestyle( SOLID_LINE, 0, NORM_WIDTH );

  getviewsettings( &vp );
  rectangle( 0, 0, vp.right-vp.left, vp.bottom-vp.top );

}

void MainWindow( char *header )
{
  int height;

  cleardevice();                        /* Clear graphics screen        */
  setcolor( MaxColors - 1 );            /* Set current color to white   */
  setviewport( 0, 0, MaxX, MaxY, 1 );   /* Open port to full screen     */

  height = textheight( "H" );           /* Get basic text height        */

  changetextstyle( DEFAULT_FONT, HORIZ_DIR, 1 );
  settextjustify( CENTER_TEXT, TOP_TEXT );
  outtextxy( MaxX/2, 2, header );
  setviewport( 0, height+4, MaxX, MaxY-(height+4), 1 );
  DrawBorder();
  setviewport( 1, height+5, MaxX-1, MaxY-(height+5), 1 );

}

void StatusLine( char *msg )
{
  int height;

  setviewport( 0, 0, MaxX, MaxY, 1 );   /* Open port to full screen     */
  setcolor( MaxColors - 1 );            /* Set current color to white   */

  changetextstyle( DEFAULT_FONT, HORIZ_DIR, 1 );
  settextjustify( CENTER_TEXT, TOP_TEXT );
  setlinestyle( SOLID_LINE, 0, NORM_WIDTH );
  setfillstyle( EMPTY_FILL, 0 );

  height = textheight( "H" );           /* Detemine current height      */
  bar( 0, MaxY-(height+4), MaxX, MaxY );
  rectangle( 0, MaxY-(height+4), MaxX, MaxY );
  outtextxy( MaxX/2, MaxY-(height+2), msg );
  setviewport( 1, height+5, MaxX-1, MaxY-(height+5), 1 );

}

void Pause(void)
{
  static char msg[] = "Esc aborts or press a key...";
  int c;

  StatusLine( msg );                    /* Put msg at bottom of screen  */

  c = getch();                          /* Read a character from kbd    */

  if( ESC == c ){                       /* Does user wish to leave?     */
    closegraph();                       /* Change to text mode          */
    exit( 1 );                          /* Return to OS                 */
  }

  if( 0 == c ){                         /* Did use hit a non-ASCII key? */
    c = getch();                        /* Read scan code for keyboard  */
  }

  cleardevice();                        /* Clear the screen             */

}

void PutImageDemo(void)
{
  static int r      = 20;
  static int StartX = 100;
  static int StartY = 50;

  struct viewporttype vp;
  int PauseTime, x, y, ulx, uly, lrx, lry, size, i, width, height, step;
  void *Saucer;

  MainWindow("GetImage / PutImage Demonstration");
  getviewsettings( &vp );

  /* Draw Saucer */
  setfillstyle( SOLID_FILL, getmaxcolor() );
  fillellipse(StartX, StartY, r, (r/3)+2);
  ellipse(StartX, StartY-4, 190, 357, r, r/3);

  line(StartX+7, StartY-6, StartX+10, StartY-12);
  circle(StartX+10, StartY-12, 2);
  line(StartX-7, StartY-6, StartX-10, StartY-12);
  circle(StartX-10, StartY-12, 2);


  /* Read saucer image */
  ulx = StartX-(r+1);
  uly = StartY-14;
  lrx = StartX+(r+1);
  lry = StartY+(r/3)+3;
  width = lrx - ulx + 1;
  height = lry - uly + 1;
  size = 0;
  size = imagesize(ulx, uly, lrx, lry);
  Saucer = malloc( size );
  getimage(ulx, uly, lrx, lry, Saucer);
  putimage(ulx, uly, Saucer, XOR_PUT);

/* Plot some "stars"  */
  for ( i=0 ; i<1000; ++i )
    putpixel(random(MaxX), random(MaxY), random( MaxColors-1 )+1);
  x = MaxX / 2;
  y = MaxY / 2;
  PauseTime = 70;

  /* until a key is hit */
  while ( !kbhit() ) {

    /* Draw the Saucer */
    putimage(x, y, Saucer, XOR_PUT);                 /*  draw image  */
    delay(PauseTime);
    putimage(x, y, Saucer, XOR_PUT);                 /* erase image  */

    /* Move Saucer */

    step = random( 2*r );
    if ((step/2) % 2 != 0 )
      step = -1 * step;
    x = x + step;
    step = random( r );
    if ((step/2) % 2 != 0 )
      step = -1 * step;
    y = y + step;

    if (vp.left + x + width - 1 > vp.right)
      x = vp.right-vp.left-width + 1;
    else
      if (x < 0)
	x = 0;
    if (vp.top + y + height - 1 > vp.bottom)
      y = vp.bottom-vp.top-height + 1;
    else
      if (y < 0)
	y = 0;
  }
  free( Saucer );
  Pause();
}

int main( )
{   int mradius;
	initwindow( 800 , 600 , "Aprendiendo Gráficos en DEV C++" );
//	outtextxy(100,50,"Gráficos con Dev");
    MaxColors = getmaxcolor() + 1;
    MaxX = getmaxx();
    MaxY = getmaxy(); 
    mradius = MaxY / 10;
     
	
                            /* Maximum radius allowed       */

    MainWindow( "Circle Demonstration" );
  StatusLine( "ESC Aborts - Press a Key to stop" );

                   /* Determine the maximum radius */
                   
  PutImageDemo();
/*
  while( !kbhit() ){                    
    setcolor( random( MaxColors - 1 ) + 1 );    
    circle( random(MaxX), random(MaxY), random(mradius) );
  }  */

  Pause();   
	
/*	
	
    
	outtextxy( 0 ,0 , "Hello WinBGIm!" );
    
	bgiout << "Hello WinBGIm-Stream!" ;
	
	circle(100,100,50);
	
	outstreamxy( 0 , 15 ); 
	
	
	printf( "Hello Console!\n" );

	cout << "Hello Console-Stream!\n" ;
	
    
    
    
    
	while( !kbhit() ); 
  
*/    
    getch();
	closegraph( );
    
	return( 0 );
}
