#include "Mano.h"
#include "Lista.h"
//#include <cctype>

#pragma once
class Juego
{
public:
	static void iniciaNuevoJuego();
	static void iniciarPartidas(Mazo*, Lista*, Dealer*);
	static void menuJuego();
};

