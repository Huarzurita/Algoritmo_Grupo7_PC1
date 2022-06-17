#pragma once
#include "Capp.h"
template<class Generic>
class CEvento
{
private:
	Generic lugar,titulo, fecha, hora, descripcion, urgencia;
public:
	CEvento(Generic lugar, Generic titulo, Generic fecha, Generic hora, Generic descripcion, Generic urgencia):
	lugar(lugar),titulo(titulo),fecha(fecha),hora(hora),descripcion(descripcion),urgencia(urgencia) {}
	Generic getTitulo() { return titulo; }
	Generic getFecha() { return fecha; }
	Generic getHora() { return hora; }
	Generic getUrgencia() { return urgencia; }
	Generic getDescripcion() { return descripcion; }
	Generic getLugar() { return lugar; }
	~CEvento() {}
};
