#pragma once
#include "CEvento.h"
#include "CNota.h"
#include "CRecordatorio.h"
#include "CTarea.h"
#include "CAgenda.h"
#include "Queue.h"
#include "CHorario.h"
#include "CMusica.h"
#include "CQuizz.h"
#include "List.h"
#include "AdvanceSort.h"
#include "Stack.h"
#include "DataGenerator.h"
#include "Registros.h"
class Controller
{
private:
	vector<CTarea<string,int>*>tareas;vector<CRecordatorio<string>*>recordatorios;
	vector<CNota<string>*>notas;vector<CEvento<string>*>eventos;
	vector<Contact<string,long>*>agenda;vector<long>telefonos; Queue<Music<string>*>*musica;
	Stack<CHorario<string>*>*horario;List<Quizz<string>*>* quizz;
	fstream archivoTareas, archivoEventos, archivoNotas, archivoRecordatorios,archivoAgenda;
public:
	Controller() {
		horario = new Stack<CHorario<string>*>([](CHorario<string>* a) {a->mostrar(); }, [](CHorario<string>* a) { a->guardar(); });
		musica = new Queue<Music<string>*>([](Music<string>* a) {a->mostrar(); }, [](Music<string>* a) { a->guardar(); });
		quizz = new List<Quizz<string>*>([](Quizz<string>* a) {a->Print();}, [](Quizz<string>* a) { a->Save(); });
	}
	~Controller() {};
	void addTarea(string completado, string titulo, string fecha, int hora, string urgencia) {
		tareas.push_back(new CTarea<string,int>(completado, titulo, fecha, hora, urgencia));}
	void addRecordatorio(string titulo, string fecha, string hora, string urgencia) {
		recordatorios.push_back(new CRecordatorio<string>(titulo, fecha, hora, urgencia));}
	void addNota(string titulo, string descripcion) {
		notas.push_back(new CNota<string>(titulo, descripcion));}
	void addEvento(string lugar, string titulo, string fecha, string hora, string descripcion, string urgencia) {
		eventos.push_back(new CEvento<string>(lugar, titulo, fecha, hora, descripcion, urgencia));}
	void add_Agenda(long telefono, string correo, string contacto) {
		agenda.push_back(new Contact<string, long>(telefono, correo, contacto));
		telefonos.push_back(telefono);}
	void add_Musica(string cancion, string genero, string artista) {
		musica->enqueque(new Music<string>(cancion, genero, artista));
		musica->save(new Music<string>(cancion, genero, artista));
	}
	void add_Horario(string actividad, string horaI, string horaF) {
		horario->push_back(new CHorario<string>(actividad, horaI, horaF));
		horario->save(new CHorario<string>(actividad, horaI, horaF));
	}
	void add_quizz(string pregunta, string respuesta) {
		quizz->pushBack(new Quizz<string>(pregunta, respuesta));
		quizz->save(new Quizz<string>(pregunta, respuesta));
	}
	void ordenar() {
		Console::ForegroundColor = ConsoleColor::Cyan;
		AdvanceSort<long>* auxiliar = new AdvanceSort<long>(telefonos, telefonos.size(),
			[](long valor) -> void { cout << "\t Teléfono: " << valor << endl; },
			[](long a, long b) -> bool { return a > b; });
		auxiliar->radixsort();
		cout << "\t Teléfonos recientemente ordenados... "; cout << endl;
		auxiliar->print();
	}
	void Informacion(long aux) {
		Console::ForegroundColor = ConsoleColor::Green;
		for (size_t i = 0; i < telefonos.size(); i++) {
			if (aux == agenda.at(i)->gettelefono()) {
				agenda.at(i)->mostrar();
			}
		}
	}
	void imprimir_ordenar_table() {
		Registros* d = new Registros();
		cout << "Simulación de Datos de Usuarios:" << endl;
		Console::ForegroundColor = ConsoleColor::Green;
		d->getList()->print();
		cout << "---------------------------------------------" << endl;
		d->Merge_Sort();
		Console::ForegroundColor = ConsoleColor::Cyan;
		cout << "Simulación de Datos de Ordenados:" << endl;
		d->getList()->print();
		cout << "---------------------------------------------" << endl;
		Console::ForegroundColor = ConsoleColor::Yellow;
		cout << "Hash Table:" << endl;
		d->Hash_Table(); 
		system("pause");
	}
	void treap() {
		Registros* d = new Registros();
		d->delete_treap();
	}
	void generador() {
		DataGenerator* generator = new DataGenerator("Generador.csv");
		generator->generate(1000000);
	}
	void mostrar_Musica() {musica->print();}
	void mostrar_Horario() {horario->print();}
	void mostrar_quizz() {quizz->print();}
	void mostrarAgenda() {
		Random r;
		string linea;
		fstream archivo;
		archivo.open("Contactos.txt", ios::in);
		Console::ForegroundColor = ConsoleColor(r.Next(1, 16));
		while (!archivo.eof()) {
			getline(archivo, linea);
			cout << linea << "\n";
		}
		_getch();
		archivo.close();
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
	void guardar_Agenda() {
		archivoAgenda.open("Contactos.txt", ios::out);
		if (archivoAgenda.fail())
			cout << "No se pudo abrir el archivo " << "\n";
		for (size_t i = 0; i < agenda.size(); i++)
		{
			archivoAgenda << "--------------------------------------------------------------------------------------------" << "\n";
			archivoAgenda << "                                  °INFORMACIÓN DEL CONTACTO°                                " << "\n";
			archivoAgenda << "--------------------------------------------------------------------------------------------" << "\n";
			archivoAgenda << "     Nombre del contacto: " << agenda[i]->getcontacto() << endl;
			archivoAgenda << "     Correo del contacto: " << agenda[i]->getcorreo() << endl;
			archivoAgenda << "     Telefono del contacto: " << agenda[i]->gettelefono() << endl;
			archivoAgenda << "--------------------------------------------------------------------------------------------" << "\n";
		}
		archivoAgenda.close();
	}
	void guardarTareas() {
		archivoTareas.open("Tareas.txt", ios::out);
		if (archivoTareas.fail())
			cout << "No se pudo abrir el archivo " << "\n";
		for (int i = 0; i < tareas.size(); i++)
		{
			archivoTareas << "--------------------------------------------------------------------------------------------" << "\n";
			archivoTareas << "                                   °INFORMACIÓN DE LA TAREA°                                " << "\n";
			archivoTareas << "--------------------------------------------------------------------------------------------" << "\n";
			archivoTareas << "  Título de la tarea: "<< tareas[i]->getTitulo() << "\n";
			archivoTareas << "  Fecha de la tarea: " << tareas[i]->getFecha() << "\n";
			archivoTareas << "  Hora de la tarea: " << tareas[i]->getHora()  << "\n";
			archivoTareas << "  Urgencia de la tarea: " << tareas[i]->getUrgencia() << "\n";
			archivoTareas << "  Estado de la tarea: " << tareas[i]->getCompletado() << "\n";
			archivoTareas << "--------------------------------------------------------------------------------------------" << "\n";
		}
		archivoTareas.close();
	}
	void guardarEventos() {
		archivoEventos.open("Eventos.txt", ios::out);
		if (archivoEventos.fail())
			cout << "No se pudo abrir el archivo " << "\n";
		for (int i = 0; i < eventos.size(); i++)
		{
			archivoEventos << "--------------------------------------------------------------------------------------------" << "\n";
			archivoEventos << "                                   °INFORMACIÓN DEL EVENTO°                                 " << "\n";
			archivoEventos << "--------------------------------------------------------------------------------------------" << "\n";
			archivoEventos << "  Título del evento: " << eventos[i]->getTitulo() << "\n";
			archivoEventos << "  Fecha del evento: " << eventos[i]->getFecha() << "\n";
			archivoEventos << "  Hora del evento: " << eventos[i]->getHora()  << "\n";
			archivoEventos << "  Urgencia del evento: " << eventos[i]->getUrgencia() << "\n";
			archivoEventos << "  Descripción del evento: " << eventos[i]->getDescripcion() << "\n";
			archivoEventos << "  Lugar del evento: " << eventos[i]->getLugar()  << "\n";
			archivoEventos << "--------------------------------------------------------------------------------------------" << "\n";
		}
		archivoEventos.close();
	}
	void guardarNotas() {
		archivoNotas.open("Notas.txt", ios::out);
		if (archivoNotas.fail())
			cout << "No se pudo abrir el archivo " << "\n";
		for (int i = 0; i < notas.size(); i++)
		{
			archivoNotas << "--------------------------------------------------------------------------------------------" << "\n";
			archivoNotas << "                                 °INFORMACIÓN DE LA NOTA°                                   " << "\n";
			archivoNotas << "--------------------------------------------------------------------------------------------" << "\n";
			archivoNotas << " Título de la nota: " << notas[i]->getTitulo()<< "\n";
			archivoNotas << " Descripción de la nota: " << notas[i]->getDescripcion()  <<"\n";
			archivoNotas << "--------------------------------------------------------------------------------------------" << "\n";
		}
		archivoNotas.close();
	}
	void guardarRecordatorios() {
		archivoRecordatorios.open("Recordatorios.txt", ios::out);
		if (archivoRecordatorios.fail())
			cout << "No se pudo abrir el archivo " << "\n";
		for (int i = 0; i < recordatorios.size(); i++)
		{
			archivoRecordatorios << "--------------------------------------------------------------------------------------------"<< "\n";
			archivoRecordatorios << "                                 °INFORMACIÓN DEL RECORDATORIO°                             " << "\n";
			archivoRecordatorios << "--------------------------------------------------------------------------------------------" << "\n";
			archivoRecordatorios << "  Título del recordatorio: " << recordatorios[i]->getTitulo() << "\n";
			archivoRecordatorios << "  Fecha del recordatorio: " << recordatorios[i]->getFecha() << "\n";
			archivoRecordatorios << "  Hora del recordatorio: " << recordatorios[i]->getHora() << "\n";
			archivoRecordatorios << "  Urgencia del recordatorio: " <<recordatorios[i]->getUrgencia() << "\n";
			archivoRecordatorios << "--------------------------------------------------------------------------------------------" << "\n";
		}
		archivoRecordatorios.close();
	}
};

