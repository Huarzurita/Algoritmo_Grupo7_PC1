#pragma once
#include "Capp.h"
template <class Generic>
class Music
{
public:
	Music(Generic cancion, Generic genero, Generic artista) : cancion(cancion), genero(genero), artista(artista) {
		archivo.open("Canciones.txt", ios::app);
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
		archivo << "--------------------------------------------------------------------------------------------" << "\n";
		archivo << "                                 �INFORMACI�N DE LA CANCI�N�                                " << "\n";
		archivo << "--------------------------------------------------------------------------------------------" << "\n";
		archivo << "    Nombre de la canci�n: " << cancion << endl;
		archivo << "    G�nero de la canci�n: " << genero << endl;
		archivo << "    Artista de la canci�n: " << artista << endl;
		archivo << "--------------------------------------------------------------------------------------------" << endl;
		archivo << "\n";
	}
public:
	Generic cancion, genero, artista;
	fstream archivo;
};