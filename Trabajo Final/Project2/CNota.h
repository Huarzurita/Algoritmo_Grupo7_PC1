#pragma once
#include "Capp.h"
template<class Generic>
class CNota 
{
private:
	Generic titulo, descripcion;
public:
	CNota(Generic titulo, Generic descripcion):titulo(titulo),descripcion(descripcion) {}
	Generic getTitulo() { return titulo; }
	Generic getDescripcion() { return descripcion; }
	~CNota() {}
};
