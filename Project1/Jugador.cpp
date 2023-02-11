#include "Jugador.h"
#include "Mano.h"

Jugador::Jugador(string nickname, Mano* mano) {
	this->nickname = nickname;
	this->mano = mano;
}
Jugador::~Jugador() {

}
void Jugador::pedirCarta(int num,Mazo* ca) {
	if (num == 1) {
		mano->agregarCarta(ca);
		cout << "La carta se ha añadido a su mano";
	}else 
		cout << "No se añade ninguna carta a su mano";
}

string Jugador::toString() {
	stringstream s; 
	s << "============ " << nickname << " ============" << endl;
	//s << "-Mano: " << endl 
	s << "\n" << mano->toString() << endl;
	return s.str();
}