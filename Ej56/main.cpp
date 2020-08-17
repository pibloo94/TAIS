//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "PriorityQueue.h"

using namespace std;

struct tActividad {
	int ini;
	int fin;
};

bool operator <(tActividad const& a, tActividad const& b) {
	return (a.ini < b.ini);
}

int resolver(PriorityQueue<tActividad>& colap) {
	int amigos = 0;
	tActividad actividad;

	actividad = colap.top();
	colap.pop();

	PriorityQueue<int> finales;
	finales.push(actividad.fin);

	while (!colap.empty()) {
		actividad = colap.top();
		colap.pop();

		if (finales.top() > actividad.ini) {
			amigos++;
			finales.push(actividad.fin);
		}
		else {
			finales.pop();
			finales.push(actividad.fin);
		}
	}

	return amigos;
}

bool resuelveCaso() {
	int N;

	std::cin >> N;

	if (N == 0) {
		return false;
	}

	PriorityQueue<tActividad> colap;
	int ini, fin;

	for (int i = 0; i < N; i++) {
		std::cin >> ini >> fin;
		colap.push({ini, fin});
	}

	int solucion = resolver(colap);

	std::cout << solucion << "\n";

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}