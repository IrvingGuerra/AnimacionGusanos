animacion: animacion.o Asteroide.o gfx.o
	g++ gfx.o animacion.o Asteroide.o -o animacion -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lm
animacion.o: animacion.cpp Asteroide.o gfx.o
	g++ -std=c++11 animacion.cpp -c -lpthread
Asteroide.o: Asteroide.cpp gfx.o Asteroide.h
	g++ Asteroide.cpp -c
gfx.o: gfx.c gfx.h
	gcc gfx.c -c -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lm
clean:
	rm *.o