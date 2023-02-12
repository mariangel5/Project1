#include "Juego.h"

void Juego::iniciaNuevoJuego() {
	system("CLS");
	Lista* jugadores = new Lista();
	Mazo* mazo = new Mazo();
	Mano* manoD = new Mano();
	Dealer* dealer = new Dealer("Dealer", manoD);
	int numJug = 0;
	string nomb;
	int num = 0;
	bool error;
	

	do {//Se hace un ciclo que pregunte al usuario el numero de jugadores a participar
		error = false; 
		cout << "Digite la cantidad de jugadores (Minimo 1 - Maximo 7): "; cin >> numJug;
		cout << endl << endl;
		if ((numJug > 7) || (0 >= numJug) || (cin.fail())) {//Comprueba si hay fallos cuando se digita un valor no valido y vuelve a preguntar por el dato
			system("CLS");
			cin.clear();
			cin.ignore(50, '\n');
			error = true; 
			cout << "--Digite una cantidad valida--" << endl << endl;
		}
	} while (error);
	
		mazo->inicializar();
		mazo->barajar();

	for (int i = 0; i < numJug; i++) { 
		cout << "=======JUGADOR "<< i + 1 << "======= "  << endl;
		cout<< "Digite su nickname: ";	cin >> nomb;	//Le pregunta el nickname a cada jugador
		cout << endl << endl;
		Mano* manJ = new Mano();
		JugadorGenerico* j1 = new Jugador(nomb, manJ);
		j1->setNumJug(num);
		num++;
		jugadores->insertarFinal(j1);
		manJ->agregarCarta(mazo);			//Agrega las dos cartas necesarias al jugador
		manJ->agregarCarta(mazo);
	}

	system("CLS");

	manoD->agregarCarta(mazo);
	manoD->agregarCarta(mazo);					//Agrega las cartas al dealer
	dealer->getMano()->getCarta(1)->voltear();	// Le da vuelta a una de las cartas para que no se muestre su valor
	
	cout << jugadores->toString() << endl << endl;
	cout << dealer->toString() << endl;
	system("PAUSE");
	system("CLS");

	iniciarPartidas(mazo, jugadores, dealer);
}

void Juego::iniciarPartidas(Mazo* mazo, Lista* lis, Dealer* dea) {
	char opc;
	bool partidaOn = true; 
	bool endTurno;
	static int cantJugadores = lis->cuentaNodos();
	if (partidaOn == true) {
		for (int i = 0; i < cantJugadores; i++) {
			endTurno = false;
			if (cantJugadores == 0) {
				cout << "No es posible iniciar el juego";
				break;
			}
			else {
				while (endTurno == false) {
					cout << "--Turno del jugador numero " << lis->getJugador(i)->getNumJug() << "--" << endl;
					cout << "\n" << lis->getJugador(i)->toString() << endl;
					cout << "Los puntos obtenidos son: " << lis->getJugador(i)->getMano()->getPuntos() << endl;
					system("PAUSE");
					system("CLS");

					if (lis->getJugador(i)->getMano()->getPuntos() > 21) {
						cout << "HAS PERDIDO... " << endl;
						cout << "Mas suerte la proxima!" << endl;
						lis->borrarJug(i);
						system("PAUSE");
						opc = 'P';
					}
					else {
						do {
							menuJuego();
							cin >> opc;
							system("CLS");
						} while (opc != 'D' && opc != 'P' && opc != 'G' && opc != 'S'); //Comprueba que solo se pueda ingresar las letras del menu

					}switch (opc) {
					case 'D': {
						lis->getJugador(i)->pedirCarta(mazo);
						break;
					}
					case 'P': {
						cout << "Siguiente jugador..." << endl;
						Sleep(600);
						endTurno = true;
						break;
					}
					case 'G': {		
						break;
					}
					case 'S': {
						cout << "El juego ha terminado..." << endl << endl;
						partidaOn = false;
						endTurno = true;
						break;
					}
					default:
						cout << "Opcion no valida";
						break;
					}
				}
			}
		}
	}
	comprobarGanador(partidaOn, mazo, lis, dea);
}

void Juego::menuJuego() {
		std::cout << "\t----------------------------------------\n";
		std::cout << "\t        M E N U  J U G A D O R         \n";
		std::cout << "\t----------------------------------------\n" << endl;
		cout << " (D)eme carta - (P)asar - (G)uardar Partida - (S)alir" << endl << endl;
}

void Juego::comprobarGanador(bool part, Mazo* ma, Lista* li, Dealer* de) {
	if (part == true) { //Comprueba que no se haya terminado el juego
		cout << "\t--Turno del Dealer--" << endl;
		de->volteaSegunda(); 
		cout << "\n" << de->toString() << endl; // Se muestra la segunda carta del dealer
		cout << "Los puntos obtenidos son : " << de->getMano()->getPuntos() << endl;
		system("PAUSE");
		system("CLS");

		if (li->getInicio() == nullptr) { //En caso de que no quedaran jugadores, la casa gana por default
			cout << "La casa ha ganado ya que no hay jugadores disponibles" << endl;
			cout << "F I N   D E L   J U E G O " << endl;
		}
		else {
			JugadorGenerico* jugAux = li->getInicio()->dato;
			while (de->getMano()->getPuntos() < 16) { //Se le añade una carta si la suma es menor de 16 puntos
				de->getMano()->agregarCarta(ma);
				cout << de->toString() << endl << endl;
				cout << "Los puntos obtenidos son : " << de->getMano()->getPuntos() << endl;
				system("PAUSE");
			}
			if (de->getMano()->getPuntos() <= 21) { //En caso de que el dealer no se pase de 21 se comparara con cada jugador
				for (int i = 0; i < li->cuentaNodos(); i++) {
					if (li->getJugador(i)->getMano()->getPuntos() > de->getMano()->getPuntos()) {
						li->getJugador(i)->setEstado("Ganador"); // se les asigna el estado
					}
					else if (li->getJugador(i)->getMano()->getPuntos() < de->getMano()->getPuntos()) {
						li->getJugador(i)->setEstado("Perdedor");

					}
					else {
						li->getJugador(i)->setEstado("Empate");
					}
				}
				li->mostrarResultados(); //mostrara el resultado del juego
			}
			else {
				system("CLS");
				cout << "La casa ha perdido..." << endl << endl;
				cout << "============== G A N A D O R E S ==============" << endl << endl;
				cout << li->toString() << endl << endl; //muestra todos los jugadores que no se pasaron de 21
			}
		}
	}
}
