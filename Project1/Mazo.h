#include <algorithm>
#include <cstdlib>
#include "Carta.h"
using namespace std;
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
	Carta* getCarta(string, string);

protected:
	Carta** mazo;
	int cant;
};

