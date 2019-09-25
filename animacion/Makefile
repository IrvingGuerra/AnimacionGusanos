animacion: animacion.cpp Gusano.o gfx.o
	g++ -std=c++11 gfx.o animacion.cpp Gusano.o -o animacion -lpthread -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lm
Gusano.o: Gusano.cpp gfx.o Gusano.h
	g++ Gusano.cpp -c
gfx.o: gfx.c gfx.h
	gcc gfx.c -c -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lm