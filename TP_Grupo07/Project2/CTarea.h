#pragma once
#include "Capp.h"
template<class Generic>
class CTarea
{
private:
	Generic titulo, fecha, hora, urgencia, completado;
public:
	CTarea(Generic completado, Generic titulo, Generic fecha, Generic hora, Generic urgencia):completado(completado),titulo(titulo), fecha(fecha), hora(hora), urgencia(urgencia) {}
	~CTarea() {}
	Generic getTitulo() { return titulo; }
	Generic getFecha() { return fecha; }
	Generic getHora() { return hora; }
	Generic getUrgencia() { return urgencia; }
	Generic getCompletado() { return completado; }
};
