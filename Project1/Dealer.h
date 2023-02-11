#ifndef DEALER_H
#define DEALER_H
#include "JugadorGenerico.h"

class Dealer: public JugadorGenerico {

public:
	Dealer(string, Mano*);
	~Dealer();
	void volteaSegunda();
	string toString();
};

#endif
