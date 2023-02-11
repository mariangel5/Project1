#include "Lista.h"


Lista::Lista() : inicio{ nullptr } {
}

Nodo* Lista::getInicio() {
	return this->inicio;
}

Lista::~Lista() {
	Nodo* temporal;
	if (inicio == nullptr) {
		while (inicio != NULL) {
			temporal = inicio;
			inicio = inicio->next;
			delete temporal;
		}
		delete inicio;
	}
}



/*Lista::~Lista() { //otro constructor que pude servir 
	Nodo* temp = inicio;
	while (temp != NULL) {
		inicio = temp->getSiguiente();
		delete temp;
		temp = inicio;
	}
	inicio = NULL;
}*/

void Lista::insertar(Nodo j) {
	Nodo* nuevo;
	nuevo = new Nodo{ j };
	if (inicio == nullptr)
		inicio = nuevo;
	else {
		Nodo* tmp = inicio;
		while (tmp->next != nullptr)
			tmp = tmp->next;
		tmp->next = nuevo;
	}
}

void Lista::insertarFinal(JugadorGenerico* j) {//inserta un jugador al final de la lista
	Nodo* actual = inicio;
	if (actual == NULL) {
		inicio = new Nodo(j, NULL);
	}
	else {
		while (actual->getNext() != NULL) {
			actual = actual->getNext();
		}
		actual->setNext(new Nodo(j, NULL));
	}
}

bool Lista::borrarJug(int num) {
		Nodo* aux = inicio;
		Nodo* anterior = nullptr;
		if (aux != nullptr && aux->dato->getNumJug() == num) {
			Nodo* actual = inicio;
			if (aux != nullptr) {
				inicio = actual->next;
				delete actual;
				return true;
			}
		}
		else if (aux != nullptr) {
			while (aux != nullptr && aux->dato->getNumJug() != num) {
				anterior = aux;
				aux = aux->next;
			}
			anterior->setNext(aux->next);
			delete aux;
			return true;
		}
		return false;
}

bool Lista::listaVacia() {
	return inicio == nullptr;
}


int Lista::cuentaNodos() {
	int cont = 0;
	Nodo* actual = inicio;
	while (actual != NULL) {
		cont++;
		actual = actual->getNext();
	}
	return cont;
}

string Lista::toString() {
	stringstream s;
	Nodo* actual = inicio;
	while (actual != NULL) {
		s << actual->toString();
		actual = actual->getNext();
	}
	return s.str();
}

JugadorGenerico* Lista::getJugador(int num) {
	Nodo* aux = inicio;
	while (aux != nullptr) {
		if (aux->dato->getNumJug() == num) {
			return aux->dato;
		}
		aux = aux->next;
	}
	return nullptr;
}