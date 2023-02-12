#pragma once
#include "Nodo.h" 

class Lista{
public:
	Lista(); 
	~Lista();
	Nodo* getInicio();
	void insertar(Nodo);
	bool borrarJug(int); //recibe el nombre del jugador que se quiere borrar
	string toString();
	bool listaVacia(); 
	int cuentaNodos();
	void insertarFinal(JugadorGenerico*);
	JugadorGenerico* getJugador(int);
	void mostrarResultados();

private:
	Nodo* inicio;
	
};

