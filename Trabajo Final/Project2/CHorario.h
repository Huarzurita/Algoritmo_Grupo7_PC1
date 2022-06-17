#pragma once
#include "Capp.h"
template<class Generic>
class CHorario
{
public:
	CHorario(Generic actividad, Generic hora_I, Generic hora_F) : actividad(actividad), hora_I(hora_I), hora_F(hora_F) {
		archivo.open("Horarios.txt", ios::app);
	}
	~CHorario() {}
	Generic getactividad() { return actividad; }
	Generic gethora_I() { return hora_I; }
	Generic gethora_F() { return hora_F; }
	void mostrar() {
		cout << "\n";
		cout << "\t |--------------------------------------------------------------------------------------------|" << "\n";
		cout << "\t |                                   °REGISTRO DE ACTIVIDADES°                                |" << "\n";
		cout << "\t |--------------------------------------------------------------------------------------------|" << "\n";
		cout << "\t      Nombre de la actividad: " << actividad << endl;
		cout << "\t      Hora de inicio: " << hora_I << endl;
		cout << "\t      Hora de culminación: " << hora_F << endl;
		cout << "\t |--------------------------------------------------------------------------------------------|" << "\n";
		cout << "\n";
	}
	void guardar() {
		archivo << "--------------------------------------------------------------------------------------------" << "\n";
		archivo << "                                   °REGISTRO DE ACTIVIDADES°                                " << "\n";
		archivo << "--------------------------------------------------------------------------------------------" << "\n";
		archivo << "    Nombre de la actividad: " << actividad << endl;
		archivo << "    Hora de inicio: " << hora_I << endl;
		archivo << "    Hora de culminación: " << hora_F << endl;
		archivo << "--------------------------------------------------------------------------------------------" << "\n";
		archivo << "\n";
	}
private:
	Generic actividad, hora_I, hora_F;
	fstream archivo;
};


