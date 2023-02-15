#ifndef MAZO_H
#define MAZO_H
#include <algorithm>
#include <cstdlib>
#include "Carta.h"

class Mazo
{
public:
	Mazo();
	~Mazo();
	void inicializar();
	void barajar();
	Carta* tomarCarta();
	std::string toString();
	Carta* getCarta(std::string, std::string);
	void guardarMazo(std::ofstream&);
	void agregarCarta(Carta*);

protected:
	Carta** mazo;
	int cant;
};
#endif

