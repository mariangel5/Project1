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
	int num;

public:
	JugadorGenerico();
	JugadorGenerico(string, Mano*);
	virtual ~JugadorGenerico();
	void setNickname(string);
	string  getNickname();
	void setMano(Mano*);
	Mano*  getMano();
	virtual void pedirCarta() = 0;
	/*bool sePaso();*/
	virtual string toString() =0;

};

#endif
