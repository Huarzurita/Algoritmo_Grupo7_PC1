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
		cout << "\t |                                 °INFORMACIÓN DE LA CANCIÓN°                                |" << "\n";
		cout << "\t |--------------------------------------------------------------------------------------------|" << "\n";
		cout << "\t      Nombre de la canción: " << cancion << endl;
		cout << "\t      Género de la canción: " << genero << endl;
		cout << "\t      Artista de la canción: " << artista << endl;
		cout << "\t |--------------------------------------------------------------------------------------------|" << "\n";
		cout << "\n";
	}
	void guardar() {
		archivo << "\n";
		archivo << "\t |--------------------------------------------------------------------------------------------|" << "\n";
		archivo << "\t |                                 °INFORMACIÓN DE LA CANCIÓN°                                |" << "\n";
		archivo << "\t |--------------------------------------------------------------------------------------------|" << "\n";
		archivo << "\t      Nombre de la canción: " << cancion << endl;
		archivo << "\t      Género de la canción: " << genero << endl;
		archivo << "\t      Artista de la canción: " << artista << endl;
		archivo << "\t |--------------------------------------------------------------------------------------------|" << endl;
		archivo << "\n";
	}
public:
	Generic cancion, genero, artista;
	fstream archivo;
};