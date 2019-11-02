//PABLO AGUDO BRUN

#include "GrafoValorado.h"
#include "Camiones.h"

#include <iostream>
#include <fstream>

using namespace std;


bool resuelveCaso() {
	int V, E;

	std::cin >> V;

	if (!std::cin) {
		return false;
	}

	std::cin >> E;

	GrafoValorado<int> grafo(V);

	int v, w, valor;

	for (int i = 0; i < E; i++) {
		std::cin >> v >> w >> valor;
		grafo.ponArista({ v-1, w-1, valor });
	}

	int K, origen, destino, anchura;

	std::cin >> K;

	for (int i = 0; i < K; i++) {
		std::cin >> origen >> destino >> anchura;
		
		Camion camion(grafo, origen - 1, anchura);

		if (camion.dest(destino - 1)) {
			std::cout << "SI\n";
		}
		else {
			std::cout << "NO\n";
		}
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