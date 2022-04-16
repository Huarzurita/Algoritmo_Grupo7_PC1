#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include<time.h>
#include "sstream"
using namespace std;
template<class t1> //string y int
class App {
protected:
	t1 titulo, descripcion, fecha, hora, urgencia;
public:
	App(t1 titulo, t1 fecha, t1 hora, t1 urgencia) {

	}
	App(t1 titulo, t1 descripcion) {

	}
	App(t1 titulo, t1 fecha, t1 hora, t1 descripcion, t1 urgencia) {


	}
	~App() {}
	t1 gettitulo() { return titulo; }
	t1 getdescripcion() { return descripcion; }

	t2 getfecha() { return fecha; }
	t2 gethora() { return hora; }
	int geturgencia() { return urgencia; }
	void settitulo(t1 v) { titulo = v; }
	void setdescripcion(t1 v) { descripcion = v; }
	void setfecha(t2 v) { fecha = v; }
	void sethora(t2 v) { hora = v; }
	void seturgencia(int v) { urgencia = v; }

	t1 getfecha() { return fecha; }
	t1 gethora() { return hora; }
	int geturgencia() { return urgencia; }
	void settitulo(t1 v) { titulo = v; }
	void setdescripcion(t1 v) { descripcion = v; }
	void setfecha(t1 v) { fecha = v; }
	void sethora(t1 v) { hora = v; }
	void seturgencia(t1 v) { urgencia = v; }
	void save_Datas(vector<t1>datas) {
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

};

