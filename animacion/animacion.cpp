#include "gfx.h"
#include "Gusano.h"


#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
	/*
 int t;
 gfx_open(800, 600, "Ejemplo Micro Animacion GFX");
 gfx_color(0,200,100);
 for(t = 0; t < 100; t++){
 gfx_clear();
 gfx_line( t*1+80, t*2+40, t*2+40, t*3+80 );
 gfx_line(t*5+80, t*3+40, t*3+40, t*5+80);
 gfx_flush();
 usleep(41666); //24 por segundo
 }
 */
	srand(time(NULL));

	if (atoi(argv[1]) < 1 || argv[1] == NULL){
		printf("Debe de ingresar un numero mayor a 0");
	}else{
		
		gfx_open(800, 600, "Gusanos Animados");		//Creamos la ventana
		gfx_clear_color(255,255,255); 				//Ponemos un fondo blanco
		gfx_clear();
		gfx_color(0,0,0); 							//Color Negro por default

/*
		int randomX = rand() % 800 + 1;
		int randomy = rand() % 600 + 1;
*/
		int randomX = 100;
		int randomy = 100;
		int tamano = 10;

		Gusano a;
		a.inicializaGusano(randomX,randomy,tamano);
		a.imprimeGusano();


	
		//Todo estara en un while infinito hasta presionar la letra q
		char c;
		while(1) {
			c = gfx_wait();
			if(c=='q') break;
		}

	}

	return 0;
}