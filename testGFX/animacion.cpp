#include "gfx.h"
#include <unistd.h>
using namespace std;
int main()
{
 int t;
 gfx_open(800, 600, "Ejemplo Micro Animacion GFX");
 gfx_color(0,200,100);
 for(t = 0; t < 100; t++){
 gfx_clear();
 gfx_line( t*1+80, t*2+40, t*2+40, t*3+80 );
 gfx_line(t*5+80, t*3+40, t*3+40, t*5+80);
 gfx_flush();
 usleep(41666); //24 por segundo
 }
 return 0;
}

//MAC

//gcc animacion.cpp gfx.c -o animacion -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lm