#pragma once
#include "Capp.h"
template<class t>
class CTarea 
{
private:
	t titulo, fecha, hora, urgencia;
	bool completado;
public:
	CTarea(bool completado,t titulo, t fecha, t hora, t urgencia) {
		this->titulo = titulo;
		this->fecha = fecha;
		this->hora = hora;
		this->urgencia = urgencia;
	}
	~CTarea() {}

	t getTitulo() { return titulo; }
	t getFecha() { return fecha; }
	t getHora() { return hora; }
	t getUrgencia() { return urgencia; }
	bool getCompletado() { return completado; }


};
