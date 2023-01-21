#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#pragma once
class Carta
{
public:
	Carta();
	Carta(int, string);
	~Carta();
	void setValor(int);
	void setPalo(string);
	void setBocaAbajo(bool);
	int getValor();
	string getPalo();
	bool getBocaAbajo();
	void voltear();
	string toString();

private:
	int valor;
	string palo;
	bool bocaAbajo;
};

