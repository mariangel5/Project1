#include "Jugador.h"

Jugador::Jugador(string nickname, Mano* mano) {
	this->nickname = nickname;
	this->mano = mano;
}
Jugador::~Jugador() {

}
//Carta* Jugador::pedirCarta() {
//
//}

string Jugador::toString() {
	stringstream s; 
	s << "\t============Datos de Jugador============" << endl;
	s << "Nickname: " << nickname << endl;
	s << "Mano: " << endl << mano->toString() << endl;
	return s.str();
}