#include "gfx.h"
#include "Gusano.h"

#include <unistd.h>
#include <iostream>
using namespace std;

const int TIEMPO = 30000;

Gusano::Gusano(int s,float x, float y, int tam) : sentido(s),inicialX(x), inicialY(y), tamano(tam){}

void Gusano::inicializaGusano(int s,float x, float y, int tam){
	inicialX = x; //100
	inicialY = y; //100
	tamano 	 = tam; //10
	sentido = s;
	//Creamos pixel a pixel el gusano
	//Sentido
	//1 = Norte, 2 = Noroeste, 3 = Este, 4 = Sureste, 5 = Sur, 6 = Suroeste, 7 = Oeste, 8 = Noroeste
	switch(sentido){
		case 1: case 5: //Norte y Sur. = |
			for (int i = 0; i < tamano; ++i){
				saveX1[i] = inicialX;
				saveX2[i] = inicialX;
				saveY1[i] = inicialY+i;
				saveY2[i] = inicialY+i;
			}
		break;
		case 2: case 4: //Noroeste y Sureste. = \.  
			for (int i = 0; i < tamano; ++i){
				saveX1[i] = inicialX-i;
				saveX2[i] = inicialX-i;
				saveY1[i] = inicialY-i;
				saveY2[i] = inicialY-i;
			}
		break;
		case 3: //Este = __
			for (int i = 0; i < tamano; ++i){
				saveX1[i] = inicialX-i;
				saveX2[i] = inicialX-i;
				saveY1[i] = inicialY;
				saveY2[i] = inicialY;
			}
		break;
		case 7: //Oeste = __
			for (int i = 0; i < tamano; ++i){
				saveX1[i] = inicialX+i;
				saveX2[i] = inicialX+i;
				saveY1[i] = inicialY;
				saveY2[i] = inicialY;
			}
		break;
		case 6: case 8: //Suroeste y Noreste = /
			for (int i = 0; i < tamano; ++i){
				saveX1[i] = inicialX-i;
				saveX2[i] = inicialX-i;
				saveY1[i] = inicialY+i;
				saveY2[i] = inicialY+i;
			}
		break;
	}

	return;
}
void Gusano::imprimeGusanoColor(){
	for (int i = 0; i < tamano; ++i){
		gfx_line(saveX1[i],saveY1[i],saveX2[i],saveY2[i]);
	}
	return;
}

void Gusano::imprimeGusanoBlanco(){
	gfx_color(255,255,255);
	for (int i = 0; i < tamano; ++i){
		gfx_line(saveX1[i],saveY1[i],saveX2[i],saveY2[i]);
	}
	gfx_color(0,0,0);
	return;
}




//Vueltas a la derecha
void Gusano::NtoNE(){
	for (int h = 1; h < 5; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX1[i] = saveX1[i-1];
				saveY1[i] = saveY1[i-1];
				saveX2[i] = saveX2[i-1];
				saveY2[i] = saveY2[i-1];  
			}
			float decimal = (float)h/10;
			saveX1[0] = saveX1[0]+decimal;
			saveX2[0] = saveX2[0]+decimal;
			saveY1[0] = saveY1[0]-1+decimal;
			saveY2[0] = saveY1[0]-1+decimal;
			imprimeGusanoColor();
			gfx_flush();
	 		usleep(TIEMPO);
	 		imprimeGusanoBlanco();
		}	
	}
}
void Gusano::NEtoE(){
	for (int h = 5; h < 10; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX1[i] = saveX1[i-1];
				saveY1[i] = saveY1[i-1];
				saveX2[i] = saveX2[i-1];
				saveY2[i] = saveY2[i-1];  
			}
			float decimal = (float)h/10;
			saveX1[0] = saveX1[0]+decimal;
			saveX2[0] = saveX2[0]+decimal;
			saveY1[0] = saveY1[0]-1+decimal;
			saveY2[0] = saveY1[0]-1+decimal;
			imprimeGusanoColor();
			gfx_flush();
	 		usleep(TIEMPO);
	 		imprimeGusanoBlanco();
		}	
	}
}
void Gusano::EtoSE(){
	for (int h = 1; h < 5; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX1[i] = saveX1[i-1];
				saveY1[i] = saveY1[i-1];
				saveX2[i] = saveX2[i-1];
				saveY2[i] = saveY2[i-1];  
			}
			float decimal = (float)h/10;

			saveX1[0] = saveX1[0]+1-decimal;
			saveX2[0] = saveX2[0]+1-decimal;
			saveY1[0] = saveY1[0]+decimal;
			saveY2[0] = saveY1[0]+decimal;
			imprimeGusanoColor();
			gfx_flush();
	 		usleep(TIEMPO);
	 		imprimeGusanoBlanco();
		}	
	}
}
void Gusano::SEtoS(){
	for (int h = 5; h < 10; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX1[i] = saveX1[i-1];
				saveY1[i] = saveY1[i-1];
				saveX2[i] = saveX2[i-1];
				saveY2[i] = saveY2[i-1];  
			}
			float decimal = (float)h/10;

			saveX1[0] = saveX1[0]+1-decimal;
			saveX2[0] = saveX2[0]+1-decimal;
			saveY1[0] = saveY1[0]+decimal;
			saveY2[0] = saveY1[0]+decimal;
			imprimeGusanoColor();
			gfx_flush();
	 		usleep(TIEMPO);
	 		imprimeGusanoBlanco();
		}	
	}
}
void Gusano::StoSO(){
	for (int h = 1; h < 5; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX1[i] = saveX1[i-1];
				saveY1[i] = saveY1[i-1];
				saveX2[i] = saveX2[i-1];
				saveY2[i] = saveY2[i-1];  
			}
			float decimal = (float)h/10;
			saveX1[0] = saveX1[0]-decimal;
			saveX2[0] = saveX2[0]-decimal;
			saveY1[0] = saveY1[0]+1-decimal;
			saveY2[0] = saveY1[0]+1-decimal;
			imprimeGusanoColor();
			gfx_flush();
	 		usleep(TIEMPO);
	 		imprimeGusanoBlanco();
		}	
	}
}
void Gusano::SOtoO(){
	for (int h = 5; h < 10; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX1[i] = saveX1[i-1];
				saveY1[i] = saveY1[i-1];
				saveX2[i] = saveX2[i-1];
				saveY2[i] = saveY2[i-1];  
			}
			float decimal = (float)h/10;
			saveX1[0] = saveX1[0]-decimal;
			saveX2[0] = saveX2[0]-decimal;
			saveY1[0] = saveY1[0]+1-decimal;
			saveY2[0] = saveY1[0]+1-decimal;
			imprimeGusanoColor();
			gfx_flush();
	 		usleep(TIEMPO);
	 		imprimeGusanoBlanco();
		}	
	}
}
void Gusano::OtoNO(){
	for (int h = 1; h < 5; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX1[i] = saveX1[i-1];
				saveY1[i] = saveY1[i-1];
				saveX2[i] = saveX2[i-1];
				saveY2[i] = saveY2[i-1];  
			}
			float decimal = (float)h/10;
			saveX1[0] = saveX1[0]-1+decimal;
			saveX2[0] = saveX2[0]-1+decimal;
			saveY1[0] = saveY1[0]-decimal;
			saveY2[0] = saveY1[0]-decimal;
			imprimeGusanoColor();
			gfx_flush();
	 		usleep(TIEMPO);
	 		imprimeGusanoBlanco();
		}	
	}
}
void Gusano::NOtoN(){
	for (int h = 5; h < 10; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX1[i] = saveX1[i-1];
				saveY1[i] = saveY1[i-1];
				saveX2[i] = saveX2[i-1];
				saveY2[i] = saveY2[i-1];  
			}
			float decimal = (float)h/10;
			saveX1[0] = saveX1[0]-1+decimal;
			saveX2[0] = saveX2[0]-1+decimal;
			saveY1[0] = saveY1[0]-decimal;
			saveY2[0] = saveY1[0]-decimal;
			imprimeGusanoColor();
			gfx_flush();
	 		usleep(TIEMPO);
	 		imprimeGusanoBlanco();
		}	
	}
}
//Rectas
void Gusano::straightN(){
	for(int j = 0; j < 50; j++){
		for (int i = (tamano-1); i > 0; --i){
			saveX1[i] = saveX1[i-1];
			saveY1[i] = saveY1[i-1];
			saveX2[i] = saveX2[i-1];
			saveY2[i] = saveY2[i-1];  
		}
		saveY1[0]--;
		saveY2[0]--;
		imprimeGusanoColor();
		gfx_flush();
 		usleep(TIEMPO);
 		imprimeGusanoBlanco(); //24 por segundo
	}
}
void Gusano::straightNE(){
	for(int j = 0; j < 50; j++){
		for (int i = (tamano-1); i > 0; --i){
			saveX1[i] = saveX1[i-1];
			saveY1[i] = saveY1[i-1];
			saveX2[i] = saveX2[i-1];
			saveY2[i] = saveY2[i-1];  
		}
		saveX1[0]++;
		saveX2[0]++;
		saveY1[0]--;
		saveY2[0]--;
		imprimeGusanoColor();
		gfx_flush();
 		usleep(TIEMPO);
 		imprimeGusanoBlanco(); //24 por segundo
	}
}
void Gusano::straightE(){
	for(int j = 0; j < 50; j++){
		for (int i = (tamano-1); i > 0; --i){
			saveX1[i] = saveX1[i-1];
			saveY1[i] = saveY1[i-1];
			saveX2[i] = saveX2[i-1];
			saveY2[i] = saveY2[i-1];  
		}
		saveX1[0]++;
		saveX2[0]++;
		imprimeGusanoColor();
		gfx_flush();
 		usleep(TIEMPO);
 		imprimeGusanoBlanco(); //24 por segundo
		}
}
void Gusano::straightSE(){
	for(int j = 0; j < 50; j++){
		for (int i = (tamano-1); i > 0; --i){
			saveX1[i] = saveX1[i-1];
			saveY1[i] = saveY1[i-1];
			saveX2[i] = saveX2[i-1];
			saveY2[i] = saveY2[i-1];  
		}
		saveX1[0]++;
		saveX2[0]++;
		saveY1[0]++;
		saveY2[0]++;
		imprimeGusanoColor();
		gfx_flush();
 		usleep(TIEMPO);
 		imprimeGusanoBlanco(); //24 por segundo
		}
}
void Gusano::straightS(){
	for(int j = 0; j < 50; j++){
		for (int i = (tamano-1); i > 0; --i){
			saveX1[i] = saveX1[i-1];
			saveY1[i] = saveY1[i-1];
			saveX2[i] = saveX2[i-1];
			saveY2[i] = saveY2[i-1];  
		}
		saveY1[0]++;
		saveY2[0]++;
		imprimeGusanoColor();
		gfx_flush();
 		usleep(TIEMPO);
 		imprimeGusanoBlanco(); //24 por segundo
	}
}
void Gusano::straightSO(){
	for(int j = 0; j < 50; j++){
		for (int i = (tamano-1); i > 0; --i){
			saveX1[i] = saveX1[i-1];
			saveY1[i] = saveY1[i-1];
			saveX2[i] = saveX2[i-1];
			saveY2[i] = saveY2[i-1];  
		}
		saveX1[0]--;
		saveX2[0]--;
		saveY1[0]++;
		saveY2[0]++;
		imprimeGusanoColor();
		gfx_flush();
 		usleep(TIEMPO);
 		imprimeGusanoBlanco(); //24 por segundo
	}
}
void Gusano::straightO(){
	for(int j = 0; j < 50; j++){
		for (int i = (tamano-1); i > 0; --i){
			saveX1[i] = saveX1[i-1];
			saveY1[i] = saveY1[i-1];
			saveX2[i] = saveX2[i-1];
			saveY2[i] = saveY2[i-1];  
		}
		saveX1[0]--;
		saveX2[0]--;
		imprimeGusanoColor();
		gfx_flush();
 		usleep(TIEMPO);
 		imprimeGusanoBlanco(); //24 por segundo
	}
}
void Gusano::straightNO(){
	for(int j = 0; j < 50; j++){
		for (int i = (tamano-1); i > 0; --i){
			saveX1[i] = saveX1[i-1];
			saveY1[i] = saveY1[i-1];
			saveX2[i] = saveX2[i-1];
			saveY2[i] = saveY2[i-1];  
		}
		saveX1[0]--;
		saveX2[0]--;
		saveY1[0]--;
		saveY2[0]--;
		imprimeGusanoColor();
		gfx_flush();
 		usleep(TIEMPO);
 		imprimeGusanoBlanco(); //24 por segundo
	}
}

//Vueltas a la izquierda
void Gusano::NtoNO(){
	for (int h = 1; h < 5; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX1[i] = saveX1[i-1];
				saveY1[i] = saveY1[i-1];
				saveX2[i] = saveX2[i-1];
				saveY2[i] = saveY2[i-1];  
			}
			float decimal = (float)h/10;
			saveX1[0] = saveX1[0]-decimal;
			saveX2[0] = saveX2[0]-decimal;
			saveY1[0] = saveY1[0]-1+decimal;
			saveY2[0] = saveY1[0]-1+decimal;
			imprimeGusanoColor();
			gfx_flush();
	 		usleep(TIEMPO);
	 		imprimeGusanoBlanco();
		}	
	}
}
void Gusano::NOtoO(){
	for (int h = 5; h < 10; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX1[i] = saveX1[i-1];
				saveY1[i] = saveY1[i-1];
				saveX2[i] = saveX2[i-1];
				saveY2[i] = saveY2[i-1];  
			}
			float decimal = (float)h/10;
			saveX1[0] = saveX1[0]-decimal;
			saveX2[0] = saveX2[0]-decimal;
			saveY1[0] = saveY1[0]-1+decimal;
			saveY2[0] = saveY1[0]-1+decimal;
			imprimeGusanoColor();
			gfx_flush();
	 		usleep(TIEMPO);
	 		imprimeGusanoBlanco();
		}	
	}
}
void Gusano::OtoSO(){
	for (int h = 1; h < 5; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX1[i] = saveX1[i-1];
				saveY1[i] = saveY1[i-1];
				saveX2[i] = saveX2[i-1];
				saveY2[i] = saveY2[i-1];  
			}
			float decimal = (float)h/10;

			saveX1[0] = saveX1[0]-1+decimal;
			saveX2[0] = saveX2[0]-1+decimal;
			saveY1[0] = saveY1[0]+decimal;
			saveY2[0] = saveY1[0]+decimal;
			imprimeGusanoColor();
			gfx_flush();
	 		usleep(TIEMPO);
	 		imprimeGusanoBlanco();
		}	
	}
}
void Gusano::SOtoS(){
	for (int h = 5; h < 10; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX1[i] = saveX1[i-1];
				saveY1[i] = saveY1[i-1];
				saveX2[i] = saveX2[i-1];
				saveY2[i] = saveY2[i-1];  
			}
			float decimal = (float)h/10;

			saveX1[0] = saveX1[0]-1+decimal;
			saveX2[0] = saveX2[0]-1+decimal;
			saveY1[0] = saveY1[0]+decimal;
			saveY2[0] = saveY1[0]+decimal;
			imprimeGusanoColor();
			gfx_flush();
	 		usleep(TIEMPO);
	 		imprimeGusanoBlanco();
		}	
	}
}
void Gusano::StoSE(){
	for (int h = 1; h < 5; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX1[i] = saveX1[i-1];
				saveY1[i] = saveY1[i-1];
				saveX2[i] = saveX2[i-1];
				saveY2[i] = saveY2[i-1];  
			}
			float decimal = (float)h/10;
			saveX1[0] = saveX1[0]+decimal;
			saveX2[0] = saveX2[0]+decimal;
			saveY1[0] = saveY1[0]+1-decimal;
			saveY2[0] = saveY1[0]+1-decimal;
			imprimeGusanoColor();
			gfx_flush();
	 		usleep(TIEMPO);
	 		imprimeGusanoBlanco();
		}	
	}
}
void Gusano::SEtoE(){
	for (int h = 5; h < 10; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX1[i] = saveX1[i-1];
				saveY1[i] = saveY1[i-1];
				saveX2[i] = saveX2[i-1];
				saveY2[i] = saveY2[i-1];  
			}
			float decimal = (float)h/10;
			saveX1[0] = saveX1[0]+decimal;
			saveX2[0] = saveX2[0]+decimal;
			saveY1[0] = saveY1[0]+1-decimal;
			saveY2[0] = saveY1[0]+1-decimal;
			imprimeGusanoColor();
			gfx_flush();
	 		usleep(TIEMPO);
	 		imprimeGusanoBlanco();
		}	
	}
}
void Gusano::EtoNE(){
	for (int h = 1; h < 5; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX1[i] = saveX1[i-1];
				saveY1[i] = saveY1[i-1];
				saveX2[i] = saveX2[i-1];
				saveY2[i] = saveY2[i-1];  
			}
			float decimal = (float)h/10;
			saveX1[0] = saveX1[0]+1-decimal;
			saveX2[0] = saveX2[0]+1-decimal;
			saveY1[0] = saveY1[0]-decimal;
			saveY2[0] = saveY1[0]-decimal;
			imprimeGusanoColor();
			gfx_flush();
	 		usleep(TIEMPO);
	 		imprimeGusanoBlanco();
		}	
	}
}
void Gusano::NEtoN(){
	for (int h = 5; h < 10; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX1[i] = saveX1[i-1];
				saveY1[i] = saveY1[i-1];
				saveX2[i] = saveX2[i-1];
				saveY2[i] = saveY2[i-1];  
			}
			float decimal = (float)h/10;
			saveX1[0] = saveX1[0]+1-decimal;
			saveX2[0] = saveX2[0]+1-decimal;
			saveY1[0] = saveY1[0]-decimal;
			saveY2[0] = saveY1[0]-decimal;
			imprimeGusanoColor();
			gfx_flush();
	 		usleep(TIEMPO);
	 		imprimeGusanoBlanco();
		}	
	}
}


void Gusano::mueveGusano(int d, int tipo){
	direccion = d;
	switch(tipo){
		case 1: //Linea recta
			switch(sentido){
				case 1: //Norte
					switch(direccion){
						case 1: //Norte
							NtoNE();
							NEtoE();
							EtoSE();
							SEtoS();
							StoSO();
							SOtoO();
							OtoNO();
							NOtoN();
							straightN();
							sentido = 1;
						break;
						case 2: //Noreste
							NtoNE();
							straightNE();
							sentido = 8;
						break;
						case 3: //Este
							NtoNE();
							NEtoE();
							straightE();
							sentido = 3;
						break;
						case 4: //Sureste
							NtoNE();
							NEtoE();
							EtoSE();
							straightSE();
							sentido = 4;
						break;
						case 5: //Sur
							NtoNE();
							NEtoE();
							EtoSE();
							SEtoS();
							straightS();
							sentido = 5;
						break;
						case 6: //Suroeste
							NtoNE();
							NEtoE();
							EtoSE();
							SEtoS();
							StoSO();
							straightSO();
							sentido = 6;
						break;
						case 7: //Oeste
							NtoNE();
							NEtoE();
							EtoSE();
							SEtoS();
							StoSO();
							SOtoO();
							straightO();
							sentido = 7;
						break;
						case 8: //Noroeste
							NtoNE();
							NEtoE();
							EtoSE();
							SEtoS();
							StoSO();
							SOtoO();
							OtoNO();
							straightNO();
							sentido = 2;
						break;
					}
				break;
				case 8: //Noreste
					switch(direccion){
						case 1: //Norte
							NEtoN();
							straightN();
							sentido = 1;
						break;
						case 2: //Noreste
							straightNE();
							sentido = 8;
						break;
						case 3: //Este
							NEtoE();
							straightE();
							sentido = 3;
						break;
						case 4: //Sureste
							NEtoE();
							EtoSE();
							straightSE();
							sentido = 4;
						break;
						case 5: //Sur
							NEtoE();
							EtoSE();
							SEtoS();
							straightS();
							sentido = 5;
						break;
						case 6: //Suroeste
							NEtoE();
							EtoSE();
							SEtoS();
							StoSO();
							straightSO();
							sentido = 6;
						break;
						case 7: //Oeste
							NEtoE();
							EtoSE();
							SEtoS();
							StoSO();
							SOtoO();
							straightO();
							sentido = 7;
						break;
						case 8: //Noroeste
							NEtoE();
							EtoSE();
							SEtoS();
							StoSO();
							SOtoO();
							OtoNO();
							straightNO();
							sentido = 2;
						break;
					}
				break;
				case 3: //Este
					switch(direccion){
						case 1: //Norte
							EtoNE();
							NEtoN();
							straightN();
							sentido = 1;
						break;
						case 2: //Noreste
							EtoNE();
							straightNE();
							sentido = 8;
						break;
						case 3: //Este
							straightE();
							sentido = 3;
						break;
						case 4: //Sureste
							EtoSE();
							straightSE();
							sentido = 4;
						break;
						case 5: //Sur
							EtoSE();
							SEtoS();
							straightS();
							sentido = 5;
						break;
						case 6: //Suroeste
							EtoSE();
							SEtoS();
							StoSO();
							straightSO();
							sentido = 6;
						break;
						case 7: //Oeste
							EtoSE();
							SEtoS();
							StoSO();
							SOtoO();
							straightO();
							sentido = 7;
						break;
						case 8: //Noroeste
							EtoSE();
							SEtoS();
							StoSO();
							SOtoO();
							OtoNO();
							straightNO();
							sentido = 2;
						break;
					}
				break;
				case 4: //Sureste
					switch(direccion){
						case 1: //Norte
							SEtoE();
							EtoNE();
							NEtoN();
							straightN();
							sentido = 1;
						break;
						case 2: //Noreste
							SEtoE();
							EtoNE();
							straightNE();
							sentido = 8;
						break;
						case 3: //Este
							SEtoE();
							straightE();
							sentido = 3;
						break;
						case 4: //Sureste
							straightSE();
							sentido = 4;
						break;
						case 5: //Sur
							SEtoS();
							straightS();
							sentido = 5;
						break;
						case 6: //Suroeste
							SEtoS();
							StoSO();
							straightSO();
							sentido = 6;
						break;
						case 7: //Oeste
							SEtoS();
							StoSO();
							SOtoO();
							straightO();
							sentido = 7;
						break;
						case 8: //Noroeste
							SEtoS();
							StoSO();
							SOtoO();
							OtoNO();
							straightNO();
							sentido = 2;
						break;
					}
				break;
				case 5: //Sur
					switch(direccion){
						case 1: //Norte
							StoSE();
							SEtoE();
							EtoNE();
							NEtoN();
							straightN();
							sentido = 1;
						break;
						case 2: //Noreste
							StoSE();
							SEtoE();
							EtoNE();
							straightNE();
							sentido = 8;
						break;
						case 3: //Este
							StoSE();
							SEtoE();
							straightE();
							sentido = 3;
						break;
						case 4: //Sureste
							StoSE();
							straightSE();
							sentido = 4;
						break;
						case 5: //Sur
							straightS();
							sentido = 5;
						break;
						case 6: //Suroeste
							StoSO();
							straightSO();
							sentido = 6;
						break;
						case 7: //Oeste
							StoSO();
							SOtoO();
							straightO();
							sentido = 7;
						break;
						case 8: //Noroeste
							StoSO();
							SOtoO();
							OtoNO();
							straightNO();
							sentido = 2;
						break;
					}
				break;
				case 6: //Suroeste
					switch(direccion){
						case 1: //Norte
							SOtoS();
							StoSE();
							SEtoE();
							EtoNE();
							NEtoN();
							straightN();
							sentido = 1;
						break;
						case 2: //Noreste
							SOtoS();
							StoSE();
							SEtoE();
							EtoNE();
							straightNE();
							sentido = 8;
						break;
						case 3: //Este
							SOtoS();
							StoSE();
							SEtoE();
							straightE();
							sentido = 3;
						break;
						case 4: //Sureste
							SOtoS();
							StoSE();
							straightSE();
							sentido = 4;
						break;
						case 5: //Sur
							SOtoS();
							straightS();
							sentido = 5;
						break;
						case 6: //Suroeste
							straightSO();
							sentido = 6;
						break;
						case 7: //Oeste
							SOtoO();
							straightO();
							sentido = 7;
						break;
						case 8: //Noroeste
							SOtoO();
							OtoNO();
							straightNO();
							sentido = 2;
						break;
					}
				break;
				case 7: //Oeste
					switch(direccion){
						case 1: //Norte
							OtoSO();
							SOtoS();
							StoSE();
							SEtoE();
							EtoNE();
							NEtoN();
							straightN();
							sentido = 1;
						break;
						case 2: //Noreste
							OtoSO();
							SOtoS();
							StoSE();
							SEtoE();
							EtoNE();
							straightNE();
							sentido = 8;
						break;
						case 3: //Este
							OtoSO();
							SOtoS();
							StoSE();
							SEtoE();
							straightE();
							sentido = 3;
						break;
						case 4: //Sureste
							OtoSO();
							SOtoS();
							StoSE();
							straightSE();
							sentido = 4;
						break;
						case 5: //Sur
							OtoSO();
							SOtoS();
							straightS();
							sentido = 5;
						break;
						case 6: //Suroeste
							OtoSO();
							straightSO();
							sentido = 6;
						break;
						case 7: //Oeste
							straightO();
							sentido = 7;
						break;
						case 8: //Noroeste
							OtoNO();
							straightNO();
							sentido = 2;
						break;
					}
				break;
				case 2: //Noroeste
					switch(direccion){
						case 1: //Norte
							NOtoO();
							OtoSO();
							SOtoS();
							StoSE();
							SEtoE();
							EtoNE();
							NEtoN();
							straightN();
							sentido = 1;
						break;
						case 2: //Noreste
							NOtoO();
							OtoSO();
							SOtoS();
							StoSE();
							SEtoE();
							EtoNE();
							straightNE();
							sentido = 8;
						break;
						case 3: //Este
							NOtoO();
							OtoSO();
							SOtoS();
							StoSE();
							SEtoE();
							straightE();
							sentido = 3;
						break;
						case 4: //Sureste
							NOtoO();
							OtoSO();
							SOtoS();
							StoSE();
							straightSE();
							sentido = 4;
						break;
						case 5: //Sur
							NOtoO();
							OtoSO();
							SOtoS();
							straightS();
							sentido = 5;
						break;
						case 6: //Suroeste
							NOtoO();
							OtoSO();
							straightSO();
							sentido = 6;
						break;
						case 7: //Oeste
							NOtoO();
							straightO();
							sentido = 7;
						break;
						case 8: //Noroeste
							straightNO();
							sentido = 2;
						break;
					}
				break;
			}	
		break;
		case 2: //Serpenteo
			
		break;
	}
	return;
}
