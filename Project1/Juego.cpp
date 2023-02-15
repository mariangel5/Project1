#include "Juego.h"

void Juego::iniciaNuevoJuego() {
	system("CLS");
	Lista* jugadores = new Lista();
	Mazo* mazo = new Mazo();
	Mano* manoD = new Mano();
	Dealer* dealer = new Dealer("Dealer", manoD);
	int numJug = 0;
	std::string nomb;
	std::string verifiNomb;
	int num = 0;
	bool error;
	int i = 0;


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
		std::cout << "Digite su nickname: ";	std::cin >> nomb;	//Le pregunta el nickname a cada jugador

		for (i = 0; i < jugadores->cuentaNodos(); i++) {     // se verifica que no se repitan los nicknames
			if (nomb == jugadores->getJugador(i)->getNickname()) {
				verifiNomb = nomb;
				while (verifiNomb == nomb) {
					system("CLS");
					std::cout << "Su nickname ya ha sido escojido, por favor inserte otro: ";
					std::cin >> nomb;
				}
			}
		}

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

	iniciarPartidas(mazo, jugadores, dealer, i);
}

void Juego::iniciarPartidas(Mazo* mazo, Lista* lis, Dealer* dea, int i) {
	char opc;
	bool partidaOn = true;
	bool endTurno;
	static int cantJugadores = lis->cuentaNodos();
	if (partidaOn == true) {
		for (i; i < cantJugadores; i++) {
			endTurno = false;
			if (cantJugadores == 0) {
				std::cout << "\t---------------------------------------------------\n";
				std::cout << "\t     Esta saliendo del menu, gracias por jugar     \n";
				std::cout << "\t---------------------------------------------------\n";
				break;
			}
			else {
				while (endTurno == false && partidaOn == true) {
					std::cout << "--Turno del jugador numero " << lis->getJugador(i)->getNumJug() + 1 << "--" << std::endl;
					std::cout << "\n" << lis->getJugador(i)->toString() << std::endl;
					std::cout << "\t---------------------------------------------------\n";
					std::cout << "\t             Los puntos obtenidos son:             \n";
					std::cout << lis->getJugador(i)->getMano()->getPuntos() << std::endl;
					std::cout << "\t---------------------------------------------------\n";
					system("PAUSE");
					system("CLS");

					if (lis->getJugador(i)->getMano()->getPuntos() > 21) {
						std::cout << "\t---------------------------------------------------\n";
						std::cout << "\t                     HAS PERDIDO                   \n";
						std::cout << "\t                Mas suerte la proxima!             \n" << std::endl;
						std::cout << "\t---------------------------------------------------\n";
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
						int guardado;
						do {
							std::cout << "\t--------------------------------------------------------------------------------\n";
							std::cout << "\tTome en cuenta que si guarda ahora se borrara la partida anteriormente guardada" << std::endl;
							std::cout << "\tDesea guardar: 0. Si 1. No: ";
							std::cout << "\t--------------------------------------------------------------------------------\n";
							std::cin >> guardado;
							if (std::cin.fail()) {
								std::cin.clear();
								std::cin.ignore();
							}
						} while (guardado != 0 && guardado != 1);
						if (guardado == 0) {
							guardarLista("Jugadores.txt", lis);
							guardarMazo(mazo, "Mazo.txt");
							guardarDealer(dea, "Dealer.txt");
							guardarTurno(i, "Turno.txt");
							system("CLS");
							std::cout << "------------------------------------------\n";
							std::cout << "          El juego se ha guardado         \n";
							std::cout << "------------------------------------------\n";
							system("PAUSE");
							break;
						}
						else {
							std::cout << "------------------------------------------\n";
							std::cout << "        El juego no se ha guardado        \n";
							std::cout << "------------------------------------------\n";
							break;
						}
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
				system("CLS");
				Sleep(600);
				li->mostrarResultados(); //mostrara el resultado del juego
			}
			else {
				system("CLS");
				Sleep(600);
				std::cout << "La casa ha perdido..." << std::endl << std::endl;
				std::cout << "============== G A N A D O R E S ==============" << std::endl << std::endl;
				li->mostrarGanadores(); //muestra todos los jugadores que no se pasaron de 21
			}
		}
	}
}

void Juego::guardarLista(std::string m, Lista* lis) {
	std::ofstream file;
	file.open(m, std::ios::out);

	if (!file.is_open()) {
		std::cout << "Error al abrir el archivo...\n";
	}
	lis->guardarJugador(file);
	file.close();
}

Lista* Juego::cargarLista() {

	std::string nickname;
	std::string palo;
	std::string valor;
	std::string buffer;
	std::string cant;
	Lista* lis = new Lista();
	std::ifstream file;
	std::string cont;

	file.open("Jugadores.txt", std::ios::in);

	if (!file.is_open()) {
		std::cout << "Error al abrir el archivo...\n";
	}


	while (std::getline(file, buffer)) {
		std::istringstream linea{ buffer };
		std::getline(linea, nickname, '&');
		std::getline(linea, cant, '&');
		std::getline(linea, cont, '&');
		Mano* mano = new Mano();
		for (int i = 0; i < stringToInt(cant); i++) {
			std::getline(linea, valor, ',');
			std::getline(linea, palo, '|');
			Carta* c = new Carta(valor, palo);
			mano->agregarCarta(c);
		}
		Jugador* j1 = new Jugador(nickname, mano);
		j1->setNumJug(stringToInt(cont));
		lis->insertarFinal(j1);
	}
	return lis;
}


int Juego::stringToInt(std::string s) {
	int x;
	std::stringstream ss;
	ss << s;
	ss >> x;
	return x;
}

void Juego::guardarMazo(Mazo* m, std::string n) {
	std::ofstream file;

	file.open(n, std::ios::out);
	if (!file.is_open()) {
		std::cout << "Error al abrir el archivo...\n";
	}

	m->guardarMazo(file);
	file.close();
}

Mazo* Juego::cargarMazo() {

	std::string palo;
	std::string valor;
	std::string buffer;
	std::string cant;
	std::ifstream file;

	file.open("Mazo.txt", std::ios::in);

	if (!file.is_open()) {
		std::cout << "Error al abrir el archivo...\n";
	}

	Mazo* mazo = new Mazo;
	while (std::getline(file, buffer)) {
		std::istringstream linea{ buffer };
		std::getline(linea, cant, '&');
		for (int i = 0; i < stringToInt(cant); i++) {
			std::getline(linea, valor, ',');
			std::getline(linea, palo, '|');
			Carta* c = new Carta(valor, palo);
			mazo->agregarCarta(c);

		}
	}

	return mazo;
}

void Juego::guardarDealer(Dealer* d, std::string pa) {

	std::ofstream file;

	file.open(pa, std::ios::out);

	if (!file.is_open()) {
		std::cout << "Error al abrir el archivo...\n";
	}

	d->guardarDealer(file);
	file.close();
}

Dealer* Juego::cargarDealer() {

	std::string nickname;
	std::string palo;
	std::string valor;
	std::string buffer;
	std::string cant;
	std::ifstream file;

	file.open("Dealer.txt", std::ios::in);

	if (!file.is_open()) {
		std::cout << "Error al abrir el archivo...\n";
	}

	Dealer* a = nullptr;
	while (std::getline(file, buffer)) {
		std::istringstream linea{ buffer };
		std::getline(linea, nickname, '%');
		std::getline(linea, cant, '%');
		Mano* mano = new Mano();
		for (int i = 0; i < stringToInt(cant); i++) {
			std::getline(linea, valor, ',');
			std::getline(linea, palo, '|');
			Carta* c = new Carta(valor, palo);
			mano->agregarCarta(c);
		}
		a = new Dealer("dealer", mano);
	}
	return a;
}

void Juego::cargarPartida() {
	iniciarPartidas(cargarMazo(), cargarLista(), cargarDealer(), cargarTurno());
}

void Juego::guardarTurno(int i, std::string pa) {
	std::ofstream file;

	file.open(pa, std::ios::out);

	if (!file.is_open()) {
		std::cout << "Error al abrir el archivo...\n";
	}

	file << i << "%";

	file.close();
}

int Juego::cargarTurno() {
	std::string num;
	std::string buffer;
	std::ifstream file;

	file.open("Turno.txt", std::ios::in);

	if (!file.is_open()) {
		std::cout << "Error al abrir el archivo...\n";
	}

	while (std::getline(file, buffer)) {
		std::istringstream linea{ buffer };
		std::getline(linea, num, '%');
	}
	return stringToInt(num);

}