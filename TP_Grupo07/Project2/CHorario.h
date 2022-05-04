#pragma once
#include "Capp.h"
template<class tipo>
class CHorario;
template<class tipo>
class Nodo
{
private:
	tipo com, com1, com2;
	tipo dato;
	Nodo* sgte;
	friend class CHorario<tipo>;
public:
	Nodo(tipo aux, tipo aux1,tipo aux2) {
		com = aux;
		com1 = aux1;
		com2 = aux2;
		sgte = nullptr;
	}
	~Nodo(){}
};
template<class tipo>
class CHorario
{
private:
	Nodo<tipo>* inicio;
	tipo actividad,horaI, horaF;
public:
	CHorario(tipo actividad,tipo horaI,tipo horaF){
		inicio = nullptr;
		this->actividad = actividad;
		this->horaI=horaI;
		this->horaF=horaF;
	}
	~CHorario(){}
	void insertarhorario() {//insertar al final O(n)
		Nodo<tipo>* nuevonodo = new Nodo<tipo>(actividad,horaI,horaF);
		if (inicio == nullptr) { inicio = nuevonodo; }//si la lista esta vacia inicio toma el valor ingresado
		else { Nodo<tipo>* aux = inicio;// aux se ubica al inicio
		while (aux->sgte!=nullptr)//mientras aux no apunte a nullptr
		{
			aux = aux->sgte;//que siga recorriendo hasta llegar al ultimo elemento
		}
		aux->sgte =nuevonodo; //aux ya apunta a nullptr, se borra nullptr y apunta al dato ingresado
		            //elemento a agregar 8   10->20->nullptr y ahora 10->20->8->nullptr
		}
	}

	void saveData() {
		if (inicio==NULL) {
			cout << "La lista está vacía " << "\n";
		}
		else {
			while (inicio != NULL)
			{
				cout<< "|--------------------------------------------------------------------------------------------|" << "\n";
				cout<< "|                                   °REGISTRO DE ACTIVIDADES°                                  |" << "\n";
				cout<< "|--------------------------------------------------------------------------------------------|" << "\n";
				cout<< " Nombre de la actividad: " << inicio->com << "\n";
				cout<< " Hora de inicio: " << inicio->com1 << "\n";
				cout<< " Hora de finalizacion: " << inicio->com2 << "\n";
				cout<< "|--------------------------------------------------------------------------------------------|" << "\n";
				inicio = inicio->sgte;
			}
		}
	}
};


