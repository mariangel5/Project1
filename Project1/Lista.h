#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h" 

class Lista{
public:
	Lista(); 
	~Lista();
	Nodo* getInicio();
	void insertar(Nodo);
	bool borrarJug(int); //recibe el nombre del jugador que se quiere borrar
	std::string toString();
	bool listaVacia(); 
	int cuentaNodos();
	void insertarFinal(JugadorGenerico*);
	JugadorGenerico* getJugador(int);
	void mostrarResultados();
	void mostrarGanadores();
	void guardarJugador(std::ofstream&);

private:
	Nodo* inicio;
	
};
#endif
