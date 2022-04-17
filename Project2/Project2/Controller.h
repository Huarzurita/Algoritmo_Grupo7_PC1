#pragma once
#include "CEvento.h"
#include "CNota.h"
#include "CRecordatorio.h"
#include "CTarea.h"

class Controller
{
private:
	vector<CTarea<string>*>tareas;
	vector<CRecordatorio<string>*>recordatorios;
	vector<CNota<string>*>notas;
	vector<CEvento<string>*>eventos;
	fstream archivoTareas;
public:
	Controller() {};
	~Controller() {};
	void addTarea(bool completado,string titulo, string fecha, string hora, string urgencia) {
		tareas.push_back(new CTarea<string>(completado, titulo, fecha, hora, urgencia));
	}
	void addRecordatorio(string titulo, string fecha, string hora, string urgencia) {
		recordatorios.push_back(new CRecordatorio<string>(titulo, fecha, hora, urgencia));
	}
	void addNota(string titulo, string descripcion) {
		notas.push_back(new CNota<string>(titulo, descripcion));
	}
	void addEvento(string lugar, string titulo, string fecha, string hora, string descripcion, string urgencia) {
		eventos.push_back(new CEvento<string>(lugar, titulo, fecha, hora, descripcion, urgencia));
	}

	void guardarTareas() {
		
		archivoTareas.open("Tareas.txt", ios::out);
		if(archivoTareas.fail())
			cout << "No se pudo abrir el archivo " << "\n";
		for (int i = 0; i < tareas.size(); i++)
		{
			archivoTareas << tareas[i]->getTitulo();
			archivoTareas << tareas[i]->getFecha();
			archivoTareas << tareas[i]->getHora();
			archivoTareas << tareas[i]->getUrgencia();
			archivoTareas << to_string(tareas[i]->getCompletado());

		}
		archivoTareas.close();
	}
	void mostrarTareas() {
		string linea;
		archivoTareas.open("tareas.txt", ios::in);
		Console::ForegroundColor = ConsoleColor::Yellow;
		cout << "___________________________________________________________________\n";
		Console::ForegroundColor = ConsoleColor::Green;
		while (!archivoTareas.eof()) {
			getline(archivoTareas, linea);
			cout << linea << "\n";
		}
		Console::ForegroundColor = ConsoleColor::Yellow;
		cout << "___________________________________________________________________\n";
		_getch();
		archivoTareas.close();
		
	}

};
