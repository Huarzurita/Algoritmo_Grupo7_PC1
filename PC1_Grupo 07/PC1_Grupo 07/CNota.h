#pragma once
#include "Capp.h"
template<class t1>
class CNota : public App
{
public:
	CNota(t1 titulo, t1 descripcion) :App(titulo, descripcion) {
		this->titulo = titulo;
		this->descripcion = descripcion;
	}
	void save_data(string line) {
		fstream file("tareas.txt");
		vector<string>data;
		if (file.is_open()) {
			for (int i = 0; i < 4; i++)
			{
				cout << "\n Ingresar tarea: ";
				getline(cin, line);//el getline solo lee con string
				data.push_back(line);
			}
		}
		save_Datas(data);
	}
	void show_data(string line) {
		fstream file("tareas.txt");
		file.open("tareas.txt", ios::in);
		cout << "___________________________________________________________________\n";
		while (!file.eof()) {
			getline(file, line);
			cout << line << "\n";
		}
		cout << "___________________________________________________________________\n";
		_getch();
	}
	~CNota() {}
};
