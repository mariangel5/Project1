#include "Mano.h"
#include "Lista.h"


#pragma once
class Juego
{
public:
	static void iniciaNuevoJuego();
	static void iniciarPartidas(Mazo*, Lista*, Dealer*);
	static void menuJuego();
	static void comprobarGanador(bool, Mazo*, Lista*, Dealer*);
};

