#pragma once
#include "Jugador.h" 
#include "Dealer.h"

class Nodo { //preguntar si se puede dejar en public todo 
public:
	/*Nodo();*/
	Nodo(JugadorGenerico*, Nodo*);
	~Nodo();
	Nodo* getNext();
	JugadorGenerico* getJugador();
	void setNext(Nodo*);
	string toString();

/*private:*/ 
	Nodo* next;
	JugadorGenerico* dato; 
};

