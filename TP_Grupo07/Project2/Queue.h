#include "Node.h"
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
		if (empty()) {
			head = nuevo;
			head->next = NULL;
			tail = head;
		}
		else {
			tail->next = nuevo;
			nuevo->next = NULL;
			tail = nuevo;
		}
		cout << endl;
		siz++;
	}

	void dequeque() {
		Node<Generic>* aux = head;
		head = aux->next;
		tail = aux->next;
		aux->next = nullptr;
		delete aux;
		siz--;
	}
	void front() {
		cout << " " << head->date << endl;
	}
	void back() {
		cout << " " << tail->date << endl;
	}
	void reverse() {
		Node<Generic>* temp = NULL, * prev = NULL, * curr = head;
		while (curr != NULL)
		{
			temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}
		head = prev;
	}
	void print(function<void(Generic)>imprimir) {
		if (siz > 0) {
			Node<Generic>* aux = head;
			while (aux->next != NULL) {
				imprimir(aux->date);
				aux = aux->next;
			}
			if (aux->next == nullptr) {
				imprimir(aux->date);
			}
			cout << endl;
		}
	} 
	void save(function<void(Generic)>guardar) {
		if (siz > 0) {
			Node<Generic>* aux = head;
			while (aux->next != NULL) {
				guardar(aux->date);
				aux = aux->next;
			}
			if (aux->next == nullptr) {
				guardar(aux->date);
			}
			cout << endl;
		}
	}
	
	void remove_pos(int posicion) {
		if (posicion > siz)
			return;
		if (posicion == 0) {
			dequeque();
		}
		else
		{
			Node<Generic>* aux = head;
			for (int i = 1; i < posicion; i++)
			{
				aux = aux->next;
			}
			Node<Generic>* nuevo = aux->next;
			aux->next = aux->next->next;
			delete nuevo;
			siz--;
		}
	}
	void search_node() {
		Node<Generic>* curr = head;
		T n;
		bool exist = false;
		cout << " Ingrese el dato del Nodo a Buscar: ";
		cin >> n;
		if (!empty()) {
			while (curr != NULL && exist != true) {

				if (curr->date == n) {
					cout << endl << " Nodo con el dato ( " << n << " ) encontrado" << endl << endl;
					exist = true;
				}
				curr = curr->next;
			}
			if (exist == false) {
				cout << endl << " Nodo no encontrado" << endl << endl;
			}
		}
		else {
			cout << endl << " La cola se encuentra vacia" << endl << endl;
		}
	}

	void change_node() {
		Node<Generic>* curr = head;
		T n;
		bool exist = false;
		cout << " Ingrese el dato del Nodo a Buscar par Modificar: ";
		cin >> n;
		if (!empty()) {
			while (curr != NULL && exist != true) {

				if (curr->date == n) {
					cout << endl << " Nodo con el dato ( " << n << " ) encontrado";
					cout << endl << " Ingrese el nuevo dato para este Nodo: ";
					cin >> curr->date;
					cout << endl << " Nodo Modificado " << endl << endl;
					exist = true;
				}

				curr = curr->next;
			}
			if (exist == false) {
				cout << endl << " Nodo no encontrado" << endl << endl;
			}
		}
		else {
			cout << endl << " La cola se encuentra vacia" << endl << endl;
		}
	}
	size_t get_siz() { return siz; }
	bool empty() {
		if (head == NULL) {
			return true;
		}
	}
	~Queue() {
	}
};