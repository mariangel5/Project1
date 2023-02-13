#ifndef MANO_H
#define MANO_H
#include "Mazo.h"

class Mano   
{
public:
	Mano();
	~Mano();
	void agregarCarta(Mazo*);
	void limpiar();
	int getPuntos();
	std::string toString();
	bool buscarA();
	void agregarCarta(Carta*);
	Carta* getCarta(int);
	

private:
	Carta** cartas;
	int tam;
	int can;
};
#endif

