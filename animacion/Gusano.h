#ifndef GUSANO_H_
#define GUSANO_H_

class Gusano{
private:
	int sentido;
	//1 = Norte, 2 = Noroeste, 3 = Este, 4 = Sureste, 5 = Sur, 6 = Suroeste, 7 = Oeste, 8 = Noroeste
	int direccion;
	//1 = Norte, 2 = Noroeste, 3 = Este, 4 = Sureste, 5 = Sur, 6 = Suroeste, 7 = Oeste, 8 = Noroeste
	float inicialX;
	float inicialY;
	int tamano;

	float saveX1[10];
	float saveY1[10];
	float saveX2[10];
	float saveY2[10];
public:
	Gusano(int = 1,float = 100, float = 100, int = 10);
	void inicializaGusano(int, float, float, int);
	void imprimeGusanoColor();
	void imprimeGusanoBlanco();
	void mueveGusano(int,int);

	//Vueltas a la derecha
	void NtoNE();
	void NEtoE();
	void EtoSE();
	void SEtoS();
	void StoSO();
	void SOtoO();
	void OtoNO();
	void NOtoN();

	//Vueltas a la izquierda
	void NtoNO();
	void NOtoO();
	void OtoSO();
	void SOtoS();
	void StoSE();
	void SEtoE();
	void EtoNE();
	void NEtoN();


	//Rectas

	void straightN();
	void straightNE();
	void straightE();
	void straightSE();
	void straightS();
	void straightSO();
	void straightO();
	void straightNO();

};
#endif