#include "Juego.h"

void Juego::iniciaNuevoJuego() {
	system("CLS");
	bool sePuede = true;
	bool turno = true;
	Lista* jugadores = new Lista();
	Mazo* mazo = new Mazo();
	Mano* manoD = new Mano();
	Dealer* dealer = new Dealer("Dealer", manoD);
	int numJug = 0;
	string nomb;
	

	do { //Se hace un ciclo que pregunte al usuario el numero de jugadores a participar
		cout << "Digite la cantidad de jugadores (Minimo 1 y Maximo 7): "; 
		cin >> numJug;
		system("CLS");
		if (cin.fail()) { //Comprueba si hay fallos cuando se digita un valor no valido y vuelve a preguntar por el dato
			cout << "\nDigite una cantidad valida" << endl;
			system("PAUSE");
			cin.clear();
			cin.ignore();
		}
	} while (numJug > 7 || 0 >= numJug); //Valida que no sean mas de 7 y menos de 1
	
		mazo->inicializar();
		mazo->barajar();

	for (int i = 0; i < numJug; i++) { 
		cout << "=======JUGADOR "<< i + 1 << "======= "  << endl;
		cout<< "Digite su nickname: "; //Le pregunta el nickname a cada jugador
		cin >> nomb;
		Mano* manJ = new Mano();
		JugadorGenerico* j1 = new Jugador(nomb, manJ);
		jugadores->insertarFinal(j1);
		manJ->agregarCarta(mazo); //Agrega las dos cartas necesarias al jugador
		manJ->agregarCarta(mazo);
		system("CLS");
	}

	manoD->agregarCarta(mazo);
	manoD->agregarCarta(mazo); //Agrega las cartas al dealer
	dealer->getMano()->getCarta(1)->voltear(); // Le da vuelta a una de las cartas para que no se muestre su valor
	
	iniciarPartidas(mazo, jugadores, dealer);


}

void Juego::iniciarPartidas(Mazo* mazo, Lista* lis, Dealer* dea) {
	bool otraCarta = false;
	int cantJugadores = lis->cuentaNodos();
	if (otraCarta == false) {
		for (int i = 0; i < cantJugadores; i++) {
			if (cantJugadores == 0) {
				cout << "No es posible iniciar el juego";
				break;

			}
			else {
				cout << lis->toString() << endl << endl;
				cout << dea->toString() << endl;
			}
		}
	}
}