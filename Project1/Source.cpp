#include <iostream>
#include <sstream>
#include <string>
#include "Mazo.h"
using namespace std;


int main() {
	Mazo d;
	d.inicializar();
	cout << d.toString();

	return 0;
}

