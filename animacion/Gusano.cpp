#include "gfx.h"
#include "Gusano.h"
#include <unistd.h>
#include <iostream>
using namespace std;
const int TIEMPO = 3000;
Gusano::Gusano(int s, int tam) : sentido(s), tamano(tam){}
void Gusano::inicializaGusano(int s,float x, float y, int tam){
	tamano 	= tam; 
	sentido = s;
	//Creamos pixel a pixel el gusano
	switch(sentido){
		case 1: case 5: //Norte y Sur. = |
			for (int i = 0; i < tamano; ++i){
				saveX[i] = x;
				saveY[i] = y+i;
			}
		break;
		case 2: case 4: //Noroeste y Sureste. = \.  
			for (int i = 0; i < tamano; ++i){
				saveX[i] = x-i;
				saveY[i] = y-i;
			}
		break;
		case 3: //Este = __
			for (int i = 0; i < tamano; ++i){
				saveX[i] = x-i;
				saveY[i] = y;
			}
		break;
		case 7: //Oeste = __
			for (int i = 0; i < tamano; ++i){
				saveX[i] = x+i;
				saveY[i] = y;
			}
		break;
		case 6: case 8: //Suroeste y Noreste = /
			for (int i = 0; i < tamano; ++i){
				saveX[i] = x-i;
				saveY[i] = y+i;
			}
		break;
	}
	return;
}
void Gusano::imprimeGusanoColor(){
	//gfx_color(0,0,0); //Color negro
	//Color random!!! Menos blanco
	gfx_color(rand() % 254 + 0,rand() % 254 + 0,rand() % 254 + 0);
	
	for (int i = 0; i < tamano; ++i){
		gfx_point(saveX[i],saveY[i]);
	}
	gfx_flush();
	usleep(TIEMPO);
	imprimeGusanoBlanco();
	return;
}
void Gusano::imprimeGusanoBlanco(){
	gfx_color(255,255,255);
	for (int i = 0; i < tamano; ++i){
		gfx_point(saveX[i],saveY[i]);
	}
	gfx_flush();
	return;
}
void Gusano::NtoNE(){
	for (int h = 1; h < 5; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX[i] = saveX[i-1];
				saveY[i] = saveY[i-1];
			}
			float decimal = (float)h/10;
			saveX[0] = saveX[0]+decimal;
			saveY[0] = saveY[0]-1+decimal;
			imprimeGusanoColor();					
		}	
	}
}
void Gusano::NEtoE(){
	for (int h = 5; h < 10; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX[i] = saveX[i-1];
				saveY[i] = saveY[i-1];
			}
			float decimal = (float)h/10;
			saveX[0] = saveX[0]+decimal;
			saveY[0] = saveY[0]-1+decimal;
			imprimeGusanoColor();			
		}	
	}
}
void Gusano::EtoSE(){
	for (int h = 1; h < 5; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX[i] = saveX[i-1];
				saveY[i] = saveY[i-1];	
			}
			float decimal = (float)h/10;
			saveX[0] = saveX[0]+1-decimal;
			saveY[0] = saveY[0]+decimal;
			imprimeGusanoColor();				
		}	
	}
}
void Gusano::SEtoS(){
	for (int h = 5; h < 10; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX[i] = saveX[i-1];
				saveY[i] = saveY[i-1];
			}
			float decimal = (float)h/10;
			saveX[0] = saveX[0]+1-decimal;
			saveY[0] = saveY[0]+decimal;
			imprimeGusanoColor();			
		}	
	}
}
void Gusano::StoSO(){
	for (int h = 1; h < 5; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX[i] = saveX[i-1];
				saveY[i] = saveY[i-1];
			}
			float decimal = (float)h/10;
			saveX[0] = saveX[0]-decimal;
			saveY[0] = saveY[0]+1-decimal;
			imprimeGusanoColor();			
		}	
	}
}
void Gusano::SOtoO(){
	for (int h = 5; h < 10; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX[i] = saveX[i-1];
				saveY[i] = saveY[i-1];
			}
			float decimal = (float)h/10;
			saveX[0] = saveX[0]-decimal;
			saveY[0] = saveY[0]+1-decimal;
			imprimeGusanoColor();			
		}	
	}
}
void Gusano::OtoNO(){
	for (int h = 1; h < 5; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX[i] = saveX[i-1];
				saveY[i] = saveY[i-1];
			}
			float decimal = (float)h/10;
			saveX[0] = saveX[0]-1+decimal;
			saveY[0] = saveY[0]-decimal;
			imprimeGusanoColor();			
		}	
	}
}
void Gusano::NOtoN(){
	for (int h = 5; h < 10; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX[i] = saveX[i-1];
				saveY[i] = saveY[i-1];
			}
			float decimal = (float)h/10;
			saveX[0] = saveX[0]-1+decimal;
			saveY[0] = saveY[0]-decimal;
			imprimeGusanoColor();			
		}	
	}
}
void Gusano::straightN(){
	for(int j = 0; j < 50; j++){
		for (int i = (tamano-1); i > 0; --i){
			saveX[i] = saveX[i-1];
			saveY[i] = saveY[i-1];
		}
		saveY[0]--;
		imprimeGusanoColor();
	}
}
void Gusano::straightNE(){
	for(int j = 0; j < 50; j++){
		for (int i = (tamano-1); i > 0; --i){
			saveX[i] = saveX[i-1];
			saveY[i] = saveY[i-1];
		}
		saveX[0]++;
		saveY[0]--;	
		imprimeGusanoColor();
	}
}
void Gusano::straightE(){
	for(int j = 0; j < 50; j++){
		for (int i = (tamano-1); i > 0; --i){
			saveX[i] = saveX[i-1];
			saveY[i] = saveY[i-1];
		}
		saveX[0]++;
		imprimeGusanoColor();
	}
}
void Gusano::straightSE(){
	for(int j = 0; j < 50; j++){
		for (int i = (tamano-1); i > 0; --i){
			saveX[i] = saveX[i-1];
			saveY[i] = saveY[i-1];
		}
		saveX[0]++;
		saveY[0]++;
		imprimeGusanoColor();
	}
}
void Gusano::straightS(){
	for(int j = 0; j < 50; j++){
		for (int i = (tamano-1); i > 0; --i){
			saveX[i] = saveX[i-1];
			saveY[i] = saveY[i-1];
		}
		saveY[0]++;
		imprimeGusanoColor();
	}
}
void Gusano::straightSO(){
	for(int j = 0; j < 50; j++){
		for (int i = (tamano-1); i > 0; --i){
			saveX[i] = saveX[i-1];
			saveY[i] = saveY[i-1];
		}
		saveX[0]--;
		saveY[0]++;
		imprimeGusanoColor();
	}
}
void Gusano::straightO(){
	for(int j = 0; j < 50; j++){
		for (int i = (tamano-1); i > 0; --i){
			saveX[i] = saveX[i-1];
			saveY[i] = saveY[i-1];	
		}
		saveX[0]--;
		imprimeGusanoColor();
	}
}
void Gusano::straightNO(){
	for(int j = 0; j < 50; j++){
		for (int i = (tamano-1); i > 0; --i){
			saveX[i] = saveX[i-1];
			saveY[i] = saveY[i-1];
		}
		saveX[0]--;
		saveY[0]--;
		imprimeGusanoColor();
	}
}
void Gusano::snakeN(){
	/*NOTA. En los serpenteos se repiten mas veces para que duren como un Straight*/
	NtoNE();
	NEtoN();
	NtoNO();
	NOtoN();
	NtoNE();
	NEtoN();
	NtoNO();
	NOtoN();
	NtoNE();
	NEtoN();
	NtoNO();
	NOtoN();
	NtoNE();
	NEtoN();
	NtoNO();
	NOtoN();
}
void Gusano::snakeNE(){
	NtoNE();
	NEtoN();
	NtoNE();
	NEtoN();
	NtoNE();
	NEtoN();
	NtoNE();
	NEtoN();
	NtoNE();
	NEtoN();
}
void Gusano::snakeE(){
	EtoSE();
	SEtoE();
	EtoNE();
	NEtoE();
	EtoSE();
	SEtoE();
	EtoNE();
	NEtoE();
}
void Gusano::snakeSE(){
	EtoSE();
	SEtoE();
	EtoSE();
	SEtoE();
	EtoSE();
	SEtoE();
	EtoSE();
	SEtoE();
	EtoSE();
	SEtoE();
}
void Gusano::snakeS(){
	StoSE();
	SEtoS();
	StoSO();
	SOtoS();
	StoSE();
	SEtoS();
	StoSO();
	SOtoS();
}
void Gusano::snakeSO(){
	StoSO();
	SOtoS();
	StoSO();
	SOtoS();
	StoSO();
	SOtoS();
	StoSO();
	SOtoS();
	StoSO();
	SOtoS();
}
void Gusano::snakeO(){
	OtoNO();
	NOtoO();
	OtoSO();
	SOtoO();
	OtoNO();
	NOtoO();
	OtoSO();
	SOtoO();
}
void Gusano::snakeNO(){
	OtoNO();
	NOtoO();
	OtoNO();
	NOtoO();
	OtoNO();
	NOtoO();
	OtoNO();
	NOtoO();
	OtoNO();
	NOtoO();
}
void Gusano::NtoNO(){
	for (int h = 1; h < 5; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX[i] = saveX[i-1];
				saveY[i] = saveY[i-1];
			}
			float decimal = (float)h/10;
			saveX[0] = saveX[0]-decimal;
			saveY[0] = saveY[0]-1+decimal;
			imprimeGusanoColor();			
		}	
	}
}
void Gusano::NOtoO(){
	for (int h = 5; h < 10; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX[i] = saveX[i-1];
				saveY[i] = saveY[i-1];
			}
			float decimal = (float)h/10;
			saveX[0] = saveX[0]-decimal;
			saveY[0] = saveY[0]-1+decimal;
			imprimeGusanoColor();			
		}	
	}
}
void Gusano::OtoSO(){
	for (int h = 1; h < 5; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX[i] = saveX[i-1];
				saveY[i] = saveY[i-1];
			}
			float decimal = (float)h/10;
			saveX[0] = saveX[0]-1+decimal;
			saveY[0] = saveY[0]+decimal;
			imprimeGusanoColor();			
		}	
	}
}
void Gusano::SOtoS(){
	for (int h = 5; h < 10; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX[i] = saveX[i-1];
				saveY[i] = saveY[i-1];
			}
			float decimal = (float)h/10;
			saveX[0] = saveX[0]-1+decimal;
			saveY[0] = saveY[0]+decimal;
			imprimeGusanoColor();			
		}	
	}
}
void Gusano::StoSE(){
	for (int h = 1; h < 5; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX[i] = saveX[i-1];
				saveY[i] = saveY[i-1];
			}
			float decimal = (float)h/10;
			saveX[0] = saveX[0]+decimal;
			saveY[0] = saveY[0]+1-decimal;
			imprimeGusanoColor();			
		}	
	}
}
void Gusano::SEtoE(){
	for (int h = 5; h < 10; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX[i] = saveX[i-1];
				saveY[i] = saveY[i-1];
			}
			float decimal = (float)h/10;
			saveX[0] = saveX[0]+decimal;
			saveY[0] = saveY[0]+1-decimal;
			imprimeGusanoColor();			
		}	
	}
}
void Gusano::EtoNE(){
	for (int h = 1; h < 5; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX[i] = saveX[i-1];
				saveY[i] = saveY[i-1];
			}
			float decimal = (float)h/10;
			saveX[0] = saveX[0]+1-decimal;
			saveY[0] = saveY[0]-decimal;
			imprimeGusanoColor();			
		}	
	}
}
void Gusano::NEtoN(){
	for (int h = 5; h < 10; ++h){
		for (int j = 0; j < 5; ++j){
			for (int i = (tamano-1); i > 0; --i){
				saveX[i] = saveX[i-1];
				saveY[i] = saveY[i-1];
			}
			float decimal = (float)h/10;
			saveX[0] = saveX[0]+1-decimal;
			saveY[0] = saveY[0]-decimal;
			imprimeGusanoColor();			
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
			switch(sentido){
				case 1: //Norte
					switch(direccion){
						case 1: //Norte
							snakeN();
							sentido = 1;
						break;
						case 2: //Noreste
							NtoNE();
							snakeNE();
							sentido = 8;
						break;
						case 3: //Este
							NtoNE();
							NEtoE();
							snakeE();
							sentido = 3;
						break;
						case 4: //Sureste
							NtoNE();
							NEtoE();
							EtoSE();
							snakeSE();
							sentido = 4;
						break;
						case 5: //Sur
							NtoNE();
							NEtoE();
							EtoSE();
							SEtoS();
							snakeS();
							sentido = 5;
						break;
						case 6: //Suroeste
							NtoNE();
							NEtoE();
							EtoSE();
							SEtoS();
							StoSO();
							snakeSO();
							sentido = 6;
						break;
						case 7: //Oeste
							NtoNE();
							NEtoE();
							EtoSE();
							SEtoS();
							StoSO();
							SOtoO();
							snakeO();
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
							snakeNO();
							sentido = 2;
						break;
					}
				break;
				case 8: //Noreste
					switch(direccion){
						case 1: //Norte
							NEtoN();
							snakeN();
							sentido = 1;
						break;
						case 2: //Noreste
							snakeNE();
							sentido = 8;
						break;
						case 3: //Este
							NEtoE();
							snakeE();
							sentido = 3;
						break;
						case 4: //Sureste
							NEtoE();
							EtoSE();
							snakeSE();
							sentido = 4;
						break;
						case 5: //Sur
							NEtoE();
							EtoSE();
							SEtoS();
							snakeS();
							sentido = 5;
						break;
						case 6: //Suroeste
							NEtoE();
							EtoSE();
							SEtoS();
							StoSO();
							snakeSO();
							sentido = 6;
						break;
						case 7: //Oeste
							NEtoE();
							EtoSE();
							SEtoS();
							StoSO();
							SOtoO();
							snakeO();
							sentido = 7;
						break;
						case 8: //Noroeste
							NEtoE();
							EtoSE();
							SEtoS();
							StoSO();
							SOtoO();
							OtoNO();
							snakeNO();
							sentido = 2;
						break;
					}
				break;
				case 3: //Este
					switch(direccion){
						case 1: //Norte
							EtoNE();
							NEtoN();
							snakeN();
							sentido = 1;
						break;
						case 2: //Noreste
							EtoNE();
							snakeNE();
							sentido = 8;
						break;
						case 3: //Este
							snakeE();
							sentido = 3;
						break;
						case 4: //Sureste
							EtoSE();
							snakeSE();
							sentido = 4;
						break;
						case 5: //Sur
							EtoSE();
							SEtoS();
							snakeS();
							sentido = 5;
						break;
						case 6: //Suroeste
							EtoSE();
							SEtoS();
							StoSO();
							snakeSO();
							sentido = 6;
						break;
						case 7: //Oeste
							EtoSE();
							SEtoS();
							StoSO();
							SOtoO();
							snakeO();
							sentido = 7;
						break;
						case 8: //Noroeste
							EtoSE();
							SEtoS();
							StoSO();
							SOtoO();
							OtoNO();
							snakeNO();
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
							snakeN();
							sentido = 1;
						break;
						case 2: //Noreste
							SEtoE();
							EtoNE();
							snakeNE();
							sentido = 8;
						break;
						case 3: //Este
							SEtoE();
							snakeE();
							sentido = 3;
						break;
						case 4: //Sureste
							snakeSE();
							sentido = 4;
						break;
						case 5: //Sur
							SEtoS();
							snakeS();
							sentido = 5;
						break;
						case 6: //Suroeste
							SEtoS();
							StoSO();
							snakeSO();
							sentido = 6;
						break;
						case 7: //Oeste
							SEtoS();
							StoSO();
							SOtoO();
							snakeO();
							sentido = 7;
						break;
						case 8: //Noroeste
							SEtoS();
							StoSO();
							SOtoO();
							OtoNO();
							snakeNO();
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
							snakeN();
							sentido = 1;
						break;
						case 2: //Noreste
							StoSE();
							SEtoE();
							EtoNE();
							snakeNE();
							sentido = 8;
						break;
						case 3: //Este
							StoSE();
							SEtoE();
							snakeE();
							sentido = 3;
						break;
						case 4: //Sureste
							StoSE();
							snakeSE();
							sentido = 4;
						break;
						case 5: //Sur
							snakeS();
							sentido = 5;
						break;
						case 6: //Suroeste
							StoSO();
							snakeSO();
							sentido = 6;
						break;
						case 7: //Oeste
							StoSO();
							SOtoO();
							snakeO();
							sentido = 7;
						break;
						case 8: //Noroeste
							StoSO();
							SOtoO();
							OtoNO();
							snakeNO();
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
							snakeN();
							sentido = 1;
						break;
						case 2: //Noreste
							SOtoS();
							StoSE();
							SEtoE();
							EtoNE();
							snakeNE();
							sentido = 8;
						break;
						case 3: //Este
							SOtoS();
							StoSE();
							SEtoE();
							snakeE();
							sentido = 3;
						break;
						case 4: //Sureste
							SOtoS();
							StoSE();
							snakeSE();
							sentido = 4;
						break;
						case 5: //Sur
							SOtoS();
							snakeS();
							sentido = 5;
						break;
						case 6: //Suroeste
							snakeSO();
							sentido = 6;
						break;
						case 7: //Oeste
							SOtoO();
							snakeO();
							sentido = 7;
						break;
						case 8: //Noroeste
							SOtoO();
							OtoNO();
							snakeNO();
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
							snakeN();
							sentido = 1;
						break;
						case 2: //Noreste
							OtoSO();
							SOtoS();
							StoSE();
							SEtoE();
							EtoNE();
							snakeNE();
							sentido = 8;
						break;
						case 3: //Este
							OtoSO();
							SOtoS();
							StoSE();
							SEtoE();
							snakeE();
							sentido = 3;
						break;
						case 4: //Sureste
							OtoSO();
							SOtoS();
							StoSE();
							snakeSE();
							sentido = 4;
						break;
						case 5: //Sur
							OtoSO();
							SOtoS();
							snakeS();
							sentido = 5;
						break;
						case 6: //Suroeste
							OtoSO();
							snakeSO();
							sentido = 6;
						break;
						case 7: //Oeste
							snakeO();
							sentido = 7;
						break;
						case 8: //Noroeste
							OtoNO();
							snakeNO();
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
							snakeN();
							sentido = 1;
						break;
						case 2: //Noreste
							NOtoO();
							OtoSO();
							SOtoS();
							StoSE();
							SEtoE();
							EtoNE();
							snakeNE();
							sentido = 8;
						break;
						case 3: //Este
							NOtoO();
							OtoSO();
							SOtoS();
							StoSE();
							SEtoE();
							snakeE();
							sentido = 3;
						break;
						case 4: //Sureste
							NOtoO();
							OtoSO();
							SOtoS();
							StoSE();
							snakeSE();
							sentido = 4;
						break;
						case 5: //Sur
							NOtoO();
							OtoSO();
							SOtoS();
							snakeS();
							sentido = 5;
						break;
						case 6: //Suroeste
							NOtoO();
							OtoSO();
							snakeSO();
							sentido = 6;
						break;
						case 7: //Oeste
							NOtoO();
							snakeO();
							sentido = 7;
						break;
						case 8: //Noroeste
							snakeNO();
							sentido = 2;
						break;
					}
				break;
			}
		break;
	}
	return;
}