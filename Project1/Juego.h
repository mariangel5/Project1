#ifndef JUEGO_H
#define JUEGO_H
#include "Mano.h"
#include "Lista.h"
#include <fstream>

class Juego
{
public:
	static void iniciaNuevoJuego();
	static void iniciarPartidas(Mazo*, Lista*, Dealer*, int);
	static void menuJuego();
	static void comprobarGanador(bool, Mazo*, Lista*, Dealer*);
	static void guardarLista(std::string, Lista*);
	static void guardarTurno(int, std::string);
	static int cargarTurno();
	static Lista* cargarLista();
	static void guardarMazo(Mazo*, std::string);
	static Mazo* cargarMazo();
	static int stringToInt(std::string);
	static void guardarDealer(Dealer*, std::string);
	static Dealer* cargarDealer();
	static void cargarPartida();
};
#endif
