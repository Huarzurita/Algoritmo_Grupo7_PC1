#include "Controller.h"
#include "CQuizz.h"
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
void imprimir(function<void()>funcion) {
	funcion();
}

int main() {
	setlocale(LC_ALL, "esp");
	srand(time(NULL));
	Quizz<string> q = Quizz<string>();
	string a, titulo, fecha, hora, urgencia, completado, lugar, descripcion, contacto, correo, telefono,cancion,genero,artista, actividad,horaI, horaF;
	int opc, opc2,opc3;
	imprimir(creadores);
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
			cout << "\n\t 7. Agregar Horario";
			cout << "\n\t 8. Mostrar Datos";
			cout << "\n\t 9. QUIZZ :D";
			cout << "\n\t 10. Bye bye";
			cout << "\n\t    Ingresar opción:"; cin >> opc;
		} while (opc != 1 && opc != 2 && opc != 3 && opc != 4 && opc != 5 && opc != 6 && opc != 7 && opc != 8 && opc != 9 && opc != 10);
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
			controller->add_Agenda(contacto, correo, telefono);
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
			controller->add_Musica(cancion, genero, artista);
			_getch();
			break;
		case 7:
			Console::ForegroundColor = ConsoleColor::Green;
			cout << "Ingrese los datos solicitados:\n"; getline(cin, a);
			cout << "Ingrese el nombre de la actividad:\n"; getline(cin, actividad);
			cout << "Ingrese la hora inicial:\n"; getline(cin, horaI);
			cout << "Ingrese la hora final:\n"; getline(cin, horaF);
			controller->add_Horario(actividad, horaI, horaF);
			_getch();
			break;
			break;
		case 8:
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
				cout << "\n\t 7. Mostrar Horario";
				cout << "\n\t 8. Bye bye";
				cout << "\n\t    Ingresar opción:"; cin >> opc2;
			} while (opc2 != 1 && opc2 != 2 && opc2 != 3 && opc2 != 4 && opc2 != 5 && opc2 != 6 && opc2 != 7 && opc2 != 8);
			system("cls");
			break;
		case 9:
			do
			{
				system("cls");
				Console::ForegroundColor = ConsoleColor::Yellow;
				cout << " [1] Insertar pregunta al quizz" << "\n";
				cout << " [2] Comenzar Quizz" << "\n";
				cout << " [3] Salir" << "\n";
				cin >> opc3;

				if (opc3 == 1) {
					string dp, dr;
					system("cls");
					cout << "Ingrese pregunta " << "\n";
					cin >> dp;
					cout << "Ingrese rspta" << "\n";
					cin >> dr;

					q.Push(dp, dr);
					system("pause");
				}
				if (opc3 == 2) {
					system("cls");
					cout << "QUIZZ: " << "\n";
					q.Print();
					
				}
			} while (opc3 != 3);


			break;
		case 10:
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
				controller->mostrar_Agenda();
				_getch();
				break;
			case 6:
				controller->mostrar_Musica();
				_getch();
				break;
			case 7:
				controller->mostrar_Horario();
				_getch();
				break;
			case 8:
				exit(0);
				break;
			}
		};
		if (opc == 8)
		{
			fun();
		}
	}
	_getch();
	return 0;
}

