#ifndef JUGADOR_H
#define JUGADOR_H

#include "JugadorGenerico.h"

class Jugador: public JugadorGenerico {

public:
	Jugador(string, Mano*);
	~Jugador();
	//Carta* pedirCarta();
	string toString();
};
#endif
