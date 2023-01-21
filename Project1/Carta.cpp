#include "Carta.h"

Carta::Carta() {
	valor = 0;
	palo = "Indefinido";
	bocaAbajo = 0;
} 

Carta::Carta(int val, string pal) : valor(val), palo(pal) {
	bocaAbajo = 0;
}
	
Carta::~Carta() {}

void Carta::setPalo(string pal) {
	palo = pal;
}

void Carta::setValor(int val) {
	valor = val;
}

void Carta::setBocaAbajo(bool bocA) {
	bocaAbajo = bocA;
}

string Carta::getPalo() {
	return palo;
}

int Carta::getValor() {
	return valor;
}

bool Carta::getBocaAbajo() {
	return bocaAbajo;
}

void Carta::voltear() { //Si la carta esta boca abajo le da vuelta para mostrar los valores de la carta
	if (bocaAbajo == true) {
		bocaAbajo == false;
	}
}

string Carta::toString() {
	stringstream s;
	if (bocaAbajo == true) { 
		s << "-------------- " << endl;
		s << "|            |" << endl;
		s << "|            |" << endl;
		s << "|            |" << endl;
		s << "|  ********  |" << endl;
		s << "|            |" << endl;
		s << "|            |" << endl;
		s << "|            |" << endl;
		s << "-------------- " << endl;
	}
	else {
		s << "-------------- " << endl;
		s << "| A" << "          |" << endl;
		s << "|" << "            |" << endl;
		s << "|" << "            |" << endl;
		s << "|  corazon   |" << endl;
		s << "|" << "            |" << endl;
		s << "|" << "            |" << endl;
		s << "|" << "          A |" << endl;
		s << "-------------- " << endl;
	}
	return s.str();
}