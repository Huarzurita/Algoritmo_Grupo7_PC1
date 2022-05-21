#pragma once
#include "Capp.h"
template<class t>
class CEvento
{
private:
	t lugar,titulo, fecha, hora, descripcion, urgencia;
public:
	CEvento(t lugar, t titulo, t fecha, t hora, t descripcion, t urgencia) {
		this->lugar = lugar;
		this->titulo = titulo;
		this->fecha = fecha;
		this->hora = hora;
		this->urgencia = urgencia;
		this->descripcion = descripcion;
	}
	t getTitulo() { return titulo; }
	t getFecha() { return fecha; }
	t getHora() { return hora; }
	t getUrgencia() { return urgencia; }
	t getDescripcion() { return descripcion; }
	t getLugar() { return lugar; }
	~CEvento() {}
};
