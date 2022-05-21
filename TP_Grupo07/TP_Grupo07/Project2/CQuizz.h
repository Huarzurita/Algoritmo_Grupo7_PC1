#pragma once
#include "Capp.h"
template<class Generic>
class Node2 {
public:
	Generic Dp, Dr;
	Node2* siguiente;
	Node2() {
		Dp = "";
		Dr = "";
		siguiente = NULL;
	}
};

template<class Generic>
class Quizz {
public:
	Node2<Generic>* tope;
	fstream archivoQuizz;
	int tamaño;
public:
	Quizz() {
		tamaño = 0;
		tope = NULL;
		archivoQuizz.open("Quizz.txt", ios::out);
	}
	void Push(Generic dp, Generic dr) { // pide pregunta y respuesta
		Node2<Generic>* nuevo = new Node2<Generic>();
		nuevo->Dp = dp;
		nuevo->Dr = dr;
		nuevo->siguiente = tope;
		archivoQuizz << "\n";
		archivoQuizz << "\t |--------------------------------------------------------------------------------------------|" << "\n";
		archivoQuizz << "\t |                                          °PREGUNTAS°                                       |" << "\n";
		archivoQuizz << "\t |--------------------------------------------------------------------------------------------|" << "\n";
		archivoQuizz << "\t      Pregunta: " << nuevo->Dp << endl;
		archivoQuizz << "\t      Respuesta: " << nuevo->Dr << endl;
		archivoQuizz << "\t |--------------------------------------------------------------------------------------------|" << "\n";
		archivoQuizz << "\n";
		tope = nuevo;
		tamaño++;
	}
	void swap(Generic *a, Generic *b) {
		Generic temp = *a;
		*a = *b;
		*b = temp;
	}
	void Print() {
		for (int i = tamaño; i > 0; i--) {
			Node2<Generic>* aux2 = tope;
			Node2<Generic>* aux3 = tope;
			int j = rand() % i;
			for (int k = 0; k < j; k++)
				aux2 = aux2->siguiente;

			for (int l = 0; l < i - 1; l++)
				aux3 = aux3->siguiente;
			swap(&aux2->Dp, &aux3->Dp);
			swap(&aux2->Dr, &aux3->Dr);
			system("cls");
			cout << "\t APRENDE CON DIVERSIÓN! :D : " << endl;
			cout << "\t QUIZZ: " << "\n";
			cout << "\t Pregunta: " << aux3->Dp << endl;
			cout << "\t ";system("pause");
			cout << "\t Respuesta: " << aux3->Dr << endl;
			cout << "\t "; system("pause");
		}
	}
};