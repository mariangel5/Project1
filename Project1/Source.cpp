#include <iostream>
#include <sstream>
#include <string>

#include "Juego.h"
//using namespace std;


int main() {

	//Carta* c = new Carta("A", "Cora");
	//c->toString();
	//cout<< c->stringToInt(c->getValor());

	////Mazo* k = new Mazo();
	////k->inicializar();
	////k->barajar();
	////Mano* d = new Mano();
	////JugadorGenerico* g = new Jugador("Luis", d);
	////Lista l;
	////l.insertarFinal(g);
	////d->agregarCarta(k);
	////d->agregarCarta(k);
	////cout<< d->getPuntos();
	////cout<< l.toString();
	//cout << d->toString();
	//system("PAUSE");
	//system("CLS");
	
	//d.barajar();
	//cout<<d.toString();

	//Juego g;
	//g.juegoNuevo();


	//Mano a;
	//a.agregarCarta(d);
	//a.agregarCarta(d->getCarta("6", "Treboles"));
	//a.agregarCarta(d->getCarta("6", "Corazones"));
	//a.agregarCarta(d->getCarta("2", "Diamantes"));
	//a.agregarCarta(d->getCarta("A", "Diamantes"));
	//cout << a.toString();
	//cout<< a.getPuntos();
//	cout << a.buscarA();
	
	//system("PAUSE");
	//system("CLS");
	//a.limpiar();
	//cout<< a.toString();
	
	int op, opcion; 
	bool error = false;
	bool validar, otraVez;

	std::cout << "|--------------------------------------------------|\n";
	std::cout << "|     Le damos la bienvenida al juego BlackJack    |\n";
	std::cout << "|--------------------------------------------------|" << std::endl << endl;


	std::cout << "--------M E N U--------" << endl; 
	std::cout << "[1]- Juego Nuevo" << std::endl; 
	std::cout << "[2]- Cargar Partida" << std::endl;
	std::cout << "[3]- Salir" << std::endl << endl;
	std::cout << "Digite una opcion: " << std::endl << endl;
	std::cin >> op; 
	if ((op > 3|| op < 0) || cin.fail()) {
		error = true;
		cin.clear();
		cin.ignore(50, '\n');
		system("pause");
		std::cout << "Por favor digite una opcion valida: " << std::endl;
		std::cin >> op; 
	}
	system("CLS");
	switch (op)
	{
	case 1: 
		std::cout << "----------------------------------------\n";
		std::cout << " Ha seleccionado iniciar un Juego Nuevo \n";
		std::cout << "----------------------------------------\n";
		system("pause");
		Juego g;
		g.juegoNuevo();
		break; 
	case 2: 
		std::cout << "----------------------------------------\n";
		std::cout << "    Ha seleccionado Cargar Partida      \n";
		std::cout << "----------------------------------------\n";
		system("pause");
		break; 
	default:
		std::cout << "---------------------------------------------------\n";
		std::cout << "     Esta saliendo del menu, gracias por jugar     \n";
		std::cout << "---------------------------------------------------\n";
		break;
		system("CLS"); 
	}
	do {//Validación
		cout << "---------------------------------------------------\n";
		cout << "   ¿Desea  volver al menu y realizar otra accion  ?\n";
		cout << "---------------------------------------------------\n";
		cout << "Digite 1 para sí.\n";
		cout << "Digite 0 para no.\n";
		cout << "Opcion: ";
		cin >> opcion;
		system("CLS");
		if ((opcion == 1) || (opcion == 0)) {
			if (opcion == 1) {
				otraVez = true;
			}
			else {
				otraVez = false;
			}
			validar = true;
		}
		else {
			cout << "ERROR! Ha digitado una opción incorrecta, por favor vuelva a intentar...\n";
			validar = false;
		}
	} while (!validar);


	return 0;
}

