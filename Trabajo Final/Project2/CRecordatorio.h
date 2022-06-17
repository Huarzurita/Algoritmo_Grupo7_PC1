#pragma once
#include "Capp.h"
template<class Generic>
class CRecordatorio 
{
private:
	Generic titulo, fecha, hora, urgencia;
public:
	CRecordatorio(Generic titulo, Generic fecha, Generic hora, Generic urgencia):titulo(titulo),fecha(fecha),hora(hora),urgencia(urgencia) {}
	Generic getTitulo() { return titulo; }
	Generic getFecha() { return fecha; }
	Generic getHora() { return hora; }
	Generic getUrgencia() { return urgencia; }
	~CRecordatorio() {}
};
