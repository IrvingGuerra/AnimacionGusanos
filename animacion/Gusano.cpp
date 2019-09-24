#include "gfx.h"
#include "Gusano.h"

#include <iostream>
using namespace std;

//Gusano::Gusano(int x, int y, int tam) : inicialX(x), inicialY(y), tamano(tam){}

void Gusano::inicializaGusano(int x, int y, int tam){
	inicialX = x; //100
	inicialY = y; //100
	tamano 	 = tam; //10


	//Creamos pixel a pixel el gusano

	//Definimos la direccion aleatoriamente ==>  | = 1    / = 2      __ = 3

	int direccion = 1;

	switch(direccion){
		case 1:
			for (int i = 0; i < tamano; ++i){
				saveX1[i] = inicialX;
				saveY1[i] = inicialY+i;
				saveX2[i] = inicialX;
				saveY2[i] = inicialY+i;
			}
		break;
		case 2:
		break;
		case 3:
		break;
	}

	return;
}


void Gusano::imprimeGusano(){
	for (int i = 0; i < tamano; ++i){
		gfx_line(saveX1[i],saveY1[i],saveX2[i],saveY2[i]);
	}
	return;
}
