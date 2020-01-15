//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Matriz.h"

using namespace std;

const int INF = 1000000000;

struct tBombilla {
	int potencia;
	int coste;
};


/*
casos base:
- mapa[i][0] = 0
- mapa[0][j] = 0

casos recursivos:
- mapa[i][j] = mapa[i - 1][j] sii j < bombillas[i].potencia
- mapa[i][j] = min(mapa[i - 1][j], mapa[i][j - bombillas[i].potencia] + bombillas[i].coste) sii j >= bombillas[i].potencia;

coste de la implementacion: O(N*M) con N igual al numero de bombillas y M igual a la potencia maxima
*/
tBombilla minCoste(std::vector<tBombilla>& bombillas, int& n, int& pmax, int& pmin) {
	Matriz<int> mapa(n + 1, pmax + 1, INF);

	for (int i = 0; i <= n; i++) {
		mapa[i][0] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= pmax; j++) {
			if (j >= bombillas[i].potencia) {
				mapa[i][j] = std::min(mapa[i - 1][j], mapa[i][j - bombillas[i].potencia] + bombillas[i].coste);
			}
			else {
				mapa[i][j] = mapa[i - 1][j];
			}
		}
	}


	int minimo = mapa[n][pmin];
	int minPot = pmin;
	int aux = minimo;

	for (int i = pmin + 1; i <= pmax; i++) {
		minimo = std::min(minimo, mapa[n][i]);

		if (aux != minimo) {
			aux = minimo;
			minPot = i;
		}
	}

	return { minPot, minimo };
}

bool resuelveCaso() {
	int n, pmax, pmin;
	std::cin >> n >> pmax >> pmin;

	if (!std::cin) {
		return false;
	}

	std::vector<tBombilla> bombillas(n + 1);
	int potencia, coste;

	for (int i = 1; i <= n; i++) {
		std::cin >> potencia;
		bombillas[i].potencia = potencia;
	}

	for (int i = 1; i <= n; i++) {
		std::cin >> coste;
		bombillas[i].coste = coste;
	}

	tBombilla solucion = minCoste(bombillas, n, pmax, pmin);

	if (solucion.coste != INF) {
		std::cout << solucion.coste << " " << solucion.potencia << "\n";
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