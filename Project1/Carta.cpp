#include "Carta.h"

Carta::Carta() {
	valor = "0";
	palo = "Indefinido";
	bocaAbajo = 0;
} 

Carta::Carta(string val, string pal) : valor(val), palo(pal) {
	bocaAbajo = 0;

}
	
Carta::~Carta() {}

void Carta::setPalo(string pal) {
	palo = pal;
}

void Carta::setValor(string val) {
	valor = val;
}

void Carta::setBocaAbajo(bool bocA) {
	bocaAbajo = bocA;
}

string Carta::getPalo() {
	return palo;
}

string Carta::getValor() {
	return valor;
}

bool Carta::getBocaAbajo() {
	return bocaAbajo;
}

void Carta::voltear() { //Voltea la carta que este boca abajo
	if (bocaAbajo == 0) {
		setBocaAbajo(1);
	}
	else setBocaAbajo(0);
}

string Carta::toString() {
	stringstream s;
	if (bocaAbajo == 1) { 
		s << "-------------- " << endl;
		s << endl;
		s << endl;
		s << endl;
		s << "   ********   " << endl;
		s << endl;
		s << endl;
		s << endl;
		s << "-------------- " << endl;
	}
	else {
		s << "-------------- " << endl;
		s << valor << endl;
		s << endl;
		s << endl;
		s << "   "<<palo<<"  " << endl;
		s << endl;
		s << endl;
		s << "             " << valor << endl;
		s << "-------------- " << endl;
	}
	return s.str();
}

int Carta::stringToInt(string v) { //Convierte los valores de la carta a Int
	int x = 0;
	if (v == "A") { return x = 1; }
	else if (v == "1") { return x = 1; }
	else if (v == "2") { return x = 2; }
	else if (v == "3") { return x = 3; }
	else if (v == "4") { return x = 4; }
	else if (v == "5") { return x = 5; }
	else if (v == "6") { return x = 6; }
	else if (v == "7") { return x = 7; }
	else if (v == "8") { return x = 8; }
	else if (v == "9") { return x = 9; }
	else if (v == "10") { return x = 10; }
	else if (v == "J") { return x = 10; }
	else if (v == "Q") { return x = 10; }
	else if (v == "K") { return x = 10; }
	return x;
}