#include <iostream>
#include <sstream>
#include <string>
#include "Mazo.h"
using namespace std;


int main() {
	Mazo d;
	d.inicializar();
	cout << d.toString();
	system("PAUSE");
	system("CLS");

	cout<< d.tomarCarta()->toString();
	//d.barajar();
	//cout<<d.toString();

	//Carta* c = new Carta("A", "Diamantes");
	//c->setBocaAbajo(0);
	//cout<<c->toString();

	return 0;
}

