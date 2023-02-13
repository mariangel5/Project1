#ifndef JUGADORGENERICO_H
#define JUGADORGENERICO_H
#include <string>
#include "Mano.h"
#include <Windows.h>

class JugadorGenerico
{
protected:
	std::string nickname;
	Mano* mano;
	int numJug;
	std::string estado;

public:
	JugadorGenerico();
	virtual ~JugadorGenerico();
	void setNumJug(int);
	int getNumJug();
	JugadorGenerico(std::string, Mano*);
	void setNickname(std::string);
	std::string getNickname();
	void setMano(Mano*);
	Mano* getMano();
	void pedirCarta(Mazo*);
	virtual std::string toString() = 0;
	std::string getEstado();
	void setEstado(std::string);

};
#endif
