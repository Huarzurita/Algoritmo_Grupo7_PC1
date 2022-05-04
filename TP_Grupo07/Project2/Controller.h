#pragma once
#include "CEvento.h"
#include "CNota.h"
#include "CRecordatorio.h"
#include "CTarea.h"
#include "CAgenda.h"
#include "CHorario.h"
#include "CMusica.h"
class Controller
{
private:

	vector<CTarea<string>*>tareas;
	vector<CRecordatorio<string>*>recordatorios;
	vector<CNota<string>*>notas;
	vector<CEvento<string>*>eventos;
	vector<Contact_queue<string>*>agenda;
	vector<Music_Queue<string>*>musica;
	vector<CHorario<string>*>horario;
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
	void add_Agenda(string contacto, string correo, string telefono) {
		agenda.push_back(new Contact_queue<string>(contacto, correo, telefono));
	}
	void mostrar_Agenda() {
		for (int i = 0; i < agenda.size(); i++)
		{
			agenda.at(i)->push_data();
			agenda.at(i)->show_data();
		}
		_getch();
	}
	void add_Musica(string cancion, string genero, string artista) {
		musica.push_back(new Music_Queue<string>(cancion, genero, artista));
	}
	void mostrar_Musica() {
		for (int i = 0; i < musica.size(); i++) {
			musica.at(i)->push_data();
			musica.at(i)->show_data();
		}
	}
	void add_Horario(string actividad, string horaI, string horaF) {
		horario.push_back(new CHorario<string>(actividad, horaI, horaF));
	}
	void mostrar_Horario() {
		for (int i = 0; i < horario.size(); i++) {
			horario.at(i)->insertarhorario();
			horario.at(i)->saveData();
		}
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

