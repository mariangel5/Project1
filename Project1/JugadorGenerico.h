#ifndef JUGADORGENERICO_H
#define JUGADORGENERICO_H

#include <iostream>
#include <sstream>
#include <string>
#include "Mano.h"
#include "Carta.h"
using namespace std;

class JugadorGenerico
{
protected:
	string nickname;
	Mano* mano;

public:
	JugadorGenerico();
	JugadorGenerico(string, Mano*);
	~JugadorGenerico();
	void setNickname(string);
	string  getNickname();
	void setMano(Mano*);
	Mano*  getMano();
	virtual Carta* pedirCarta();
	bool sePaso();

};

#endif
