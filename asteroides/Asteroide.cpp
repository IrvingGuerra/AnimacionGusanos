#include "gfx.h"
#include "Asteroide.h"
#include <unistd.h>
#include <iostream>
#include <math.h> 

using namespace std;
const int TIEMPO = 70000;
#define PI	3.11015926510
int anguloCreciente = 1;

Asteroide::Asteroide(int s, int dir) : direccion(dir){}

void Asteroide::inicializaAsteroide(float x, float y, int s){
    //Creamos el asteroide
    //Unicamente dibujaremos un asteroide dependiendo el tamaño que se le ingreso
	//GUARDAMOS LOS EJES. YA QUE EN TEORIA EL ASTEROIDE ESTARA EN 0,0, Y UNICAMENTE SE DESPLAZA A SU EJE AL IMRPIMIRSE
	ejeX = x;
	ejeY = y;
	size = s;
    switch(size){
        case 1: //GRANDE
			//Haremos el asteroide
            pts[0].x= - 80; pts[0].y= 80;
            pts[1].x= - 100; pts[1].y= 0;
            pts[2].x= - 80; pts[2].y= - 70;
            pts[3].x= 0; pts[3].y= - 80;
			pts[4].x= 20; pts[4].y= - 20;
			pts[5].x= 60; pts[2].y= - 20;
			pts[6].x= 80; pts[6].y= 60;
			pts[7].x= 40; pts[7].y= 80;
			pts[8].x= -40; pts[8].y= 80;
			pts[9].x= -80; pts[9].y= 80;
		break;
		case 2: //MEDIADO
			pts[0].x= - 50; pts[0].y= 50;
            pts[1].x= - 55; pts[1].y= 0;
            pts[2].x= - 50; pts[2].y= - 50;
            pts[3].x= 0; pts[3].y= - 45;
			pts[4].x= 45; pts[4].y= - 40;
			pts[5].x= 50; pts[2].y= - 0;
			pts[6].x= 50; pts[6].y= 40;
			pts[7].x= 40; pts[7].y= 40;
			pts[8].x= -10; pts[8].y= 40;
			pts[9].x= -50; pts[9].y= 50;
		break;
		case 3: //PEQUEÑO
			pts[0].x= - 20; pts[0].y= 20;
            pts[1].x= - 30; pts[1].y= 0;
            pts[2].x= - 30; pts[2].y= - 30;
            pts[3].x= 0; pts[3].y= - 25;
			pts[4].x= 25; pts[4].y= - 20;
			pts[5].x= 30; pts[2].y= - 0;
			pts[6].x= 30; pts[6].y= 15;
			pts[7].x= 20; pts[7].y= 15;
			pts[8].x= -5; pts[8].y= 20;
			pts[9].x= -20; pts[9].y= 20;
		break;
    }
	return;
}

void Asteroide::imprimeAsteroideColor(){
	gfx_color(0,200,100);
	for (int i = 0; i < 9; ++i){
		gfx_line(pts[i].x+ejeX,pts[i].y+ejeY,pts[i+1].x+ejeX,pts[i+1].y+ejeY);
	}
	gfx_flush();
	usleep(TIEMPO);
	return;
}

void Asteroide::imprimeAsteroideNegro(){
	gfx_color(0,0,0);
	for (int i = 0; i < 9; ++i){
		gfx_line(pts[i].x+ejeX,pts[i].y+ejeY,pts[i+1].x+ejeX,pts[i+1].y+ejeY);
	}
	gfx_flush();
	usleep(20000);
	return;
}

void Asteroide::mueveAsteroide(int d, int e){
    direccion = d;
    eje = e;
	imprimeAsteroideColor();
	rotarEje(1.0);

	//Grandes se desplazan lento
	//Medianos se desplazan intermedio
	//Pequeños se desplazan a gran velocidad

	int desplazamiento = 0;

	switch (size){
		case 1: 
			desplazamiento = 2;
		break;
		case 2:	
			desplazamiento = 4;
		break;	
		case 3:
			desplazamiento = 6;
		break;	
	}

	switch (direccion){
		case 1: //Norte
			ejeY-=desplazamiento;
		break;
		case 2:	//Noreste
			ejeY-=desplazamiento;
			ejeX+=desplazamiento;
		break;	
		case 3:	//Este
			ejeX+=desplazamiento;
		break;	
		case 4:	//Sureste
			ejeX+=desplazamiento;
			ejeY+=desplazamiento;
		break;	
		case 5:	//Sur
			ejeY+=desplazamiento;
		break;	
		case 6:	//Suroeste
			ejeY+=desplazamiento;
			ejeX-=desplazamiento;
		break;	
		case 7:	//Oeste
			ejeX-=desplazamiento;
		break;	
		case 8:	//Noroeste
			ejeX-=desplazamiento;
			ejeY-=desplazamiento;
		break;	
	}


}

void Asteroide::rotarEje(float angulo) {
	angulo = (PI*angulo)/180.0;
    float sinTheta = sin(angulo);
   	float cosTheta = cos(angulo);
    for (int i = 0; i < 10; ++i){
		if(eje == 1){ //Gira a la derecha
			ptsRotados[i].x = ((pts[i].x * cosTheta) - (pts[i].y * sinTheta));
       		ptsRotados[i].y = ((pts[i].y * cosTheta) + (pts[i].x * sinTheta));
		}else{	//Gira a la izquierda
			ptsRotados[i].x = ((pts[i].x * cosTheta) + (pts[i].y * sinTheta));
       		ptsRotados[i].y = ((pts[i].y * cosTheta) - (pts[i].x * sinTheta));
		}
    }
	for (int i = 0; i < 10; ++i){
		pts[i].x = ptsRotados[i].x;
		pts[i].y = ptsRotados[i].y;
	}
};