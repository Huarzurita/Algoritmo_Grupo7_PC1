#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "sstream"
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
int main() {
	setlocale(LC_ALL, "esp");
	string linea;
	vector<string> par;
	fstream archivo("tareas.txt");
	int opc;
	creadores();
	while (true) {
		do {
			system("cls");
			cout << "\n\t -------------------------MENU-------------------------";
			cout << "\n\t 1. Agregar tarea";
			cout << "\n\t 2. Borrar tarea";
			cout << "\n\t 3. Revisar tareas";
			cout << "\n\t 4. Bye bye";
			cout << "\n\t    Ingresar opción:"; cin >> opc;
		} while (opc != 1 && opc != 2 && opc != 3 && opc != 4);
		system("cls");
		switch (opc) {
		case 1:
			
			break;
		case 2:

			_getch();
			break;
		case 3:

			break;
		case 4:
			exit(0);
			break;
		}
	}
	_getch();
	return 0;
}
