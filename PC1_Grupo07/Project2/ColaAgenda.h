#pragma once
#include "Capp.h"
template <class T>
class Nodo1{
public:
	T com, com1, com2;
	Nodo1<T>* siguiente;
	Nodo1(T aux, T aux1, T aux2, Nodo1<T>* sig = NULL) {
		com = aux;
		com1 = aux1;
		com2 = aux2;
		siguiente = sig;
	}
};
template <class T>
class ColaAgenda
{
public:
	ColaAgenda(T contacto, T correo, T telefono) {
		this->frente = NULL;
		this->fin = NULL;
		this->contacto = contacto;
		this->correo = correo;
		this->telefono = telefono;
	}
	void push() {
		Nodo1<T>* nodito = new Nodo1<T>(contacto,correo,telefono);
		nodito->siguiente = NULL;
		if (frente == NULL) {
			frente = nodito;
			fin = nodito;
		}
		else {
			fin->siguiente = nodito;
		}
		fin = nodito;
	}
	void saveData() {
		archivoAgenda.open("Agenda.txt", ios::out);
		if (archivoAgenda.fail()) {
			cout << "No se pudo abrir el archivo " << "\n";
		}
		else {
			while (frente != NULL)
			{
				archivoAgenda << "|--------------------------------------------------------------------------------------------|" << "\n";
				archivoAgenda << "|                                   °DATOS DEL CONTACTO°                                     |" << "\n";
				archivoAgenda << "|--------------------------------------------------------------------------------------------|" << "\n";
				archivoAgenda << "  Nombre del contacto: " << frente->com << "\n";
				archivoAgenda << "  Correo de la tarea: " << frente->com1 << "\n";
				archivoAgenda << "  Celular o teléfono del contacto: " << frente->com2 << "\n";
				archivoAgenda << "|--------------------------------------------------------------------------------------------|" << "\n";
				frente = frente->siguiente;
			}
		}
		archivoAgenda.close();
	}
	~ColaAgenda();

private:
	Nodo1<T>* frente;
	Nodo1<T>* fin;
	fstream archivoAgenda;
	T contacto, correo, telefono;
};