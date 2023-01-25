#ifndef DEALER_H
#define DEALER_H

#include "JugadorGenerico.h"
class Dealer: JugadorGenerico
{
public:
	Dealer(string, Mano*);
	~Dealer();
	virtual Carta* pedirCarta();
	void volteaSegunda();
};

#endif
