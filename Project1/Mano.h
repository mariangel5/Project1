#include "Mazo.h"

#pragma once
class Mano   
{
public:
	Mano();
	~Mano();
	void agregarCarta(Mazo*);
	void limpiar();
	int getPuntos();
	string toString();
	bool buscarA();
	void agregarCarta(Carta*);
	Carta* getCarta(int);
	

private:
	Carta** cartas;
	int tam;
	int can;
};

