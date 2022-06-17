#include "HashTable.h"

class Registro {
	string  name, code;
	int number;
public:
	Registro(int number, string code, string name) :number(number), code(code), name(name) {}
	~Registro() {}
	string toString() {
		string temp = "";
		temp += to_string(number);
		temp += "," + code;
		temp += "," + name;
		return temp;
	}
	string getCode() { return code; }
	string getName() { return name; }
	int getNumber() { return number; }
};

class Registros {
	LinkedList<Registro*>* lista;
public:
	Registros() {
		lista = new LinkedList<Registro*>([](Registro* a) {cout << "\t" << a->toString() << endl; });
		ifstream archivo("Users.txt");
		string linea;
		char delimitador = ',';
		getline(archivo, linea);
		while (getline(archivo, linea)) {
			stringstream stream(linea);
			string _number,code,name;
			getline(stream, _number, delimitador);
			getline(stream, code, delimitador);
			getline(stream, name, delimitador);
			int number = stoi(_number);
			Registro* r = new Registro(number, code, name);
			lista->pushBack(r);
		}
		archivo.close();
	}

	LinkedList<Registro*>* getList() {return lista;}
	void Merge_Sort() {
		function<bool(Registro* a, Registro* b)> func = [](Registro* a, Registro* b) {return a->getNumber() > b->getNumber();};
		Registro** arreglo = lista->merge_sort(func);
		LinkedList<Registro*>* aux = new LinkedList<Registro*>([](Registro* a) {cout <<"\t"<< a->toString() << endl; });
		for (size_t i = 0; i < lista->_size(); i++) {
			aux->pushBack(arreglo[i]);
		}
		lista = aux;
	}
	void Hash_Table() {
		HashTable<Registro*>* hash = lista->hash_table([](Registro* a) {return a->getNumber(); });
		hash->display([](Registro* a) {cout << "\t" << a->toString() << endl; });
	}
	~Registros() {}
};
