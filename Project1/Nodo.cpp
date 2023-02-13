#include "Nodo.h"


Nodo::Nodo(JugadorGenerico* jugadorG, Nodo* sig= nullptr): dato(jugadorG), next(sig) {

}

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

std::string Nodo::toString() {//imprime la informacion contenida en el nodo
	std::stringstream s; //toString Temporal
	s << dato->toString() << std::endl;
	return s.str();

}