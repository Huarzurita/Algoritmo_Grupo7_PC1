#pragma once
#include "Capp.h"
template <class Generic>
class Music
{
public:
	Music(Generic cancion, Generic genero, Generic artista) : cancion(cancion), genero(genero), artista(artista) {
		archivo.open("Canciones.txt", ios::out);
	}
	~Music() {  }
	Generic getcancion() { return cancion; }
	Generic getgenero() { return genero; }
	Generic getartista() { return artista; }
	void mostrar() {
		cout << "\n";
		cout << "\t |--------------------------------------------------------------------------------------------|" << "\n";
		cout << "\t |                                 �INFORMACI�N DE LA CANCI�N�                                |" << "\n";
		cout << "\t |--------------------------------------------------------------------------------------------|" << "\n";
		cout << "\t      Nombre de la canci�n: " << cancion << endl;
		cout << "\t      G�nero de la canci�n: " << genero << endl;
		cout << "\t      Artista de la canci�n: " << artista << endl;
		cout << "\t |--------------------------------------------------------------------------------------------|" << "\n";
		cout << "\n";
	}
	void guardar() {
		archivo << "\n";
		archivo << "\t |--------------------------------------------------------------------------------------------|" << "\n";
		archivo << "\t |                                 �INFORMACI�N DE LA CANCI�N�                                |" << "\n";
		archivo << "\t |--------------------------------------------------------------------------------------------|" << "\n";
		archivo << "\t      Nombre de la canci�n: " << cancion << endl;
		archivo << "\t      G�nero de la canci�n: " << genero << endl;
		archivo << "\t      Artista de la canci�n: " << artista << endl;
		archivo << "\t |--------------------------------------------------------------------------------------------|" << endl;
		archivo << "\n";
	}
public:
	Generic cancion, genero, artista;
	fstream archivo;
};