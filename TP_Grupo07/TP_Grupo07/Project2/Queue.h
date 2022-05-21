#include "Capp.h"
template <class Generic>
class Node
{
public:
	Generic date;
	Node<Generic>* next;
	Node(Generic date) :date(date),next(nullptr) {}
};

template<class Generic>
class Queue
{
public:
	Node<Generic>* head, * tail;
	size_t siz;
	Queue() {
		head = tail = nullptr;
		siz = 0;
	}
	void enqueque(Generic v) {
		Node<Generic>* nuevo = new Node<Generic>(v);
		nuevo->next = nullptr;
		if (empty()) {
			head = nuevo;
			tail = nuevo;
		}
		else {
			tail->next = nuevo;
		}
		tail = nuevo;
		cout << endl;
		siz++;
	}
	void print_save(function<void(Generic)>imprimir) {
		if (siz > 0) {
			Node<Generic>* aux = head;
			while (aux->next != nullptr) {
				imprimir(aux->date);
				aux = aux->next;
			}
			if (aux->next == nullptr) {
				imprimir(aux->date);
			}
			cout << endl;
		}
	} 
	
	size_t get_siz() { return siz; }
	bool empty() {
		if (head == nullptr) {
			return true;
		}
	}
	~Queue() {
	}
};