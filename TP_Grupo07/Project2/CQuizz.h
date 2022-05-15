#pragma once
#include "Capp.h"
template<class Generic>
class Node2 {
public:
	Generic Dp, Dr;
	Node2* siguiente;
	Node2() {
		this->Dp = "";
		this->Dr = "";
		this->siguiente = NULL;
	}
};

template<class Generic>
class Quizz {
private:
	Node2<Generic>* tope;
	int tamaño;
public:
	Quizz() {
		this->tamaño = 0;
		this->tope = NULL;
	}
	void Push(Generic dp, Generic dr) { // pide pregunta y respuesta
		Node2<Generic>* nuevo = new Node2<Generic>();
		nuevo->Dp = dp;
		nuevo->Dr = dr;
		nuevo->siguiente = this->tope;
		this->tope = nuevo;
		this->tamaño++;
	}
	void Print() {
		for (int i = tamaño; i > 0; i--) {
			Node2<Generic>* aux2 = this->tope;
			Node2<Generic>* aux3 = this->tope;
			int j = rand() % i;
			for (int k = 0; k < j; k++)
				aux2 = aux2->siguiente;

			for (int l = 0; l < i - 1; l++)
				aux3 = aux3->siguiente;
			swap(aux2->Dp, aux3->Dp);
			swap(aux2->Dr, aux3->Dr);
			system("cls");
			cout << "\t Pregunta: " << aux3->Dp << endl;
			system("pause");
			cout << "\t Respuesta: " << aux3->Dr << endl;
			system("pause");
		}
	}
};