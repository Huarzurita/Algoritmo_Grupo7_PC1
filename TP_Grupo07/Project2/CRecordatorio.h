#pragma once
#include "Capp.h"
template<class t>
class CRecordatorio 
{
private:
	t titulo, fecha, hora, urgencia;
public:
	CRecordatorio(t titulo, t fecha, t hora, t urgencia) {
		this->titulo = titulo;
		this->fecha = fecha;
		this->hora = hora;
		this->urgencia = urgencia;
	}
	t getTitulo() { return titulo; }
	t getFecha() { return fecha; }
	t getHora() { return hora; }
	t getUrgencia() { return urgencia; }
	~CRecordatorio() {}
};
