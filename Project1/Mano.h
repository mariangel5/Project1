#include "Mazo.h"

#pragma once
class Mano : public Mazo
{
public:
	Mano();
	~Mano();
	void agregarCarta(Mazo*);
	void limpiar();
	int getPuntos();
private:
	Carta* cartas;
};

