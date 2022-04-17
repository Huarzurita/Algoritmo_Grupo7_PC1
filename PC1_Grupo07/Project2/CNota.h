#pragma once
#include "Capp.h"
template<class t>
class CNota 
{
private:
	t titulo, descripcion;
public:
	CNota(t titulo, t descripcion) {
		this->titulo = titulo;
		this->descripcion = descripcion;
	}
	t getTitulo() { return titulo; }
	t getDescripcion() { return descripcion; }
	~CNota() {}
};
