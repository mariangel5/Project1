#include "Mazo.h"

Mazo::Mazo() {
	cant = 0;
	mazo = new Carta * [CARTAS]; 
	for (int i = 0; i < CARTAS; i++) {
		mazo[i] = nullptr;
	}
}

Mazo::~Mazo() {

	for (int i = 0; i < cant; i++) {
		delete mazo[i];
		delete[] mazo;
	}
}

void Mazo::inicializar() {
	Carta* aux = nullptr;
	string numeros[NUMEROS] = { "A","2","3","4","5","6","7","8","9","10","J", "Q", "K" };
	string palos[PALOS] = { "Espadas", "Corazones","Diamantes", "Treboles" };
	for (int j = 0; j < PALOS; j++) {
		for (int i = 0; i < NUMEROS; i++) {
			aux = new Carta(numeros[i], palos[j]);
			if (mazo[NUMEROS*j+i] == nullptr) { //Se guardan las cartas en el vector
				mazo[NUMEROS * j + i] = aux;
				cant = 0;
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
	Carta* aux = nullptr;
	int indice = 0, j=0;
	for (int i = 0; i < CARTAS; i++) {
		j = i;
		indice = int(rand() / (float)RAND_MAX * (CARTAS - i)) + j; //Se crea un auxiliar para ir moviendo las cartas a un numero random
		aux = mazo[i];
		mazo[i] = mazo[indice];
		mazo[indice] = aux;
	}
	return;
}

Carta* Mazo::tomarCarta() { //Metodo regresar ultima carta del mazo
	Carta* aux = nullptr; //Se puede modificar
	for (int i = CARTAS-1; i >= 0; i--) {
		if (mazo[i] != nullptr) {
			aux = mazo[i];
			mazo[i] = nullptr;
			i = -2;
		}
	}
	return aux;

}