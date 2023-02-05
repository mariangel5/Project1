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
	s << "=============================";
	s << "Nombre: " << nickname << endl;
	s << "Mano: " << mano->toString() << endl;
	return s.str();
}