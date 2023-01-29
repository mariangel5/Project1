#include <iostream>
#include <sstream>
#include <string>
#include "Mano.h"
using namespace std;


int main() {

	//Carta* c = new Carta("A", "Cora");
	//c->toString();
	//cout<< c->stringToInt(c->getValor());

	Mazo* d = new Mazo();
	d->inicializar();
	d->barajar();
	cout << d->toString();
	system("PAUSE");
	system("CLS");
	
	//d.barajar();
	//cout<<d.toString();



	Mano a;
	a.agregarCarta(d);
	//a.agregarCarta(d);

	cout << a.toString();
	cout << a.getPuntos();
	//system("PAUSE");
	//system("CLS");
	//a.limpiar();
	//cout<< a.toString();
	
	





	return 0;
}

