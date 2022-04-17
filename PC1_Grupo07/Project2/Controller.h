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
	fstream archivoTareas,archivoEventos,archivoNotas,archivoRecordatorios;
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
			archivoTareas << tareas[i]->getTitulo() << "\n";
			archivoTareas << tareas[i]->getFecha() << "\n";
			archivoTareas << tareas[i]->getHora() << "\n";
			archivoTareas << tareas[i]->getUrgencia() << "\n";
			archivoTareas << to_string(tareas[i]->getCompletado()) << "\n";
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
	void guardarEventos() {
		archivoEventos.open("Eventos.txt", ios::out);
		if (archivoEventos.fail())
			cout << "No se pudo abrir el archivo " << "\n";
		for (int i = 0; i < eventos.size(); i++)
		{
			archivoEventos << eventos[i]->getTitulo() << "\n";
			archivoEventos << eventos[i]->getFecha() << "\n";
			archivoEventos << eventos[i]->getHora() << "\n";
			archivoEventos << eventos[i]->getUrgencia() << "\n";
			archivoEventos << eventos[i]->getDescripcion() << "\n";
			archivoEventos << eventos[i]->getLugar() << "\n";
		}
		archivoEventos.close();
	}
	void mostrarEventos() {
		string linea;
		archivoEventos.open("Eventos.txt", ios::in);
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "___________________________________________________________________\n";
		Console::ForegroundColor = ConsoleColor::Yellow;
		while (!archivoEventos.eof()) {
			getline(archivoEventos, linea);
			cout << linea << "\n";
		}
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "___________________________________________________________________\n";
		_getch();
		archivoEventos.close();
	}

	void guardarNotas() {
		archivoNotas.open("Notas.txt", ios::out);
		if (archivoNotas.fail())
			cout << "No se pudo abrir el archivo " << "\n";
		for (int i = 0; i < notas.size(); i++)
		{
			archivoNotas << notas[i]->getTitulo() << "\n";
			archivoNotas << notas[i]->getDescripcion() << "\n";
		}
		archivoNotas.close();
	}
	void mostrarNotas() {
		string linea;
		archivoNotas.open("Notas.txt", ios::in);
		Console::ForegroundColor = ConsoleColor::DarkCyan;
		cout << "___________________________________________________________________\n";
		Console::ForegroundColor = ConsoleColor::White;
		while (!archivoNotas.eof()) {
			getline(archivoNotas, linea);
			cout << linea << "\n";
		}
		Console::ForegroundColor = ConsoleColor::DarkCyan;
		cout << "___________________________________________________________________\n";
		_getch();
		archivoNotas.close();
	}
	void guardarRecordatorios() {
		archivoRecordatorios.open("Recordatorios.txt", ios::out);
		if (archivoRecordatorios.fail())
			cout << "No se pudo abrir el archivo " << "\n";
		for (int i = 0; i < recordatorios.size(); i++)
		{
			archivoRecordatorios << recordatorios[i]->getTitulo() << "\n";
			archivoRecordatorios << recordatorios[i]->getFecha() << "\n";
			archivoRecordatorios << recordatorios[i]->getHora() << "\n";
			archivoRecordatorios << recordatorios[i]->getUrgencia() << "\n";
		}
		archivoRecordatorios.close();
	}
	void mostrarRecordatorios() {
		string linea;
		archivoRecordatorios.open("Recordatorios.txt", ios::in);
		Console::ForegroundColor = ConsoleColor::Blue;
		cout << "___________________________________________________________________\n";
		Console::ForegroundColor = ConsoleColor::Green;
		while (!archivoRecordatorios.eof()) {
			getline(archivoRecordatorios, linea);
			cout << linea << "\n";
		}
		Console::ForegroundColor = ConsoleColor::Blue;
		cout << "___________________________________________________________________\n";
		_getch();
		archivoRecordatorios.close();
	}

};
