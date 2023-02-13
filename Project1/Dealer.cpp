#include "Dealer.h"

Dealer::Dealer(std::string nickname, Mano* mano) {
	this->nickname = nickname;
	this->mano = mano;
}

Dealer::~Dealer() {

}

void Dealer::volteaSegunda() {
	if (mano->getCarta(1) != nullptr && mano->getCarta(1)->getBocaAbajo() == 1) {
			mano->getCarta(1)->setBocaAbajo(0);
	}
}

std::string Dealer::toString() {
	std::stringstream s;
	s << "============= DEALER =============" << std::endl;
	//s << "\nMano: " << endl
	s << "\n" << mano->toString() << std::endl;
	return s.str();
}