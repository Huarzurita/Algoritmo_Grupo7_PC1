#pragma once
#include "CEvento.h"
#include "CNota.h"
#include "CRecordatorio.h"
#include "CTarea.h"

template<class t1>
class Controller
{
private:
	vector<CTarea*>tareas;
	vector<CRecordatorio*>recordatorios;
	vector<CNota*>notas;
	vector<CEvento*>eventos;

public:
	Controller() {
	};
	~Controller() {};

	addTarea(t1 completado,t1 titulo, t1 fecha, t1 hora, t1 urgencia) {
		tareas.push_back(new CTarea(completado,titulo,fecha,hora,urgencia))
	}
	addRecordatorio(t1 titulo, t1 fecha, t1 hora, t1 urgencia) {
		recordatorios.push_back(new CRecordatorio(titulo,fecha,hora,urgencia))
	}
	addCNota(t1 titulo, t1 descripcion) {
		notas.push_back(new CNota(titulo,descripcion))
	}
	addCEvento(t1 lugar,t1 titulo, t1 fecha, t1 hora,t1 descripcion, t1 urgencia) {
		eventos.push_back(new CEventos(lugar,titulo,fecha,hora,descripcion,urgencia))
	}




};
