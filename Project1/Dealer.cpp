#include "Dealer.h"

Dealer::Dealer(string nickname, Mano* mano) {
	this->nickname = nickname;
	this->mano = mano;
}
Dealer::~Dealer() {

}
//Carta* Dealer::pedirCarta() {
//
//}
void Dealer::volteaSegunda() {

}

string Dealer::toString() {
	stringstream s;
	s << "============= DEALER =============" << endl;
	s << "\nMano: " << endl << mano->toString() << endl;
	return s.str();
}