#include "Jugador.h"
#include "Mano.h"

Jugador::Jugador(string nickname, Mano* mano) {
	this->nickname = nickname;
	this->mano = mano;
	numJug = 0;
}
Jugador::~Jugador() {

}
//Carta* Jugador::pedirCarta() {
//
//}

string Jugador::toString() {
	stringstream s; 
	s << "============ " << nickname << " ============" << endl;
	//s << "-Mano: " << endl 
	s << "\n" << mano->toString() << endl;
	return s.str();
}