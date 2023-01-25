#include "Mazo.h"

Mazo::Mazo() {
	cant = 0;
	mazo = new Carta * [NUMEROS]; 
	for (int i = 0; i < NUMEROS; i++) {
		mazo[i] = NULL;
	}
}

Mazo::~Mazo() {

	for (int i = 0; i < cant; i++) {
		delete mazo[i];
		delete[] mazo;
	}
}

void Mazo::inicializar() {
	Carta* aux = NULL;
	string numeros[NUMEROS] = { "A","2","3","4","5","6","7","8","9","10","J", "Q", "K" };
	string palos[PALOS] = { "Espadas", "Corazones","Diamantes", "Treboles" };
	for (int i = 0; i < NUMEROS; i++) {
		for (int j = 0; j < PALOS; j++) {
			aux = new Carta(numeros[i], palos[j]);
			if (mazo[i] == NULL) {
				mazo[i] = aux;
			}
		}
	}
}

string Mazo::toString() {
	stringstream s;
	for (int i = 0; i < NUMEROS; i++) {
		if(mazo[i] != nullptr)
		s <<i<< mazo[i]->toString() << endl;
	}
	return s.str();
}