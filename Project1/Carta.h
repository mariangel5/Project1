#ifndef CARTA_H
#define CARTA_H
#include <iostream>
#include <sstream>
#include <string>
#define PALOS    4
#define NUMEROS 13
#define CARTAS  (NUMEROS*PALOS)


class Carta
{
public:
	Carta();
	Carta(std::string, std::string);
	~Carta();
	void setValor(std::string);
	void setPalo(std::string);
	void setBocaAbajo(bool);
	std::string getValor();
	std::string getPalo();
	bool getBocaAbajo();
	int stringToInt(std::string);
	void voltear();
	std::string toString();

private:
	std::string valor;
	std::string palo;
	bool bocaAbajo;
};
#endif
