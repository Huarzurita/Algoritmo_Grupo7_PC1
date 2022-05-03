#pragma once
#include "Capp.h"
//t=string mas adelante porsiaca xd
template<class t>
class Nodo2{
public:
	t Dp, Dr;
	Nodo2* siguiente;

	Nodo2() {
		this->Dp = "";
		this->Dr = "";
		this->siguiente = NULL;
	}
};

template<class t>
class Quizz {
private:
	Nodo2<t>* tope;
	int tamaño;
public:
	Quizz() {
		this->tamaño = 0;
		this->tope = NULL;
	}


	void Push(t dp, t dr) { // pide pregunta y respuesta
		Nodo2<t>* nuevo = new Nodo2<t>();
		nuevo->Dp = dp;
		nuevo->Dr = dr;
		nuevo->siguiente = this->tope;
		this->tope = nuevo;
		this->tamaño++;
	}

	void Print() {
		for (int i = tamaño; i > 0; i--) {
			Nodo2<t>* aux2 = this->tope;
			Nodo2<t>* aux3 = this->tope;
			int j = rand() % i;
			for (int k = 0; k < j; k++)
				aux2 = aux2->siguiente;

			for (int l = 0; l < i - 1; l++)
				aux3 = aux3->siguiente;

			swap(aux2->Dp, aux3->Dp);
			swap(aux2->Dr, aux3->Dr);
			system("cls");
			cout << "Pregunta: " << aux3->Dp << "\n";
			system("pause");
			cout << "Respuesta: " << aux3->Dr << "\n";
			system("pause");
		}
	}


};