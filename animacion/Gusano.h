/*-----------------------------------------------------------------------------

	Developed By: Irving Guerra // https://github.com/IrvingGuerra

-------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------

	Archivo: Gusano.h

	Descripción: En este archivo estan definidas y comentadas todas las 
				 funciones que se usaran para animar a los gusanos.

-------------------------------------------------------------------------------*/

/*
		Explicacion de variables mas representativas y bases del programa.

		Nombre: Sentido
		Descripcion: Sera el sentido a donde el gusano pretende moverse
		Valores: 1,2,3,4,5,6,7,8
		Valores: Norte, Noreste, Este, Suereste, Sur, Suroeste, Oeste y Noroeste respectivamente
	
		Nombre: Direccion
		Descripcion: Ya que se tiene el sentido del gusano, se movera a una direccion direfente. 
		NOTA: El valor de la direccion posteriormente se convierte en el nuevo sentido del gusano.
		Valores: 1,2,3,4,5,6,7,8
		Valores: Norte, Noreste, Este, Suereste, Sur, Suroeste, Oeste y Noroeste respectivamente

*/

#ifndef GUSANO_H_
#define GUSANO_H_

class Gusano{
private:
	int 	sentido;
	int 	direccion;
	int 	tamano;
	float 	saveX[20];
	float 	saveY[20];
public:
	Gusano(int = 1, int = 20);
	void inicializaGusano(int, float, float, int);
	void imprimeGusanoColor();
	void imprimeGusanoBlanco();
	void mueveGusano(int,int);
	/*
		Tipo: Funciones
		Descripción: De Norte hasta Norte, pasando primera vez por NorESTE
		D2: Vuelta a la derecha
		D3: Sentido a las manecillas del reloj
	*/
	void NtoNE(); //Norte to Noreste...
	void NEtoE();
	void EtoSE();
	void SEtoS();
	void StoSO();
	void SOtoO();
	void OtoNO();
	void NOtoN(); //Noroeste to Norte...
	/*
		Tipo: Funciones
		Descripción: De Norte hasta Norte, pasando primera vez por NorOESTE
		D2: Vuelta a la izquierda
		D3: Sentido contrario a las manecillas del reloj
	*/
	void NtoNO();
	void NOtoO();
	void OtoSO();
	void SOtoS();
	void StoSE();
	void SEtoE();
	void EtoNE();
	void NEtoN();
	/*
		Tipo: Funciones
		Descripción: El gusano ira en linea recta.
	*/
	void straightN(); //recto Norte
	void straightNE();
	void straightE();
	void straightSE();
	void straightS();
	void straightSO();
	void straightO();
	void straightNO();
	/*
		Tipo: Funciones
		Descripción: El gusano ira en linea con serpenteo.
	*/
	void snakeN(); //serpenteo Norte
	void snakeNE();
	void snakeE();
	void snakeSE();
	void snakeS();
	void snakeSO();
	void snakeO();
	void snakeNO();
};
#endif