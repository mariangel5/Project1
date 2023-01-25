#include "JugadorGenerico.h"

JugadorGenerico::JugadorGenerico() {
	nickname = "default";
	mano = NULL;
}

JugadorGenerico::JugadorGenerico(string nickname,Mano* mano) {
	this->nickname = nickname;
	this->mano = mano;
}
JugadorGenerico::~JugadorGenerico() {

}
void JugadorGenerico::setNickname(string nickname){
	this->nickname = nickname;
}

string  JugadorGenerico::getNickname() {
	return nickname;
}

void JugadorGenerico::setMano(Mano* mano) {
	this->mano = mano;
}

Mano* JugadorGenerico::getMano() {
	return mano;
}

//Carta* JugadorGenerico::pedirCarta() {
//
//}
//bool JugadorGenerico::sePaso() {
//
//}