#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "sstream"
#include "Controller.h"
using namespace System;
using namespace std;
void creadores() {
	Console::SetCursorPosition(20, 5);
	cout << "-----------------------------------------------------------------------------------";
	Console::SetCursorPosition(20, 6);
	cout << "----------------------------------ORGANIZE YOU-------------------------------------";
	Console::SetCursorPosition(20, 7);
	cout << "-----------------------------------------------------------------------------------";
	Console::SetCursorPosition(55, 10);
	cout << "CREADO POR:";
	Console::SetCursorPosition(55, 11);
	cout << "André Alonso Arroyo Ormeño";
	Console::SetCursorPosition(55, 12);
	cout << "Jessica Elizabeth Comettant";
	Console::SetCursorPosition(55, 13);
	cout << "Miguel ";
	_getch();
	system("cls");
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "esp");
	string titulo, fecha, hora, completado, urgencia,linea;
	vector<string> par;
	fstream archivo("tareas.txt");
	int opc;
	Controller<int>* controller = new Controller<int>();
	creadores();
	while (true) {
		do {
			system("cls");
			cout << "\n\t -------------------------MENU-------------------------";
			cout << "\n\t 1. Agregar tarea";
			cout << "\n\t 2. Borrar tarea";
			cout << "\n\t 3. Revisar tareas";
			cout << "\n\t 4. Bye byeguiy";
			cout << "\n\t    Ingresar opción:"; cin >> opc;
		} while (opc != 1 && opc != 2 && opc != 3 && opc != 4);
		system("cls");
		switch (opc) {
		case 1:
			cout << "\n Ingresar Titulo de la tareaaaa: ";
			getline(cin, titulo);
			cout << "\n Ingresar Fecha de la tarea: ";
			getline(cin, fecha);
			cout << "\n Ingresar Hora de la tarea: ";
			getline(cin, hora);
			cout << "\n Ingresar Urgencia de la tarea (1 al 10) ";
			getline(cin, urgencia);
			cout << "\n Ingresar Si la tarea esta completada o no (SI o NO) ";
			getline(cin, completado);
			controller->addTarea(0, 0, 0, 0, 0);
			_getch();
			break;


		case 3:
			archivo.open("tareas.txt", ios::in);
			cout << "___________________________________________________________________\n";
			while (!archivo.eof()) {
				getline(archivo, linea);
				cout << linea << "\n";
			}
			cout << "___________________________________________________________________\n";
			_getch();
			archivo.close();

			break;
		case 4:
			exit(0);
			break;
		}
	}
	_getch();
	return 0;
}