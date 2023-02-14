#ifndef JUEGO_H
#define JUEGO_H
#include "Mano.h"
#include "Lista.h"
#include <fstream>

class Juego
{
public:
	static void iniciaNuevoJuego();
	static void iniciarPartidas(Mazo*, Lista*, Dealer*);
	static void menuJuego();
	static void comprobarGanador(bool, Mazo*, Lista*, Dealer*);
	static void guardarJugadores(Lista*);
};
#endif
