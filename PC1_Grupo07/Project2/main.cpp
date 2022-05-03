#include "Controller.h"
using namespace System;
using namespace std;

void creadores() {
	Console::ForegroundColor = ConsoleColor::Magenta;
	Console::SetCursorPosition(20, 5);
	cout << "-----------------------------------------------------------------------------------";
	Console::SetCursorPosition(20, 6);
	cout << "----------------------------------ORGANIZE YOU-------------------------------------";
	Console::SetCursorPosition(20, 7);
	cout << "-----------------------------------------------------------------------------------";
	Console::SetCursorPosition(40, 10);
	cout << "CREADO POR:";
	Console::SetCursorPosition(40, 11);
	cout << "André Alonso Arroyo Ormeño";
	Console::SetCursorPosition(40, 12);
	cout << "Jessica Elizabeth Comettant Rubiños";
	Console::SetCursorPosition(40, 13);
	cout << "Miguel Alejandro Daniel Huarcaya Chavez";
	_getch();
	system("cls");
}
int main() {
	setlocale(LC_ALL, "esp");
	string a, titulo, fecha, hora, urgencia, completado, lugar, descripcion, contacto, correo, telefono,cancion,genero,artista;
	int opc, opc2;
	creadores();
	Controller* controller = new Controller();
	while (true) {
		do {
			system("cls");
			Console::ForegroundColor = ConsoleColor::Cyan;
			cout << "\n\t -------------------------MENU-------------------------";
			cout << "\n\t 1. Agregar Tarea";
			cout << "\n\t 2. Agregar Evento";
			cout << "\n\t 3. Agregar Recordatorio";
			cout << "\n\t 4. Agregar Nota";
			cout << "\n\t 5. Agregar Contacto";
			cout << "\n\t 6. Agregar Musica";
			cout << "\n\t 7. Mostrar Datos";
			cout << "\n\t 8. Bye bye";
			cout << "\n\t    Ingresar opción:"; cin >> opc;
		} while (opc != 1 && opc != 2 && opc != 3 && opc != 4 && opc != 5 && opc != 6 && opc != 7 && opc != 8);
		system("cls");
		switch (opc) {
		case 1:
			Console::ForegroundColor = ConsoleColor::Gray;
			cout << " INGRESE LOS DATOS SOLICITADOS" << "\n";
			getline(cin, a);
			cout << "\n Ingresar título de la tarea: \n";
			getline(cin, titulo);
			cout << "\n Ingresar fecha de la tarea:\n ";
			getline(cin, fecha);
			cout << "\n Ingresar hora de la tarea: \n";
			getline(cin, hora);
			cout << "\n Ingresar urgencia de la tarea: \n";
			getline(cin, urgencia);
			do
			{
				cout << "\n Ingresar si la tarea ha sido completada (SI o NO): ";
				getline(cin, completado);
			} while (completado != "SI" && completado != "NO");
			controller->addTarea(completado, titulo, fecha, hora, urgencia);
			controller->guardarTareas();
			_getch();
			break;
		case 2:
			Console::ForegroundColor = ConsoleColor::Gray;
			cout << " INGRESE LOS DATOS SOLICITADOS" << "\n";
			getline(cin, a);
			cout << "\n Ingresar título del evento: \n";
			getline(cin, titulo);
			cout << "\n Ingresar fecha del evento:  \n";
			getline(cin, fecha);
			cout << "\n Ingresar hora del evento: \n";
			getline(cin, hora);
			cout << "\n Ingresar lugar del evento: \n";
			getline(cin, lugar);
			cout << "\n Ingresar urgencia del evento: \n";
			getline(cin, urgencia);
			cout << "\n Ingresar descripción del evento: \n";
			getline(cin, descripcion);
			controller->addEvento(lugar, titulo, fecha, hora, descripcion, urgencia);
			controller->guardarEventos();

			_getch();
			break;
		case 3:
			Console::ForegroundColor = ConsoleColor::Gray;
			cout << " INGRESE LOS DATOS SOLICITADOS" << "\n";
			getline(cin, a);
			cout << "\n Ingresar título del recordatorio: \n";
			getline(cin, titulo);
			cout << "\n Ingresar fecha del recordatorio:  \n";
			getline(cin, fecha);
			cout << "\n Ingresar hora del recordatorio: \n";
			getline(cin, hora);
			cout << "\n Ingresar urgencia del recordatorio: \n";
			getline(cin, urgencia);
			controller->addRecordatorio(titulo, fecha, hora, urgencia);
			controller->guardarRecordatorios();
			_getch();
			break;
		case 4:
			Console::ForegroundColor = ConsoleColor::Gray;
			cout << " INGRESE LOS DATOS SOLICITADOS" << "\n";
			getline(cin, a);
			cout << "\n Ingresar título de la nota: \n";
			getline(cin, titulo);
			cout << "\n Ingresar descripción de la nota:  \n";
			getline(cin, descripcion);
			controller->addNota(titulo, descripcion);
			controller->guardarNotas();
			_getch();
			break;
		case 5:
			Console::ForegroundColor = ConsoleColor::Gray;
			cout << " INGRESE LOS DATOS SOLICITADOS" << "\n";
			getline(cin, a);
			cout << "\n Ingresar nombre del contacto: \n";
			getline(cin, contacto);
			cout << "\n Ingresar correo del contacto: \n";
			getline(cin, correo);
			cout << "\n Ingresar teléfono del contacto:  \n";
			getline(cin, telefono);
			controller->addAgenda(contacto,correo,telefono);
			_getch();
			break;
		case 6:
			Console::ForegroundColor = ConsoleColor::Gray;
			cout << " INGRESE LOS DATOS SOLICITADOS" << "\n";
			getline(cin, a);
			cout << "\n Ingresar nombre de la canción: \n";
			getline(cin, cancion);
			cout << "\n Ingresar género de la canción: \n";
			getline(cin, genero);
			cout << "\n Ingresar artista de la canción:  \n";
			getline(cin, artista);
			controller->addMusica(cancion, genero, artista);
			_getch();
			break;
		case 7:
			do {
				system("cls");
				Console::ForegroundColor = ConsoleColor::Cyan;
				cout << "\n\t -------------------------MENU-------------------------";
				cout << "\n\t 1. Mostrar Tareas";
				cout << "\n\t 2. Mostrar Eventos";
				cout << "\n\t 3. Mostrar Recordatorios";
				cout << "\n\t 4. Mostrar Notas";
				cout << "\n\t 5. Mostrar Contactos";
				cout << "\n\t 6. Mostrar Canciones";
				cout << "\n\t 7. Bye bye";
				cout << "\n\t    Ingresar opción:"; cin >> opc2;
			} while (opc2 != 1 && opc2 != 2 && opc2 != 3 && opc2 != 4 && opc2 != 5 && opc2 != 6 && opc2 != 7);
			system("cls");
			break;
		case 8:
			exit(0);
			break;
		}
		auto fun = [opc2, controller]() {//lambda
			switch (opc2)
			{
			case 1:
				controller->mostrarTareas();
				_getch();
				break;
			case 2:
				controller->mostrarEventos();
				_getch();
				break;
			case 3:
				controller->mostrarRecordatorios();
				_getch();
				break;
			case 4:
				controller->mostrarNotas();
				_getch();
				break;
			case 5:
				controller->mostrarAgenda();
				_getch();
				break;
			case 6:
				controller->mostrarMusica();
				_getch();
				break;
			case 7:
				exit(0);
				break;
			}
		};
		if (opc == 7)
		{
			fun();
		}
	}
	_getch();
	return 0;
}

