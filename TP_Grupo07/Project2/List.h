#include "Capp.h"
template<class T>
class List {
public:
    class Node {
    public:
        T value;
        Node* next;
        Node(T value, Node* next = nullptr) : value(value), next(next) {}
    };
private:
    Node* inicio;
    Node* fin;
    unsigned long size;
    function<void(T)> mostrar;
    function<void(T)> guardar;
public:
    List(function<void(T)> mostrar, function<void(T)> guardar) : mostrar(mostrar), guardar(guardar) {
        inicio = fin = nullptr;
        size = 0;
    }
    ~List() {
        while (size > 0) {
            popFront();
        }
        inicio = fin = nullptr;
    }
    void print() {
        cout << "\n";
        if (size == 0) {
            cout << "\nnullptr";
            return;
        }
        _print(inicio);
    }
    void save(T elem) {
        guardar(elem);
    }
private:
    void disorder() {
        for (int i = size; i > 0; i--) {
            Node* aux = inicio; Node* aux1 = inicio;
            int j = rand() % i;
            for (int k = 0; k < j; k++)
                aux = aux->next;
            for (int l = 0; l < i - 1; l++)
                aux1 = aux1->next;
            swap(&aux1->value, &aux->value);
        }
    }
    void _print(Node* n) {
        if (n == nullptr) return;
        disorder();
        mostrar(n->value);
        _print(n->next);
    }

public:
    void pushBack(T value) {
        if (size == 0) {
            Node* n = new Node(value);
            inicio = n;
            fin = n;
            ++size;
        }
        else {
            Node* n = new Node(value);
            fin->next = n;
            fin = n;
            ++size;
        }
    }
    void popFront() {
        if (size == 0) return;
        Node* aux = inicio;
        if (size == 1) inicio = fin = nullptr;
        else inicio = inicio->next;
        delete aux;
        --size;
    }
    unsigned long Size() {
        return size;
    }
    Node* insertInRange(function<void(T)> insert, int i, int f, Node* n) {
        size_t init = i;
        Node* aux = (!n) ? this->inicio : n;
        for (init; init <= f; ++init) {
            insert(aux->value);
            aux = aux->next;
        }
        return aux;
    }
    void swap(T *a, T *b) {
   		T temp = *a;
   		*a = *b;
   		*b = temp;
   	}
};