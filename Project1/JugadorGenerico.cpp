#include "JugadorGenerico.h"

JugadorGenerico::JugadorGenerico() {
	nickname = "default";
	mano = NULL;
}

JugadorGenerico::JugadorGenerico(std::string nickname,Mano* mano) {
	this->nickname = nickname;
	this->mano = mano;
}
JugadorGenerico::~JugadorGenerico() {

}
void JugadorGenerico::setNickname(std::string nickname){
	this->nickname = nickname;
}

std::string  JugadorGenerico::getNickname() {
	return nickname;
}

void JugadorGenerico::setMano(Mano* mano) {
	this->mano = mano;
}

Mano* JugadorGenerico::getMano() {
	return mano;
}

void JugadorGenerico::setNumJug(int num) {
	numJug = num;
}

int JugadorGenerico::getNumJug() {
	return numJug;
}

void JugadorGenerico::setEstado(std::string es) {
	estado = es;
}

std::string JugadorGenerico::getEstado() {
	return estado;
}

void JugadorGenerico::pedirCarta(Mazo* ca) {
		mano->agregarCarta(ca);
		std::cout << "La carta se ha agregado a su mano..." << std::endl << std::endl;
		Sleep(400);
}
