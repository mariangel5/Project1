#ifndef JUGADORGENERICO_H
#define JUGADORGENERICO_H

#include <iostream>
#include <sstream>
#include <string>
#include "Mano.h"
#include <Windows.h>

using namespace std;

class JugadorGenerico
{
protected:
	string nickname;
	Mano* mano;
	int numJug;
	string estado;

public:
	JugadorGenerico();
	virtual ~JugadorGenerico();
	void setNumJug(int);
	int getNumJug();
	JugadorGenerico(string, Mano*);
	void setNickname(string);
	string  getNickname();
	void setMano(Mano*);
	Mano*  getMano();
	void pedirCarta(Mazo*);
	virtual string toString() = 0;
	string getEstado();
	void setEstado(string);

};

#endif
