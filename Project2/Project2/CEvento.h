#pragma once
#include "Capp.h"
template<class t>
class CEvento
{
private:
	t lugar,titulo, fecha, hora, descripcion, urgencia;
public:
	CEvento(t lugar, t titulo, t fecha, t hora, t descripcion, t urgencia) {
		this->titulo = titulo;
		this->fecha = fecha;
		this->hora = hora;
		this->urgencia = urgencia;
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
	void save_Datas(vector<string>datas) {
		fstream file("tareas.txt");
		if (!file.fail())
		{
			for (int i = 0; i < datas.size(); i++) {
				file << datas.at(i) << "\n";
			}
			file.flush();
			file.close();
		}
	}
	~CEvento() {}
};
