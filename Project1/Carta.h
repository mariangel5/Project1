#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

#define PALOS    4
#define NUMEROS 13
#define CARTAS  (NUMEROS*PALOS)

#pragma once
class Carta
{
public:
	Carta();
	Carta(string, string);
	~Carta();
	void setValor(string);
	void setPalo(string);
	void setBocaAbajo(bool);
	string getValor();
	string getPalo();
	bool getBocaAbajo();
	int stringToInt(string);
	void voltear();
	string toString();

private:
	string valor;
	string palo;
	bool bocaAbajo;
};

