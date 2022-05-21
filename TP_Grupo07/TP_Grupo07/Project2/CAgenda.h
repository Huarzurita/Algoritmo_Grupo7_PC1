#pragma once
#include "Capp.h"
template <class Generic>
class Contact
{
public:
	Contact(Generic contacto, Generic correo, Generic telefono): contacto(contacto), correo(correo), telefono(telefono) {
		archivo.open("Contactos.txt", ios::app);
	}
	~Contact(){}
	Generic getcontacto() { return contacto; }
	Generic getcorreo() { return correo; }
	Generic gettelefono() { return telefono; }
	void mostrar() {
		cout << "\n";
		cout << "\t |--------------------------------------------------------------------------------------------|" << "\n";
		cout << "\t |                                  °INFORMACIÓN DEL CONTACTO°                                |" << "\n";
		cout << "\t |--------------------------------------------------------------------------------------------|" << "\n";
		cout << "\t      Nombre del contacto: " << contacto << endl;
		cout << "\t      Correo del contacto: " << correo << endl;
		cout << "\t      Telefono del contacto: " << telefono << endl;
		cout << "\t |--------------------------------------------------------------------------------------------|" << "\n";
		cout << "\n";
	}
	void guardar() {
		archivo << "--------------------------------------------------------------------------------------------" << "\n";
		archivo << "                                  °INFORMACIÓN DEL CONTACTO°                                " << "\n";
		archivo << "--------------------------------------------------------------------------------------------" << "\n";
		archivo << "     Nombre del contacto: " << contacto << endl;
		archivo << "     Correo del contacto: " << correo << endl;
		archivo << "     Telefono del contacto: " << telefono << endl;
		archivo << "--------------------------------------------------------------------------------------------" << "\n";
		archivo << "\n";
	}
private:
	Generic contacto, correo, telefono;
	fstream archivo;
};
