animacion: animacion.cpp Gusano.o gfx.c
	gcc gfx.c animacion.cpp Gusano.o -o animacion -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lm
animacion.o: animacion.cpp Gusano.o gfx.o
	g++ animacion.cpp -c
Gusano.o: Gusano.cpp gfx.o Gusano.h
	g++ Gusano.cpp -c
gfx.o: gfx.c gfx.h
	gcc gfx.c -c -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lm