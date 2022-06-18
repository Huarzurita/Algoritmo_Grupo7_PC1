#include "Capp.h"
template <class Generic>
class HashTable {
	class Entity {
		int key;
		Generic value;
		friend class HashTable;
	public: Entity(int k = 0, Generic v = 0) :key(k), value(v) {}};
	array<list<Entity>, 40> table;
	function<int(Generic)> func_hash;
public:
	HashTable(function<int(Generic)> fh) :func_hash(fh) {}
	int getIndex(int key) { return key % table.size(); }
	void add(int key, Generic value) {table[func_hash(value)].push_back(Entity(key, value));}
	void insert(Generic value) {
		table[getIndex(func_hash(value))].insert(table[getIndex(func_hash(value))].begin(), table.size(), (Entity(func_hash(value), value)));
	}
	void display(function<void(Generic)> show) {
		for (size_t i = 0; i < table.size(); ++i) {
			cout << i << "->";	
			for (list<Entity>::iterator it = table[i].begin(); it != table[i].end(); ++it) {
				if (i == getIndex((*it).key)) { show((*it).value); cout << endl; break; }
			}	
			cout << endl;
		}
	}
};

template<class Generic>
class LinkedList {
	class Node {
	public:
		Generic value;
		Node* next;
		Node(Generic value) : value(value), next(nullptr) {}
	};
	function<void(Generic)> show;
	Node* head,*tail;
	size_t size;
public:
	LinkedList(function<void(Generic)> show) : show(show) {
		head = tail = nullptr;
		size = 0;
	}
	~LinkedList() {}
	void pushBack(Generic value) {
		Node* aux = new Node(value);
		if (size == 0) {
			head = aux;tail = aux;
			++size;
			return;
		}
		tail->next = aux;
		tail = aux;
		++size;
	}
	void print() {
		Node* aux = head;
		while (aux != nullptr) {
			show(aux->value);
			aux = aux->next;
		}
	}

	void Merge(Generic* aux1, Generic* aux2, Generic* arreglo, size_t n, function<bool(Generic, Generic)> comp) {
		size_t i = 0, j = 0, k = 0;
		size_t mitad = n / 2;
		while (i < mitad && j < n - mitad) {
			if (comp(aux1[i], aux2[j]))
				arreglo[k++] = aux1[i++];
			else
				arreglo[k++] = aux2[j++];
		}
		while (i < mitad)
			arreglo[k++] = aux1[i++];
		while (j < n - mitad)
			arreglo[k++] = aux2[j++];
	}


	void mergeSort(Generic* arreglo, size_t tam, function<bool(Generic, Generic)> comp) {
		if (tam > 1) {
			size_t middle = tam / 2;
			Generic* aux1 = new Generic[middle];
			Generic* aux2 = new Generic[tam - middle];
			for (int i = 0; i < middle; i++)
				aux1[i] = arreglo[i];
			for (int i = middle; i < tam; i++)
				aux2[i - middle] = arreglo[i];
			mergeSort(aux1, middle, comp);
			mergeSort(aux2, tam - middle, comp);
			Merge(aux1, aux2, arreglo, tam, comp);
		}
	}

	Generic* merge_sort(function<bool(Generic, Generic)> func) {
		Generic* arreglo = new Generic[size];
		Node* aux = head;int i = 0;
		while (aux != nullptr) {
			arreglo[i] = aux->value;
			aux = aux->next;
			i++;
		}
		mergeSort(arreglo, size, func);
		return arreglo;
	}
	HashTable<Generic>* hash_table(function<int(Generic)> fh) {
		HashTable<Generic>* hash = new HashTable<Generic>(fh);
		Node* aux = head;
		while (aux != nullptr) {
			hash->insert(aux->value);
			aux = aux->next;
		}
		return hash;
	}
	size_t _size() { return size; }

};



