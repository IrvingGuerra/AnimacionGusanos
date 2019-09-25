#include "gfx.h"
#include "Gusano.h"


#include <unistd.h>
#include <time.h>
#include <stdlib.h> 
#include <thread> 

#include <iostream>
using namespace std;

void gusanito(float x,float y, int tamano, int sentido, int direccion, int tipoMovimiento){
	Gusano a;
	a.inicializaGusano(sentido,x,y,tamano);

	while(1){
		int direccion = rand() % 8 + 1;
		a.mueveGusano(direccion,tipoMovimiento);
	}
}

int main(int argc, char const *argv[]){
		srand(time(NULL));

	if (atoi(argv[1]) < 1 || argv[1] == NULL){
		printf("Debe de ingresar un numero mayor a 0");
	}else{
		
		gfx_open(800, 600, "Gusanos Animados");		//Creamos la ventana
		gfx_clear_color(255,255,255); 				//Ponemos un fondo blanco
		gfx_clear();
		gfx_color(0,0,0); 							//Color Negro por default



		float randomX = rand() % 600 + 200;
		float randomY = rand() % 400 + 200;
		int tamano = 10;
		int sentido = rand() % 8 + 1;
		int direccion = rand() % 8 + 1;
		int tipoMovimiento = 1; // = rand() % 3 + 1; //Recto, serpenteo

		thread th1(gusanito, randomX, randomY, tamano, sentido,direccion,tipoMovimiento);

		randomX = rand() % 600 + 200;
		randomY = rand() % 400 + 200;
		tamano = 10;
		sentido = rand() % 8 + 1;
		direccion = rand() % 8 + 1;
		tipoMovimiento = 1; // = rand() % 3 + 1; //Recto, serpenteo

		thread th2(gusanito, randomX, randomY, tamano, sentido,direccion,tipoMovimiento);

		th1.join();
		th2.join();

	
		//Todo estara en un while infinito hasta presionar la letra q
		/*
		char c;
		while(1) {
			c = gfx_wait();
			if(c=='q') break;
		}*/
		

	}

	return 0;
}