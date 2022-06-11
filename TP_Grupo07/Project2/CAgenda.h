#pragma once
#include "Capp.h"
template <class Generic, class Generic2>
class Contact
{
public:
	Contact(Generic2 telefono, Generic correo, Generic contacto): contacto(contacto), correo(correo), telefono(telefono) {}
	~Contact(){}
	Generic getcontacto() { return contacto; }
	Generic getcorreo() { return correo; }
	Generic2 gettelefono() { return telefono; }
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
private:
	Generic contacto, correo;
	Generic2 telefono;
};
