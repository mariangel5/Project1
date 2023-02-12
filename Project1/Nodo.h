#pragma once
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
	string toString();
};

