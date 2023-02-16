#include <iostream>
#include <sstream>
#include <string>
#include "Juego.h"

int main() {

	int op, opcion;
	bool error = false;
	bool validar, otraVez = true;


	std::cout << "\t|--------------------------------------------------|\n";
	std::cout << "\t|     Le damos la bienvenida al juego BlackJack    |\n";
	std::cout << "\t|--------------------------------------------------|" << std::endl << std::endl;

	while (otraVez == true) { //mientras otraVez sea verdadero volvera al menu principal
		do {
			error = false;
			std::cout << "--------M E N U--------" << std::endl;
			std::cout << "[1]- Juego Nuevo" << std::endl;
			std::cout << "[2]- Cargar Partida" << std::endl;
			std::cout << "[3]- Salir" << std::endl;
			std::cout << "-----------------------" << std::endl << std::endl;
			std::cout << "Digite una opcion (1, 2 o 3): " << std::endl << std::endl;
			std::cin >> op;
			if ((op > 3 || op < 0) || std::cin.fail()) {
				system("CLS");
				std::cin.clear();
				std::cin.ignore(50, '\n');
				error = true;
				std::cout << "\t|--------------------------------------------------|\n";
				std::cout << "\t|        Por favor digite una opcion valida        |\n";
				std::cout << "\t|--------------------------------------------------|" << std::endl << std::endl;
			}
		} while (error);
		switch (op)
		{
		case 1:
			std::cout << "\t\t----------------------------------------\n";
			std::cout << "\t\t Ha seleccionado iniciar un Juego Nuevo \n";
			std::cout << "\t\t----------------------------------------\n";
			system("pause");
			Juego g;
			g.iniciaNuevoJuego();
			break;
		case 2:
			std::cout << "\t\t----------------------------------------\n";
			std::cout << "\t\t    Ha seleccionado Cargar Partida      \n";
			std::cout << "\t\t----------------------------------------\n";
			system("pause");
			g.cargarPartida();
			break;
		default:
			std::cout << "\t\t---------------------------------------------------\n";
			std::cout << "\t\t     Esta saliendo del menu, gracias por jugar     \n";
			std::cout << "\t\t---------------------------------------------------\n";
			break;
			system("CLS");
		}
		do {//Validación
			std::cout << "\t\t---------------------------------------------------\n";
			std::cout << "\t\t    Desea  volver al menu y realizar otra accion   \n";
			std::cout << "\t\t---------------------------------------------------\n";
			std::cout << "Digite 1 para si.\n";
			std::cout << "Digite 0 para no.\n";
			std::cout << "Opcion: ";
			std::cin >> opcion;
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
				std::cout << "\t|-------------------------------------------------------------------------------|\n";
				std::cout << "\t|    ERROR! Ha digitado una opción incorrecta, por favor vuelva a intentar...   |\n";
				std::cout << "\t|-------------------------------------------------------------------------------|" << std::endl << std::endl;
				validar = false;
			}
		} while (!validar);
	}


	return 0;
}

