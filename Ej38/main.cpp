//PABLO AGUDO BRUN

#include "GrafoDirigidoValorado.h"
#include "Laberinto.h"

#include <iostream>
#include <fstream>

using namespace std;


bool resuelveCaso() {
	int N, S, T, P;

	std::cin >> N >> S >> T >> P;

	if (!std::cin) {
		return false;
	}

	GrafoDirigidoValorado<int> grafo(N);
	int v, w, valor;

	for (int i = 0; i < P; i++) {
		std::cin >> v >> w >> valor;
		grafo.ponArista({v-1, w-1, valor});
	}

	Laberinto laberinto(grafo, S-1, T);

	std::cout << laberinto.getCont() << "\n";

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