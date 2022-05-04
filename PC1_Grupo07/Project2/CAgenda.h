#pragma once
#include "Capp.h"
template <class Generic>
class Nodo1{
public:
	Generic com, com1, com2;
	Nodo1<Generic>* siguiente;
	Nodo1(Generic aux, Generic aux1, Generic aux2) {
		com = aux;
		com1 = aux1;
		com2 = aux2;
	}
};
template <class Generic>
class Contact_queue
{
private:
	Nodo1<Generic>* head;
	Nodo1<Generic>* tail;
	Generic contacto, correo, telefono;
public:
	Contact_queue(Generic contacto, Generic correo, Generic telefono) {
		this->head = NULL;
		this->tail = NULL;
		this->contacto = contacto;
		this->correo = correo;
		this->telefono = telefono;
	}
	void push_data() {
		Nodo1<Generic>* nodito = new Nodo1<Generic>(contacto,correo,telefono);
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
		if (head==NULL) {
			cout << "La cola esta vacía" << "\n";
		}
		else {
			while (head != NULL)
			{
				cout << "|--------------------------------------------------------------------------------------------|" << "\n";
				cout << "|                                   °DATOS DEL CONTACTO°                                     |" << "\n";
				cout << "|--------------------------------------------------------------------------------------------|" << "\n";
				cout << "  Nombre del contacto: " << head->com << "\n";
				cout << "  Correo de la tarea: " << head->com1 << "\n";
				cout << "  Celular o teléfono del contacto: " << head->com2 << "\n";
				cout << "|--------------------------------------------------------------------------------------------|" << "\n";
				head = head->siguiente;
			}
		}
	}
	~Contact_queue();
};