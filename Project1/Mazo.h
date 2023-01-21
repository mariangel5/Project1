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
};

