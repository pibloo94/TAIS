//PABLO AGUDO BRUN
	
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Matriz.h"

using namespace std;

const int INF = 1000000000;

int resolver(std::vector<int>& valores, std::vector<int>& cantidades, int& n, int& p) {
	Matriz<int> mapa(n + 1, p + 1, INF);

	for (int i = 0; i <= n; i++) {
		mapa[i][0] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= p; j++) {
			int cantidad = std::min(cantidades[i], j / valores[i]);
			int actual = INF;

			for (int k = 0; k <= cantidad; k++) {
				actual = std::min(mapa[i - 1][j - (k * valores[i])] + k, actual);
			}

			mapa[i][j] = actual;
		}
	}

	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= p; j++) {
			if (mapa[i][j] == INF) {
				std::cout << "X";
			}
			else {
				std::cout << mapa[i][j] << " ";
			}
		}
	}
	*/

	return mapa[n][p];
}

bool resuelveCaso() {
	int n, p;
	std::cin >> n;

	if (!std::cin) {
		return false;
	}

	std::vector<int> valores(n + 1);
	std::vector<int> cantidades(n + 1);

	for (int i = 1; i <= n; i++) {
		std::cin >> valores[i];
	}

	for (int i = 1; i <= n; i++) {
		std::cin >> cantidades[i];
	}

	std::cin >> p;

	int solucion = resolver(valores, cantidades, n, p);

	if (solucion != INF) {
		std::cout << "SI " << solucion << "\n";
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