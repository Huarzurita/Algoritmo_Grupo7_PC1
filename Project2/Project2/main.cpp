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
	string a,titulo,fecha,hora,urgencia,completado;
	bool completo;
	vector<string> par;
	fstream archivo("tareas.txt");
	int opc;
	creadores();
	Controller* controller = new Controller();
	while (true) {
		do {
			system("cls");
			cout << "\n\t -------------------------MENU-------------------------";
			cout << "\n\t 1. Agregar Tarea";
			cout << "\n\t 2. Agregar Evento";
			cout << "\n\t 3. Agregar Recordatorio";
			cout << "\n\t 4. Agregar Nota";
			cout << "\n\t 5. Bye bye";
			cout << "\n\t    Ingresar opción:"; cin >> opc;
		} while (opc != 1 && opc != 2 && opc != 3 && opc != 4);
		system("cls");
		switch (opc) {
		case 1:
			cout << "INGRESE LOS DATOS SOLICITADOS" << "\n";
			getline(cin, a);
			cout << "\n Ingresar titulo de la tarea: \n";
			getline(cin, titulo);
			cout << "\n Ingresar fecha de la tarea: ";
			getline(cin, fecha);
			cout << "\n Ingresar hora de la tarea: ";
			getline(cin, hora);
			cout << "\n Ingresar urgencia de la tarea: ";
			getline(cin, urgencia);
			do
			{
				cout << "\n Ingresar si esta completado de la tarea (SI o NO): ";
				getline(cin, completado);
			} while (completado != "SI" && completado != "NO");
			if (completado == "SI")
				completo = true;
			else
				completo = false;
			
			controller->addTarea(completo,titulo,fecha,hora,urgencia);
			controller->guardarTareas();
			controller->mostrarTareas();
			_getch();


			break;
		case 2:

			_getch();
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			exit(0);
			break;
		}
	}
	_getch();
	return 0;
}

/*
remove("tareas.txt");
cout << "Introduzca el elemento a eliminar";
cin >> aux;
_getch();
*/
