//PABLO AGUDO BRUN

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

#include"GrafoDirigidoValorado.h"
#include "IndexPQ.h"
#include "Navegar.h"

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0) {
		return false;
	}

	std::vector<int> pagina(N);
	int carga;

	for (int i = 0; i < N; i++) {
		std::cin >> carga;
		pagina[i] = carga;
	}

	int M, v, w, valor;
	GrafoDirigidoValorado<int> grafo(N);
	std::cin >> M;

	for (int i = 0; i < M; i++) {
		std::cin >> v >> w >> valor;
		grafo.ponArista({ v - 1, w - 1, (pagina[w - 1] + valor) });
	}

	Navegar navegar(grafo, pagina);

	if (navegar.hayCamino()) {
		std::cout << navegar.camino() + pagina[0] << "\n";
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