#pragma once
#include "Capp.h"
template <class T>
class Nodo {
public:
	T com, com1, com2;
	Nodo<T>* siguiente;
	Nodo(T aux, T aux1, T aux2, Nodo<T>* sig = NULL) {
		com = aux;
		com1 = aux1;
		com2 = aux2;
		siguiente = sig;
	}
};
template <class T>
class ColaMusica
{
public:
	ColaMusica(T cancion, T genero, T artista) {
		this->frente = NULL;
		this->fin = NULL;
		this->cancion = cancion;
		this->genero = genero;
		this->artista = artista;
	}
	void push_data() {
		Nodo<T>* nodito = new Nodo<T>(cancion, genero, artista);
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
	void save__Data() {
		archivoMusica.open("Musica.txt", ios::out);
		if (archivoMusica.fail()) {
			cout << "No se pudo abrir el archivo " << "\n";
		}
		else {
			while (frente != NULL)
			{
				archivoMusica << "|--------------------------------------------------------------------------------------------|" << "\n";
				archivoMusica << "|                                   °REGISTRO DE CANCIONES°                                  |" << "\n";
				archivoMusica << "|--------------------------------------------------------------------------------------------|" << "\n";
				archivoMusica << "  Nombre de la canción: " << frente->com << "\n";
				archivoMusica << "  Género de la canción: " << frente->com1 << "\n";
				archivoMusica << "  Artista de la canción: " << frente->com2 << "\n";
				archivoMusica << "|--------------------------------------------------------------------------------------------|" << "\n";
				frente = frente->siguiente;
			}
		}
		archivoMusica.close();
	}
	~ColaMusica();

private:
	Nodo<T>* frente;
	Nodo<T>* fin;
	fstream archivoMusica;
	T cancion, genero, artista;
};