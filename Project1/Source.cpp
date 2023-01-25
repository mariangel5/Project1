#include <iostream>
#include <sstream>
#include <string>
#include "Mazo.h"
using namespace std;


int main() {
	Mazo x;
	x.inicializar();
	cout<< x.toString();

	return 0;
}

