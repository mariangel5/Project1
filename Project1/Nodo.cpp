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

string Nodo::toString() {//imprime la informacion contenida en el nodo
	stringstream s; //toString Temporal
	s << "Datos: " << endl;
	s << dato << endl;
	return s.str();

}