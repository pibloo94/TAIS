//PABLO AGUDO BRUN

#include "GrafoBipartito.h"

#include <fstream>
#include <iostream>

using namespace std;


bool resuelveCaso() {
	int V, A;
	int a1, a2;

	std::cin >> V >> A;

	if (!std::cin) {
		return false;
	}

	Grafo grafo(V);

	for (int i = 0; i < A; i++) {
		std::cin >> a1 >> a2;
		grafo.ponArista(a1, a2);
	}

	GrafoBipartito bipartito(grafo);

	if (bipartito.esGrafoBipartito()) {
		std::cout << "SI\n";
	}
	else {
		std::cout << "NO\n";
	}

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