#ifndef JUGADORGENERICO_H
#define JUGADORGENERICO_H

#include <iostream>
#include <sstream>
#include <string>
#include "Mano.h"
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
	Carta* pedirCarta();
	bool sePaso();
	string toString();

};

#endif
