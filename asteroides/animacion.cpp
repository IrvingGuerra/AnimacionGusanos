#include "gfx.h"
#include "Asteroide.h"
#include <unistd.h>
#include <time.h>
#include <stdlib.h> 
#include <thread> 
#include <iostream>
using namespace std;
const int WindowsX = 1500;
const int WindowsY = 700;

void asteroide(float x,float y, int size,int direccion, int eje){
	Asteroide a;
	a.inicializaAsteroide(x, y, size);
	//a.imprimeAsteroideColor();
	while(1){
		a.mueveAsteroide(direccion,eje);
		gfx_flush();
		//gfx_clear();
	}
}

int main(int argc, char const *argv[]){
		srand(time(NULL));
	if (atoi(argv[1]) < 1 || argv[1] == NULL){
		printf("Debe de ingresar un numero mayor a 0");
	}else{
		gfx_open(WindowsX, WindowsY, "Asteroides Animados");
        gfx_clear_color(0,0,0); //FONDO NEGRO
		gfx_clear();
		gfx_color(0,200,100); //LINEA VERDE

		//Hacemos un array de Hilos
		int cantidad = atoi(argv[1]);
		thread myThreads[cantidad];
		float randomX; //Posicion random X
		float randomY; //Posicion random Y
		int size;
		int direccion;
		int eje; 

		for (int i = 0; i < cantidad; i++){
			randomX = rand() % WindowsX + 1;
			randomY = rand() % WindowsY + 1;
			size = rand() % 3 + 1;
			direccion = rand() % 8 + 1;
			eje = rand() % 2 + 1; //Recto, serpenteo
			myThreads[i] = std::thread(asteroide, randomX, randomY, size,direccion,eje);
		}
		for (int i = 0; i < cantidad; i++){
	        myThreads[i].join();
	    }
	}
	return 0;
}