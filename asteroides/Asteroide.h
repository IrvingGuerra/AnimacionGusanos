#ifndef ASTEROIDE_H_
#define ASTEROIDE_H_
struct punto {
	float x;
	float y;
};
class Asteroide{
private:
    punto 	pts[10];
	punto 	ptsRotados[10];
	int		ejeX; //Posicion en la screen eje X
	int 	ejeY; //Posicion en la screen eje Y
    int     size; //PEQUEÑO, MEDIANO O GRANDE y mas formas.
	int 	direccion; //NORTE, NORESTE, ESTE, SURESTE, SUR, SUROESTE, OESTE, NOROESTE, NORTE
	int 	eje; //IZQUIERDA O DERECHA
public:
	Asteroide(int = 1, int = 10);
	void inicializaAsteroide(float, float, int);
	void imprimeAsteroideColor();
	void imprimeAsteroideNegro();
	void mueveAsteroide(int,int);
    void rotarEje(float angulo);
};
#endif