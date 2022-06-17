#pragma once
#include "Capp.h"
template<class Generic,class Generic_>
class CTarea
{
private:
	Generic titulo, fecha, urgencia, completado;
	Generic_ hora;
public:
	CTarea(Generic completado, Generic titulo, Generic fecha, Generic_ hora, Generic urgencia)
		:completado(completado),titulo(titulo), fecha(fecha), hora(hora), urgencia(urgencia) {}
	~CTarea() {}
	Generic getTitulo() { return titulo; }
	Generic getFecha() { return fecha; }
	Generic_ getHora() { return hora; }
	Generic getUrgencia() { return urgencia; }
	Generic getCompletado() { return completado; }
};
