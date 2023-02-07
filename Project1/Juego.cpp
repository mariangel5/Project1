#include "Juego.h"

void Juego::juegoNuevo() {
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
	
	for (int i = 0; i < numJug; i++) {
		cout << i+1 << ". Digite su nickname: ";
		cin >> nomb;
		Mano* manJ = new Mano();
		JugadorGenerico* j1 = new Jugador(nomb, manJ);
		jugadores->insertarFinal(j1);
		system("CLS");

		mazo->inicializar();
		mazo->barajar();
		
	}
	

}

