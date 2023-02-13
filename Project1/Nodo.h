#ifndef NODO_H
#define NODO_H
#include "Jugador.h" 
#include "Dealer.h"

class Nodo { 
public:
	Nodo* next;
	JugadorGenerico* dato; 
	Nodo(JugadorGenerico*, Nodo*);
	~Nodo();
	Nodo* getNext();
	JugadorGenerico* getJugador();
	void setNext(Nodo*);
	std::string toString();
};
#endif

