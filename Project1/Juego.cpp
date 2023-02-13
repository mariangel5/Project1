#include "Juego.h"

void Juego::iniciaNuevoJuego() {
	system("CLS");
	Lista* jugadores = new Lista();
	Mazo* mazo = new Mazo();
	Mano* manoD = new Mano();
	Dealer* dealer = new Dealer("Dealer", manoD);
	int numJug = 0;
	std::string nomb;
	int num = 0;
	bool error;
	

	do {//Se hace un ciclo que pregunte al usuario el numero de jugadores a participar
		error = false; 
		std::cout << "\t-------------------------------------------------\n";
		std::cout << "\t         Digite el numero de jugadores           \n";
		std::cout << "\t             (Minimo 1 - Maximo 7)               \n";
		std::cout << "\t-------------------------------------------------" << std::endl << std::endl;
		std::cin >> numJug;
		std::cout << std::endl << std::endl;
		if ((numJug > 7) || (0 >= numJug) || (std::cin.fail())) {//Comprueba si hay fallos cuando se digita un valor no valido y vuelve a preguntar por el dato
			system("CLS");
			std::cin.clear();
			std::cin.ignore(50, '\n');
			error = true; 
			std::cout << "\t|--------------------------------------------------|\n";
			std::cout << "\t|       Por favor digite una cantidad valida       |\n";
			std::cout << "\t|--------------------------------------------------|\n" << std::endl << std::endl;
			
		}
	} while (error);
	
		mazo->inicializar();
		mazo->barajar();

	for (int i = 0; i < numJug; i++) { 
		std::cout << "\t=======JUGADOR " << i + 1 << "======= \n";
		std::cout << "\t-----------------------" << std::endl << std::endl;
		std::cout<< "Digite su nickname: ";	std::cin >> nomb;	//Le pregunta el nickname a cada jugador
		std::cout << std::endl << std::endl;
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
	
	std::cout << jugadores->toString() << std::endl << std::endl;
	std::cout << dealer->toString() << std::endl;
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
				std::cout << "\t---------------------------------------------------\n";
				std::cout << "\t     Esta saliendo del menu, gracias por jugar     \n";
				std::cout << "\t---------------------------------------------------\n";
				break;
			}
			else {
				while (endTurno == false && partidaOn == true) {
					std::cout << "--Turno del jugador numero " << lis->getJugador(i)->getNumJug()+1 << "--" << std::endl;
					std::cout << "\n" << lis->getJugador(i)->toString() << std::endl;
					std::cout << "\t---------------------------------------------------\n";
					std::cout << "\t             Los puntos obtenidos son:             \n";
					std::cout << lis->getJugador(i)->getMano()->getPuntos() << std::endl;
					std::cout << lis->getJugador(i)->getMano()->getPuntos() << std::endl;
					std::cout << "\t---------------------------------------------------\n";
					system("PAUSE");
					system("CLS");

					if (lis->getJugador(i)->getMano()->getPuntos() > 21) {
						std::cout << "\t---------------------------------------------------\n";
						std::cout << "\t                     HAS PERDIDO                   \n";
						std::cout << "\t                Mas suerte la proxima!             \n" << std::endl;
						std::cout << "\t---------------------------------------------------\n";
						lis->getJugador(i)->setEstado("Perdedor");
						system("PAUSE");
						system("CLS");
						opc = 'P';
					}
					else {
						do {
							menuJuego();
							std::cin >> opc;
							system("CLS");
						} while (opc != 'D' && opc != 'P' && opc != 'G' && opc != 'S'); //Comprueba que solo se pueda ingresar las letras del menu

					}switch (opc) {
					case 'D': {
						lis->getJugador(i)->pedirCarta(mazo);
						break;
					}
					case 'P': {
						std::cout << "Siguiente jugador..." << std::endl;
						Sleep(600);
						endTurno = true;
						break;
					}
					case 'G': {		
						break;
					}
					case 'S': {
						std::cout << "----------------------------------------\n";
						std::cout << "          El juego ha terminado         \n";
						std::cout << "----------------------------------------\n";
						partidaOn = false;
						endTurno = true;
						break;
					}
					default:
						std::cout << "Opcion no valida";
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
		std::cout << "\t----------------------------------------\n" << std::endl;
		std::cout << " (D)eme carta - (P)asar - (G)uardar Partida - (S)alir" << std::endl << std::endl;
}

void Juego::comprobarGanador(bool part, Mazo* ma, Lista* li, Dealer* de) {
	static int cant = li->cuentaNodos();
	if (part == true) { //Comprueba que no se haya terminado el juego
		std::cout << "\t--Turno del Dealer--" << std::endl;
		de->volteaSegunda(); 
		std::cout << "\n" << de->toString() << std::endl; // Se muestra la segunda carta del dealer
		std::cout << "Los puntos obtenidos son : " << de->getMano()->getPuntos() << std::endl;
		system("PAUSE");
		system("CLS");

		if (li->getInicio() == nullptr) { //En caso de que no quedaran jugadores, la casa gana por default
			std::cout << "La casa ha ganado ya que no hay jugadores disponibles" << std::endl;
			std::cout << "F I N   D E L   J U E G O " << std::endl;
		}
		else {
			JugadorGenerico* jugAux = li->getInicio()->dato;
			while (de->getMano()->getPuntos() < 16) { //Se le añade una carta si la suma es menor de 16 puntos
				de->getMano()->agregarCarta(ma);
				std::cout << de->toString() << std::endl << std::endl;
				std::cout << "Los puntos obtenidos son : " << de->getMano()->getPuntos() << std::endl;
				system("PAUSE");
			}
			if (de->getMano()->getPuntos() <= 21) { //En caso de que el dealer no se pase de 21 se comparara con cada jugador
				for (int i = 0; i < cant; i++) {
					if (li->getJugador(i)->getMano()->getPuntos() < de->getMano()->getPuntos() || li->getJugador(i)->getMano()->getPuntos() > 21) {
						li->getJugador(i)->setEstado("Perdedor");
					}
					else if (li->getJugador(i)->getMano()->getPuntos() > de->getMano()->getPuntos()) {
						li->getJugador(i)->setEstado("Ganador"); // se les asigna el estado
					}
					else {
						li->getJugador(i)->setEstado("Empate");
					}
				}
				li->mostrarResultados(); //mostrara el resultado del juego
			}
			else {
				system("CLS");
				std::cout << "La casa ha perdido..." << std::endl << std::endl;
				std::cout << "============== G A N A D O R E S ==============" << std::endl << std::endl;
				li->mostrarGanadores(); //muestra todos los jugadores que no se pasaron de 21
			}
		}
	}
}
