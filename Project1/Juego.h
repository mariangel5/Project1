#include "Mano.h"
#include "Lista.h"
#include  <Windows.h>
//#include <cctype>

#pragma once
class Juego
{
public:
	static void iniciaNuevoJuego();
	static void iniciarPartidas(Mazo*, Lista*, Dealer*);
	static void menuJuego();
	static void comprobarGanador(Mazo*, Lista*, Dealer*);
};

