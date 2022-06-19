#pragma once
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class SegmentTreeRMQ {
	// st es el arreglo de nodos del segment tree
	vector< long long> arr, st;
	// leaf guarda la ubicación de cada hoja en st
	vector<int> leaf; int n;
	// construir nodo u, que representa al rango [i,j]
	void build(int u, int i, int j) {
		// caso de que el rango representa una hoja
		if (i == j) {
			leaf[i] = u;
			st[u] = arr[i];
			return;
		}
		// l y r son los hijos izquierdo y derecho de u
		int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
		build(l, i, m);
		build(r, m + 1, j); // es importante el +1
		st[u] = min(st[l], st[r]); // range min. query
	}
	// query en el rango [a,b], considerando que nos
	// encontramos en el nodo u que representa a [i,j]
	long long query(int a, int b, int u, int i, int j) {
		// nodo fuera del rango [a,b], retornar neutro
		if (j < a || b < i)
			return 1e18; //infinito = neutro del mín.
			// nodo totalmente contenido en [a,b]
		if (a <= i && j <= b)
			return st[u]; // responder directamente
			// si no, componer queries de ambos hijos
		int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
		long long x = query(a, b, l, i, m);
		long long y = query(a, b, r, m + 1, j);// +1 !!
		return min(x, y);
	}
	// actualizar nodo u considerando que uno de sus
	// hijos fue actualizado antes (o es una hoja)
	void update(int u) {
		int l = u * 2 + 1, r = u * 2 + 2;
		st[u] = min(st[l], st[r]); // actualizar info
		// si no es la raíz (nodo 0) actualizar padre
		if (u != 0) update((u - 1) / 2);
	}
public:
	// construir segment tree a partir de un vector
	SegmentTreeRMQ(vector<long long>& v) {
		arr = v;
		n = v.size();
		leaf.resize(n);
		// reservar tamaño para el peor caso, 4*N
		st.resize(n * 4 + 5);
		// construir desde la raíz
		build(0, 0, n - 1);
	}
	// [a,b] es inclusivo inclusivo, indexado desde 0
	long long query(int a, int b) {
		// responder query procesando desde la raíz
		return query(a, b, 0, 0, n - 1);
	}
	// setea un valor en cierto índice del arreglo
	void update(int index, long long value) {
		int u = leaf[index];
		arr[index] = value;
		st[u] = arr[index];
		// chequea si la hoja es raíz por si N = 1
		if (u != 0) update((u - 1) / 2);
	}
};