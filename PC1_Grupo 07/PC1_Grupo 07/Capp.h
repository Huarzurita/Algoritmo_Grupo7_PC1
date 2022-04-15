#pragma once
#include<iostream>
#include<conio.h>
#include<time.h>
using namespace std;
template<class t1, class t2 > //string y int
class App 
{
private:
	t1 titulo;
	t1 descripcion;
	t2 fecha;
	t2 hora;
	int urgencia;
public:
	App(t1 titulo,t2 fecha,t2 hora, int urgencia) {

	}
	App1(t1 titulo, t1 descripcion) {

	}
	App2(t1 titulo, t2 fecha, t2 hora, t1 descripcion, int urgencia) {

	}
	~App(){}
	t1 gettitulo(){return titulo;}
	t1 getdescripcion(){return descripcion;}
	t2 getfecha(){return fecha;}
	t2 gethora(){return hora;}
	int geturgencia() { return urgencia; }
	void settitulo(t1 v){titulo=v;}
	void setdescripcion(t1 v){descripcion=v;}
	void setfecha(t2 v){fecha=v;}
	void sethora(t2 v) { hora = v; }
	void seturgencia(int v) { urgencia = v; }
};

