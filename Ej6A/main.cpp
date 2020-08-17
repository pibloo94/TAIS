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

using namespace std;

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

int diasConsecutivos(std::vector<int>& frutas, int& N) {
	Matriz<int> matriz(N + 1 , N + 1, 0);

	for (int d = 2; d <= N; d++) {
		for (int i = 1; i <= N - d; i++) {
			int j = d + i;

			if (frutas[i] == frutas[j] && frutas[i] != 0) {
				matriz[i][j] = matriz[i + 1][j - 1] + 1;
			}
			else {
				matriz[i][j] = std::max(matriz[i + 2][j], std::max(matriz[i][j - 2], matriz[i + 1][j - 1]));
			}

			// imprimir(matriz, N);
		}
	}

	return matriz[1][N];
}

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (!std::cin) {
		return false;
	}

	std::vector<int> frutas(N + 1);
	for (int i = 1; i <= N; i++) {
		std::cin >> frutas[i];
	}

	int sol = diasConsecutivos(frutas, N);

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