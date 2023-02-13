#include "Jugador.h"

Jugador::Jugador(std::string nickname, Mano* mano) {
	this->nickname = nickname;
	this->mano = mano;
	numJug = 0;
}
Jugador::~Jugador() {

}


std::string Jugador::toString() {
	std::stringstream s; 
	s << "============ " << nickname << " ============" << std::endl;
	s << "\n" << mano->toString() << std::endl;
	return s.str();
}
