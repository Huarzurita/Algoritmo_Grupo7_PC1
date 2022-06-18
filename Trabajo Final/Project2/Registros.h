#include "HashTable.h"
#include "Treap.h"
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
	Treap*treap;
	TreapNode* root;
public:
	Registros() {
		root = nullptr;
		lista = new LinkedList<Registro*>([](Registro* a) {cout << a->toString() << endl; });
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
			treap->insertNode(root,number);
		}
		archivo.close();
	}

	LinkedList<Registro*>* getList() {return lista;}
	void Merge_Sort() {
		function<bool(Registro* a, Registro* b)> func = [](Registro* a, Registro* b) {return a->getNumber() > b->getNumber();};
		Registro** arreglo = lista->merge_sort(func);
		LinkedList<Registro*>* aux = new LinkedList<Registro*>([](Registro* a) {cout << a->toString() << endl; });
		for (size_t i = 0; i < lista->_size(); i++) {
			aux->pushBack(arreglo[i]);
		}
		lista = aux;
	}
	void Hash_Table() {
		HashTable<Registro*>* hash = lista->hash_table([](Registro* a) {return a->getNumber(); });
		hash->display([](Registro* a) {cout << a->toString(); });
	}
	void delete_treap() {
		cout << "Treap: "<<endl;treap->printTreap(root);
		cout << "Elimando al valor 2490:"<<endl;
		treap->deleteNode(root, 2490);treap->printTreap(root);
		cout << "Eliminando al valor 2677:"<<endl; 
		treap->deleteNode(root, 2677);treap->printTreap(root);
		cout << "Eliminando al valor 1458:" << endl;
		treap->deleteNode(root, 1458);treap->printTreap(root);
	}
	~Registros() {}
};
