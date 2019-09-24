#ifndef GUSANO_H_
#define GUSANO_H_

class Gusano{
private:
	int inicialX;
	int inicialY;
	int tamano;
	int saveX1[10];
	int saveY1[10];
	int saveX2[10];
	int saveY2[10];
public:
	//Gusano(int = 100, int = 100, int = 10);
	void inicializaGusano(int, int, int);
	void imprimeGusano();
};
#endif