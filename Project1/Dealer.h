#ifndef DEALER_H
#define DEALER_H
#include "JugadorGenerico.h"

class Dealer: public JugadorGenerico {

public:
	Dealer(std::string, Mano*);
	~Dealer();
	void volteaSegunda();
	std::string toString();
	void guardarDealer(std::ofstream&);
};

#endif
