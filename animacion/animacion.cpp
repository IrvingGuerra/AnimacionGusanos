#include "gfx.h"
#include "Gusano.h"
#include <unistd.h>
#include <time.h>
#include <stdlib.h> 
#include <thread> 
#include <iostream>
using namespace std;
const int WindowsX = 1500;
const int WindowsY = 700;
void gusanito(float x,float y, int tamano, int sentido, int direccion, int tipoMovimiento){
	Gusano a;
	a.inicializaGusano(sentido,x,y,tamano);
	while(1){
		gfx_clear();
		int direccion = rand() % 8 + 1;
		a.mueveGusano(direccion,tipoMovimiento);
		gfx_flush();
	}
}
int main(int argc, char const *argv[]){
		srand(time(NULL));
	if (atoi(argv[1]) < 1 || argv[1] == NULL){
		printf("Debe de ingresar un numero mayor a 0");
	}else{
		gfx_open(WindowsX, WindowsY, "Gusanos Animados");
		gfx_clear_color(255,255,255); //Ponemos un fondo blanco
		gfx_clear();
		gfx_color(0,0,0); //Color Negro por default
		//Hacemos un array de Hilos
		int cantidad = atoi(argv[1]);
		thread myThreads[cantidad];
		float randomX;
		float randomY;
		int tamano;
		int sentido;
		int direccion;
		int tipoMovimiento;
		for (int i = 0; i < cantidad; i++){
			randomX = rand() % WindowsX + 1;
			randomY = rand() % WindowsY + 1;
			tamano = 20;
			sentido = rand() % 8 + 1;
			direccion = rand() % 8 + 1;
			tipoMovimiento = rand() % 2 + 1; //Recto, serpenteo
			myThreads[i] = std::thread(gusanito, randomX, randomY, tamano, sentido,direccion,tipoMovimiento);
		}
		for (int i = 0; i < cantidad; i++){
	        myThreads[i].join();
	    }
	}

	return 0;
}