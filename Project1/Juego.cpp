#include "Juego.h"

void Juego::juegoNuevo() {
	system("CLS");
	bool sePuede = true;
	bool turno = true;
	Lista* jugadores = new Lista();
	Mazo* mazo = new Mazo();
	Mano* manoD = new Mano();
	Dealer* dealer = new Dealer("Dealer", manoD);
	int numJug = 0;
	string nomb;
	

	do {
		cout << "Digite la cantidad de jugadores (Minimo 1 y Maximo 7): ";
		cin >> numJug;
		system("CLS");
		if (cin.fail()) { //Comprueba si hay fallos cuando se digita un valor no valido y vuelve a preguntar por el dato
			cout << "\nDigite una cantidad valida" << endl;
			system("PAUSE");
			cin.clear();
			cin.ignore();
		}
	} while (numJug > 7 || 0 >= numJug);
	
		mazo->inicializar();
		mazo->barajar();

	for (int i = 0; i < numJug; i++) {
		cout << "=======JUGADOR "<< i + 1 << "======= "  << endl;
		cout<< "Digite su nickname: ";
		cin >> nomb;
		Mano* manJ = new Mano();
		JugadorGenerico* j1 = new Jugador(nomb, manJ);
		jugadores->insertarFinal(j1);
		system("CLS");
		manJ->agregarCarta(mazo);
		manJ->agregarCarta(mazo);
	}
	manoD->agregarCarta(mazo);
	manoD->agregarCarta(mazo);
	dealer->volteaSegunda();

	system("PAUSE");
	cout<< jugadores->toString();
		

}

