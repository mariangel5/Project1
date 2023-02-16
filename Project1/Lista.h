#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h" 

class Lista{
public:
	Lista(); 
	~Lista();
	Nodo* getInicio();
	bool borrarJug(int); //recibe el nombre del jugador que se quiere borrar
	std::string toString();
	bool listaVacia(); 
	int cuentaNodos();
	void insertarFinal(JugadorGenerico*);
	JugadorGenerico* getJugador(int);
	void mostrarResultados();
	void mostrarGanadores();
	void guardarJugador(std::ofstream&);
	bool buscarJugador(std::string);

private:
	Nodo* inicio;
	
};
#endif
