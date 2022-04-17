#pragma once
#include <vector>
#include "CEvento.h"
#include "CNota.h"
#include "CRecordatorio.h"
#include "CTarea.h"
using namespace std;
template<class t1>
class Controller
{
private:
	vector<CTarea*>tareas;
	vector<CRecordatorio*>recordatorios;
	vector<CNota*>notas;
	vector<CEvento*>eventos;


public:
	Controller() {};
	~Controller() {};

	void addTarea(t1 completado, t1 titulo, t1 fecha, t1 hora, t1 urgencia) {
		tareas.push_back(new CTarea<t1>(completado, titulo, fecha, hora, urgencia));
	}
	void addRecordatorio(t1 titulo, t1 fecha, t1 hora, t1 urgencia) {
		recordatorios.push_back(new CRecordatorio<t1>(titulo, fecha, hora, urgencia));
	}
	void addNota(t1 titulo, t1 descripcion) {
		notas.push_back(new CNota<t1>(titulo, descripcion));
	}
	void addEvento(t1 lugar, t1 titulo, t1 fecha, t1 hora, t1 descripcion, t1 urgencia) {
		eventos.push_back(new CEvento<t1>(lugar, titulo, fecha, hora, descripcion, urgencia));
	}

};
