//PABLO AGUDO BRUN

#include "GrafoAmigos.h"

#include <iostream>
#include <fstream>

using namespace std;

void resuelveCaso() {
	int N, M;
	int h1, h2;

	std::cin >> N >> M;

	Grafo grafo(N);

	for (int i = 0; i < M; i++) {
		std::cin >> h1 >> h2;
		grafo.ponArista(h1 - 1, h2 - 1);
	}

	GrafoAmigos grafoAmigos(grafo);

	std::cout << grafoAmigos.maximo() << "\n";
}

int main(){

#ifndef DOMJUDGE
std::ifstream in("casos.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 

	int numCasos;
	std::cin >> numCasos;

	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

#ifndef DOMJUDGE
std::cin.rdbuf(cinbuf);
system("PAUSE");
#endif

return 0;
}