#include "gfx.h"
#include "Asteroide.h"
#include <unistd.h>
#include <iostream>
#include <math.h> 

using namespace std;
const int TIEMPO = 70000;
#define PI	3.11015926510
int anguloCreciente = 1;
int getRnd(int i,int f){return rand() % (f-i) + (i);}

Asteroide::Asteroide(int s, int dir) : direccion(dir){}

void Asteroide::inicializaAsteroide(float x, float y, int s){
    //Creamos el asteroide
    //Unicamente dibujaremos un asteroide dependiendo el tamaño que se le ingreso
	//GUARDAMOS LOS EJES. YA QUE EN TEORIA EL ASTEROIDE ESTARA EN 0,0, Y UNICAMENTE SE DESPLAZA A SU EJE AL IMRPIMIRSE
	ejeX = x;
	ejeY = y;
	size = s;
	//size = 1;
	int xInit;
	int yInit;
    switch(size){
        case 1: //GRANDE
			//Haremos el asteroide
			xInit = getRnd(50,110);
			yInit = getRnd(50,110);
            pts[0].x= - xInit; pts[0].y= yInit; //Haremos cordenadas Random, para tener siempre asteroides diferentes
            pts[1].x= - getRnd(70,130); pts[1].y= getRnd(0,30);
            pts[2].x= - getRnd(50,110); pts[2].y= - getRnd(40,100);
            pts[3].x= getRnd(0,50); pts[3].y= - getRnd(50,110);
			pts[4].x= getRnd(0,60); pts[4].y= - getRnd(0,50);
			pts[5].x= getRnd(30,90); pts[2].y= - getRnd(0,50);
			pts[6].x= getRnd(50,110); pts[6].y= getRnd(30,90);
			pts[7].x= getRnd(10,70); pts[7].y= getRnd(50,110);
			pts[8].x= -getRnd(10,70); pts[8].y= getRnd(50,110);
			pts[9].x= - xInit; pts[9].y= yInit;
		break;
		case 2: //MEDIADO
			xInit = getRnd(30,70);
			yInit = getRnd(30,70);
			pts[0].x= - xInit; pts[0].y= yInit;
            pts[1].x= - getRnd(35,75); pts[1].y= getRnd(0,20);
            pts[2].x= - getRnd(35,75); pts[2].y= - getRnd(35,75);
            pts[3].x= getRnd(0,20); pts[3].y= - getRnd(25,55);
			pts[4].x= getRnd(25,55); pts[4].y= - getRnd(20,50);
			pts[5].x= getRnd(35,75); pts[2].y= - getRnd(0,20);
			pts[6].x= getRnd(35,75); pts[6].y= getRnd(20,50);
			pts[7].x= getRnd(20,50); pts[7].y= getRnd(20,50);
			pts[8].x= -getRnd(0,30); pts[8].y= getRnd(20,50);
			pts[9].x= -xInit; pts[9].y= yInit;
		break;
		case 3: //PEQUEÑO
			xInit = getRnd(10,30);
			yInit = getRnd(10,30);
			pts[0].x= - xInit; pts[0].y= yInit;
            pts[1].x= - getRnd(20,40); pts[1].y= getRnd(0,10);
            pts[2].x= - getRnd(20,40); pts[2].y= - getRnd(20,40);
            pts[3].x= getRnd(0,10); pts[3].y= - getRnd(15,35);
			pts[4].x= getRnd(15,35); pts[4].y= - getRnd(10,30);
			pts[5].x= getRnd(20,40); pts[2].y= - getRnd(0,10);
			pts[6].x= getRnd(20,40); pts[6].y= getRnd(5,25);
			pts[7].x= getRnd(10,30); pts[7].y= getRnd(5,25);
			pts[8].x= -getRnd(0,15); pts[8].y= getRnd(10,30);
			pts[9].x= -xInit; pts[9].y= yInit;
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
	imprimeAsteroideNegro();
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

