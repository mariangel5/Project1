#include "Dealer.h"

Dealer::Dealer(string nickname, Mano* mano) {
	this->nickname = nickname;
	this->mano = mano;
}
Dealer::~Dealer() {

}

void Dealer::pedirCarta(int num, Mazo* ca) {
	if (num == 1) {
		mano->agregarCarta(ca);
		cout << "La carta se ha añadido a su mano";
	}
	else
		cout << "No se añade ninguna carta a su mano";
}

void Dealer::volteaSegunda() {
	if (mano->getCarta(1) != nullptr) {
		if (mano->getCarta(1)->getBocaAbajo() == 1) {
			mano->getCarta(1)->setBocaAbajo(0);
		}
	}
}

string Dealer::toString() {
	stringstream s;
	s << "============= DEALER =============" << endl;
	//s << "\nMano: " << endl
	s << "\n" << mano->toString() << endl;
	return s.str();
}