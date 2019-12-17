//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#include "Matriz.h"

using namespace std;

/*
caminos(i, j) = nro de caminos desde el origen 

casos base:
- caminos(0, 1) = 1;

casos recursivos:
- caminos(i, j) = caminos(i-1, j) + caminos(i, j-1)

coste del algoritmo: O(N*M)
- con N calles de norte a sur
- con M calles de este a oeste
*/

int calcularCaminos(Matriz<char> &tabla, int& N, int& M) {
	std::vector<int> caminos(M+1, 0);

	caminos[1] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (tabla[i-1][j-1] != 'P') {
				caminos[j] = caminos[j] + caminos[j - 1];
			}
			else {
				caminos[j] = 0;
			}
		}
	}

	return caminos[M];
}

bool resuelveCaso() {
	int N, M;

	std::cin >> N >> M;

	if (!std::cin) {
		return false;
	}

	Matriz<char> tabla(N, M);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> tabla[i][j];
		}
		std::cin.get();
	}

	int solucion = calcularCaminos(tabla, N, M);

	std::cout << solucion << "\n";

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