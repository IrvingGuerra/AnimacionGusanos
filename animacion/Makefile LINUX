animacion: animacion.o Gusano.o gfx.o
	g++ gfx.o animacion.o Gusano.o -o animacion -lX11 -lm
animacion.o: animacion.cpp Gusano.o gfx.o
	g++ animacion.cpp -c
Gusano.o: Gusano.cpp gfx.o Gusano.h
	g++ Gusano.cpp -c
gfx.o: gfx.c gfx.h
	gcc gfx.c -c 