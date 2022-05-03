#pragma once
#include "CEvento.h"
#include "CNota.h"
#include "CRecordatorio.h"
#include "CTarea.h"
#include "ColaAgenda.h"
#include "ColaMusica.h"
#include "CQuizz.h"
class Controller
{
private:

	vector<CTarea<string>*>tareas;
	vector<CRecordatorio<string>*>recordatorios;
	vector<CNota<string>*>notas;
	vector<CEvento<string>*>eventos;
	fstream archivoTareas, archivoEventos, archivoNotas, archivoRecordatorios,archivoAgenda, archivoMusica;
public:
	Controller() {
	};
	~Controller() {};
	void addTarea(string completado, string titulo, string fecha, string hora, string urgencia) {
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
	void addAgenda(string contacto, string correo, string telefono) {
		ColaAgenda<string>*obj;
		obj = new ColaAgenda<string>(contacto, correo, telefono);
		obj->push();
		obj->saveData();
		_getch();
	}
	
	void mostrarAgenda() {
		Random r;
		string linea;
		archivoAgenda.open("Agenda.txt", ios::in);
		Console::ForegroundColor = ConsoleColor(r.Next(1, 16));
		while (!archivoAgenda.eof()) {
			getline(archivoAgenda, linea);
			cout << linea << "\n";
		}
		_getch();
		archivoAgenda.close();
	}
	void addMusica(string cancion, string genero, string artista) {
		ColaMusica<string>* musica;
		musica = new ColaMusica<string>(cancion, genero, artista);
		musica->push_data();
		musica->save__Data();
		_getch();
	}
	void mostrarMusica() {
		Random r;
		string linea;
		archivoMusica.open("Musica.txt", ios::in);
		Console::ForegroundColor = ConsoleColor(r.Next(1, 16));
		while (!archivoMusica.eof()) {
			getline(archivoMusica, linea);
			cout << linea << "\n";
		}
		_getch();
		archivoMusica.close();
	}

	void guardarTareas() {
		archivoTareas.open("Tareas.txt", ios::out);
		if (archivoTareas.fail())
			cout << "No se pudo abrir el archivo " << "\n";
		for (int i = 0; i < tareas.size(); i++)
		{
			archivoTareas << "|--------------------------------------------------------------------------------------------|" << "\n";
			archivoTareas << "|                                   °INFORMACIÓN DE LA TAREA°                                |" << "\n";
			archivoTareas << "|--------------------------------------------------------------------------------------------|" << "\n";
			archivoTareas << "   Título de la tarea: "<<tareas[i]->getTitulo() << "\n";
			archivoTareas << "   Fecha de la tarea: " << tareas[i]->getFecha() << "\n";
			archivoTareas << "   Hora de la tarea: " << tareas[i]->getHora()  << "\n";
			archivoTareas << "   Urgencia de la tarea: " << tareas[i]->getUrgencia() << "\n";
			archivoTareas << "   Estado de la tarea: " << tareas[i]->getCompletado() << "\n";
			archivoTareas << "|--------------------------------------------------------------------------------------------|" << "\n";
		}
		archivoTareas.close();
	}
	void mostrarTareas() {
		Random r;
		string linea;
		archivoTareas.open("tareas.txt", ios::in);
		Console::ForegroundColor = ConsoleColor(r.Next(1, 16));
		while (!archivoTareas.eof()) {
			getline(archivoTareas, linea);
			cout << linea << "\n";
		}
		_getch();
		archivoTareas.close();
	}

	void guardarEventos() {
		archivoEventos.open("Eventos.txt", ios::out);
		if (archivoEventos.fail())
			cout << "No se pudo abrir el archivo " << "\n";
		for (int i = 0; i < eventos.size(); i++)
		{
			archivoEventos << "|--------------------------------------------------------------------------------------------|" << "\n";
			archivoEventos << "|                                   °INFORMACIÓN DEL EVENTO°                                 |" << "\n";
			archivoEventos << "|--------------------------------------------------------------------------------------------|" << "\n";
			archivoEventos << "   Título del evento: " << eventos[i]->getTitulo() << "\n";
			archivoEventos << "   Fecha del evento: " << eventos[i]->getFecha() << "\n";
			archivoEventos << "   Hora del evento: " << eventos[i]->getHora()  << "\n";
			archivoEventos << "   Urgencia del evento: " << eventos[i]->getUrgencia() << "\n";
			archivoEventos << "   Descripción del evento: " << eventos[i]->getDescripcion() << "\n";
			archivoEventos << "   Lugar del evento: " << eventos[i]->getLugar()  << "\n";
			archivoEventos << "|--------------------------------------------------------------------------------------------|" << "\n";
		}
		archivoEventos.close();
	}
	void mostrarEventos() {
		Random r;
		string linea;
		archivoEventos.open("Eventos.txt", ios::in);
		Console::ForegroundColor = ConsoleColor(r.Next(1, 16));
		while (!archivoEventos.eof()) {
			getline(archivoEventos, linea);
			cout << linea << "\n";
		}
		_getch();
		archivoEventos.close();
	}

	void guardarNotas() {
		archivoNotas.open("Notas.txt", ios::out);
		if (archivoNotas.fail())
			cout << "No se pudo abrir el archivo " << "\n";
		for (int i = 0; i < notas.size(); i++)
		{
			archivoNotas << "|--------------------------------------------------------------------------------------------|" << "\n";
			archivoNotas << "|                                 °INFORMACIÓN DE LA NOTA°                                   |" << "\n";
			archivoNotas << "|--------------------------------------------------------------------------------------------|" << "\n";
			archivoNotas << "  Título de la nota: " << notas[i]->getTitulo()<< "\n";
			archivoNotas << "  Descripción de la nota: " << notas[i]->getDescripcion()  <<"\n";
			archivoNotas << "|--------------------------------------------------------------------------------------------|" << "\n";
		}
		archivoNotas.close();
	}
	void mostrarNotas() {
		Random r;
		string linea;
		archivoNotas.open("Notas.txt", ios::in);
		Console::ForegroundColor = ConsoleColor(r.Next(1, 16));
		while (!archivoNotas.eof()) {
			getline(archivoNotas, linea);
			cout << linea << "\n";
		}
		_getch();
		archivoNotas.close();
	}

	void guardarRecordatorios() {
		archivoRecordatorios.open("Recordatorios.txt", ios::out);
		if (archivoRecordatorios.fail())
			cout << "No se pudo abrir el archivo " << "\n";
		for (int i = 0; i < recordatorios.size(); i++)
		{
			archivoRecordatorios << "|--------------------------------------------------------------------------------------------|"<< "\n";
			archivoRecordatorios << "|                                 °INFORMACIÓN DEL RECORDATORIO°                             |" << "\n";
			archivoRecordatorios << "|--------------------------------------------------------------------------------------------|" << "\n";
			archivoRecordatorios << "   Título del recordatorio: " << recordatorios[i]->getTitulo() << "\n";
			archivoRecordatorios << "   Fecha del recordatorio: " << recordatorios[i]->getFecha() << "\n";
			archivoRecordatorios << "   Hora del recordatorio: " << recordatorios[i]->getHora() << "\n";
			archivoRecordatorios << "   Urgencia del recordatorio: " <<recordatorios[i]->getUrgencia() << "\n";
			archivoRecordatorios << "|--------------------------------------------------------------------------------------------|" << "\n";
		}
		archivoRecordatorios.close();
	}
	void mostrarRecordatorios() {
		Random r;
		string linea;
		archivoRecordatorios.open("Recordatorios.txt", ios::in);
		Console::ForegroundColor = ConsoleColor(r.Next(1, 16));
		while (!archivoRecordatorios.eof()) {
			getline(archivoRecordatorios, linea);
			cout << linea << "\n";
		}
		_getch();
		archivoRecordatorios.close();
	}

};

