#include "Mazo.h"

Mazo::Mazo() {
	cant = 0;
	mazo = new Carta * [CARTAS]; 
	for (int i = 0; i < CARTAS; i++) {
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
	for (int j = 0; j < PALOS; j++) {
		for (int i = 0; i < NUMEROS; i++) {
			aux = new Carta(numeros[i], palos[j]);
			if (mazo[NUMEROS*j+i] == NULL) {
				mazo[NUMEROS * j + i] = aux;
			}
		}
	}
}

string Mazo::toString() {
	stringstream s;
	for (int i = 0; i < CARTAS; i++) {
		if (mazo[i] != nullptr) {
			s << i+1<< mazo[i]->toString() << endl;
		}

	}
	return s.str();
}

void Mazo::barajar() {
	Carta* aux = NULL;
	int indice = 0, desp=0;
	for (int i = 0; i < CARTAS; i++) {
		desp = i;
		indice = int(rand() / (float)RAND_MAX * (CARTAS - i)) + desp;
		aux = mazo[i];
		mazo[i] = mazo[indice];
		mazo[indice] = aux;
	}
	return;
}