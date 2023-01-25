#include "Nodo.h"


Nodo::Nodo(JugadorGenerico* jugadorG, Nodo* sig= nullptr): dato(jugadorG), next(sig) {}

Nodo::~Nodo(){
	if (dato != nullptr) {
		delete dato;
	}
}

Nodo* Nodo::getNext(){
	return next; 
}

JugadorGenerico* Nodo::getJugador() {
	return dato; 
}

void Nodo::setNext(Nodo* sig) { 
	next = sig; 
}

string Nodo::toString() {//imprime la informacion contenida en el nodo
	return dato->toString(); //da error en el toString porque es necesario que se haya hecho ese metodo en el jugador

}