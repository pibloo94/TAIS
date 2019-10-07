//PABLO AGUDO BRUN

#include "TreeMap_AVL.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void resolver(int const& k1, int const& k2, std::vector<int>& vsol, map<int, int>& mapa) {
	mapa.rango(k1, k2, vsol);
}

bool resuelveCaso() {
	int N, clave, k1, k2;

	if (!std::cin) {
		return false;
	}

	std::cin >> N;

	map<int, int> mapa;

	for (int i = 0; i < N; i++) {
		std::cin >> clave;
		mapa.insert(clave);
	}

	std::cin >> k1 >> k2;

	std::vector<int> vsol;

	resolver(k1, k2, vsol, mapa);

	for (int i = 0; i < vsol.size(); i++) {
		std::cout << vsol[i] << " ";
	}

	std::cout << "\n";

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while(resuelveCaso());	

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
}