//PABLO AGUDO BRUN

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "Matriz.h"

/*
Coste del algoritmo:
*/

const int INF = 100000000;

/*
void imprimir(Matriz<int>& matriz, int& N) {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			std::cout << matriz[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}
*/

int esfuerzoMinimo(std::vector<int>& cortes, int& N) {
	int n = cortes.size() - 1;
	Matriz<int> matriz(n + 1, n + 1, 0);

	for (int d = 1; d <= n - 1; d++) {
		for (int i = 1; i <= n - d; i++) {
			int j = i + d;

			int esfuerzo = INF;

			for (int k = i + 1; k <= j - 1; k++) {
				int temp = matriz[i][k] + matriz[k][j] + 2 * (cortes[j] - cortes[i]);
				
				if (temp < esfuerzo) {
					matriz[i][j] = temp;
					esfuerzo = temp;
				}
			}
		}
	}
	
	// imprimir(matriz, n);

	return matriz[1][n];
}

bool resuelveCaso() {
	int L, N;
	std::cin >> L >> N;

	if (L == 0 && N == 0) {
		return false;
	}

	std::vector<int> cortes(N + 3);
	int corte;

	for (int i = 2; i < cortes.size() - 1; i++) {
		std::cin >> cortes.at(i);
	}

	cortes.at(cortes.size() - 1) = L;

	int sol = esfuerzoMinimo(cortes, N);

	std::cout << sol << "\n";

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