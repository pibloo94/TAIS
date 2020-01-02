//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#include "Grafo.h"
#include "NodoLejano.h"

using namespace std;

bool resuelveCaso() {
	int N, C;
	std::cin >> N; //nodos

	if (!std::cin) {
		return false;
	}

	std::cin >> C; //conexiones

	Grafo g(N);
	int n1, n2;

	for (int i = 0; i < C; i++) {
		std::cin >> n1 >> n2;
		g.ponArista(n1 - 1, n2 - 1);
	}

	int k, origen, ttl;
	std::cin >> k;

	while (k--) {
		std::cin >> origen >> ttl;
		--origen;

		NodoLejano nl(g, origen, ttl);
		std::cout << nl.inalcanzables() << "\n";
	}

	std::cout << "---\n";

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