#pragma once
#include "Capp.h"
template <class Generic>
class Node {
public:
	Generic com, com1, com2;
	Node<Generic>* siguiente;
	Node(Generic aux, Generic aux1, Generic aux2) {
		com = aux;
		com1 = aux1;
		com2 = aux2;
	}
};

template <class Generic>
class Music_Queue
{
private:
	Node<Generic>* head;
	Node<Generic>* tail;
	Generic cancion, genero, artista;
public:
	Music_Queue(Generic cancion, Generic genero, Generic artista) {
		this->head = NULL;
		this->tail = NULL;
		this->cancion = cancion;
		this->genero = genero;
		this->artista = artista;
	}
	void push_data() {
		Node<Generic>* nodito = new Node<Generic>(cancion, genero, artista);
		nodito->siguiente = NULL;
		if (head == NULL) {
			head = nodito;
			tail = nodito;
		}
		else {
			tail->siguiente = nodito;
		}
		tail = nodito;
	}
	void show_data() {
		if (head == NULL) {
			cout << "La cola esta vacía" << "\n";
		}
		else {
			while (head != NULL)
			{
				cout << "|--------------------------------------------------------------------------------------------|" << "\n";
				cout << "|                                   °REGISTRO DE CANCIONES°                                  |" << "\n";
				cout << "|--------------------------------------------------------------------------------------------|" << "\n";
				cout << "  Nombre de la canción: " << head->com << "\n";
				cout << "  Género de la canción: " << head->com1 << "\n";
				cout << "  Artista de la canción: " << head->com2 << "\n";
				cout << "|--------------------------------------------------------------------------------------------|" << "\n";
				head = head->siguiente;
			}
		}
	}
	~Music_Queue();
};