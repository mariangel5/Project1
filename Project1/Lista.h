#pragma once
#include "Nodo.h" 

class Lista{
public:
	Lista(); 
	~Lista();
	Nodo* getInicio();
	void insertar(Nodo);
	/*bool borrarJugad(string); *///recibe el nombre del jugador que se quiere borrar
	string toString();
	bool listaVacia();
	int cuentaNodos();
	void insertarFinal(JugadorGenerico*);
	/*JugadorGenerico* getJugador(int);
	JugadorGenerico* getGanador(int);
	bool buscarJugador(string); */
private:
	Nodo* inicio;
	
};

