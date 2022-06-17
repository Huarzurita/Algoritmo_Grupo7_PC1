#include "Capp.h"
template<class Generic>
class List {
public:
    class Node {
    public:
        Generic value;
        Node* next;
        Node(Generic value, Node* next = nullptr) : value(value), next(next) {}
    };
private:
    Node* first;
    Node* last;
    unsigned long size;
    function<void(Generic)> mostrar, guardar;
public:
    List(function<void(Generic)> mostrar, function<void(Generic)> guardar) : mostrar(mostrar), guardar(guardar) {
        first = last = nullptr;
        size = 0;
    }
    ~List() {
        while (size > 0) {
            popFront();
        }
        first = last = nullptr;
    }
    void print() {
        cout << "\n";
        if (size == 0) {
            cout << "\nnullptr";
            return;
        }
        _print(first);
    }
    void save(Generic elem) {
        guardar(elem);
    }
    void pushBack(Generic value) {
        if (size == 0) {
            Node* n = new Node(value);
            first = n;
            last = n;
            ++size;
        }
        else {
            Node* n = new Node(value);
            last->next = n;
            last = n;
            ++size;
        }
    }
    unsigned long Size() {
        return size;
    }
private:
    void disorder() {
        for (int i = size; i > 0; i--) {
            Node* aux = first; Node* aux1 = first;
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
    void swap(Generic* a, Generic* b) {
        Generic temp = *a;
        *a = *b;
        *b = temp;
    }

};