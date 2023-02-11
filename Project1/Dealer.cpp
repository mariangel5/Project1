#include "Dealer.h"

Dealer::Dealer(string nickname, Mano* mano) {
	this->nickname = nickname;
	this->mano = mano;
}
Dealer::~Dealer() {

}

void Dealer::volteaSegunda() {

}

string Dealer::toString() {
	stringstream s;
	s << "============= DEALER =============" << endl;
	//s << "\nMano: " << endl
	s << "\n" << mano->toString() << endl;
	return s.str();
}