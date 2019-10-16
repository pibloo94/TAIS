//PABLO AGUDO BRUN

#include "Grafo.h"
#include "Grafo_Guardias.h"

#include <fstream>
#include <iostream>

using namespace std;


bool resuelveCaso() {
	int N, C;
	int a1, a2;

	std::cin >> N >> C;

	if (!std::cin) {
		return false;
	}

	Grafo grafo(N);

	for (int i = 0; i < C; i++) {
		std::cin >> a1 >> a2;
		grafo.ponArista(a1 - 1, a2 - 1);
	}

	Grafo_Guardias grafo_guardias(grafo);

	if (grafo_guardias.bipartito()) {
		std::cout << grafo_guardias.numGuardias() << "\n";
	}
	else {
		std::cout << "IMPOSIBLE\n";
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