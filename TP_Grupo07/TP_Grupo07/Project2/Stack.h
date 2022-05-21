#pragma once
#include "Capp.h"
template <typename Generic>
struct Node4 {
    Generic elem;
    Node4* next;
    Node4(Generic date) :elem(date), next(nullptr) {}
};
template <typename Generic>
class Stack {
public:
    Node4<Generic>* first, * last;
    size_t siz;
    Stack() {
        first = last = nullptr;
        siz = 0;
    }
    void push_back(Generic n) {
        Node4<Generic>* nodito = new Node4<Generic>(n);
        nodito->next = first;
        first = nodito;
        last = first;
        siz++;
    }
    Node4<Generic>* at(int i) {
        Node4<Generic>* aux = first;
        for (int j = 0; j < i; j++) {
            aux = aux->next;
        }
        return aux;
    }
    int size() {
        return siz;
    }
    void print_save(function<void(Generic)> imprimir){
        Node4<Generic>* aux = first;
        for (int i = 0; i < siz; i++) {
            imprimir(aux->elem);
            aux = aux->next;
        }
    }

    ~Stack() {}
};