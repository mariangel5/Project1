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
	}
	delete[] mazo;
}

void Mazo::inicializar() {
	Carta* aux = nullptr;
	std::string numeros[NUMEROS] = { "A","2","3","4","5","6","7","8","9","10","J", "Q", "K" };
	std::string palos[PALOS] = { "Espadas", "Corazones","Diamantes", "Treboles" };
	for (int j = 0; j < PALOS; j++) {
		for (int i = 0; i < NUMEROS; i++) {
			aux = new Carta(numeros[i], palos[j]);
			if (mazo[NUMEROS*j+i] == nullptr) { //Se guardan las cartas en el vector
				mazo[NUMEROS * j + i] = aux;
				cant++;
			}
		}
	}
}

std::string Mazo::toString() {
	std::stringstream s;
	for (int i = 0; i < cant; i++) {
		if (mazo[i] != nullptr) {
			s << i+1<< mazo[i]->toString() << std::endl;
		}

	}
	return s.str();
}

void Mazo::barajar() {
	srand(unsigned(std::time(0)));
	std::random_shuffle(&mazo[0], &mazo[CARTAS]); //metodo de libreria de c++ para barajar
}

Carta* Mazo::tomarCarta() { //Metodo regresar ultima carta del mazo
	Carta* aux = nullptr; //Se puede modificar
	for (int i = CARTAS-1; i >= 0; i--) {
		if (mazo[i] != nullptr) {
			aux = mazo[i];
			mazo[i] = nullptr;
			cant--;
			i = -2;   
		}
	}
	return aux;

}


Carta* Mazo::getCarta(std::string n, std::string p) {
	for (int i = 0; i < cant; i++) {
		if (mazo[i]->getValor() == n && mazo[i]->getPalo() == p) {
			return mazo[i];
		}
	}
	return nullptr;
}

void Mazo::guardarMazo(std::ofstream& partida) {
	partida << cant << "&";
	for (int i = 0; i < cant; i++) {
		if (mazo[i + 1] == mazo[CARTAS - 1]) {
			mazo[i]->guardarCarta(partida);
			partida << "\n";
		}
		else {
			mazo[i]->guardarCarta(partida);
			partida << "|";
		}
	}
}

void Mazo::agregarCarta(Carta* ca) { //Se a?ade una carta al mazo
	if (cant < CARTAS) {
		mazo[cant++] = ca;
	}
}