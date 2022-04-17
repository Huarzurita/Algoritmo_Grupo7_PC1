#pragma once
#include <vector>
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
	Controller() {};
	~Controller() {};

};
