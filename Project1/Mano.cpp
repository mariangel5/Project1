#include "Mano.h"

Mano::Mano() {
	tam = 10;
	can = 0;
	cartas = new Carta * [tam];
	for (int i = 0; i < tam; i++) {
		cartas[i] = nullptr;
	}
}

Mano::~Mano() {
	for (int i = 0; i < can; i++) {
		delete cartas[i];
	}
	delete[] cartas;
}

void Mano::agregarCarta(Mazo* ca) { //Se añade una carta del mazo a la mano del jugador
	if (can < tam) {
		cartas[can++] = ca->tomarCarta();
	}
}

void Mano::limpiar() { //limpia la mano para un nuevo juego
	for (int i = 0; i < can; i++) {
		if (cartas[i] != nullptr) {
			cartas[i] = nullptr;
		}
	}
}

string Mano::toString() {
	stringstream s;
	for (int i = 0; i < can; i++) {
		if (cartas[i] != nullptr) {
			s << cartas[i]->toString() << endl;
		}

	}
	return s.str();
}

bool Mano::buscarAs() {
	for (int i = 0; i < can; i++) {
		if (cartas[i]->getValor() == "A") {
			return true;
		}
	}
	return false;

}

int Mano::getPuntos() {
	int totPun = 0;
	for (int i = 0; i < can; i++) {
		totPun = totPun + cartas[i]->stringToInt(cartas[i]->getValor()); //...
	}
	return totPun;
}

