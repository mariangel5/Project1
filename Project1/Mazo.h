#include "Carta.h"

#pragma once
class Mazo
{
public:
	Mazo();
	~Mazo();
	void inicializar();
	void barajar();
	Carta* tomarCarta();
	string toString();

protected:
	Carta** mazo;
	int cant;
};

