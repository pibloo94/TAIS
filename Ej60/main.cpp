//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>

#include "Matriz.h"
#include <algorithm>

using namespace std;

const int INF = 1000000000;

struct tVarilla {
	int longitud;
	int precio;
};

/*
li = longitud de la varilla i

sePuede(i, j) = {
	sePuede(i-1, j) sii li > j
	sePuede(i-1, j-li) sii li <= j � sePuede(i-1, j) sii li <= j
}

casos base:
	sePuede(i, 0) = cierto
	sePuede(0, j) = falso sii j> 0
*/
bool sePuede(std::vector<tVarilla>& v, int& N, int& L) {
	Matriz<bool> varillas(N + 1, L + 1, false);

	for (int i = 0; i <= N; i++) {
		varillas[i][0] = true;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= L; j++) {
			if (v[i - 1].longitud > j) {
				varillas[i][j] = varillas[i - 1][j];
			}
			else {
				varillas[i][j] = varillas[i - 1][j] || varillas[i - 1][j - v[i - 1].longitud];
			}
		}
	}

	return varillas[N][L];
}

/*
formas = {
	formas(i-1, j) sii li > j
	formas(i-1, j-li) + formas(i-1, j) sii li <= j
}

casos base:
	formas(i, 0) = 1
	formas(0, j) = 0 sii j> 0
*/
int formas(std::vector<tVarilla>& v, int& N, int& L) {
	Matriz<int> varillas(N + 1, L + 1, 0);

	for (int i = 0; i <= N; i++) {
		varillas[i][0] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= L; j++) {
			if (v[i - 1].longitud > j) {
				varillas[i][j] = varillas[i - 1][j];
			}
			else {
				varillas[i][j] = varillas[i - 1][j] + varillas[i - 1][j - v[i - 1].longitud];
			}
		}
	}

	return varillas[N][L];
}

/*
minvar = {
	minvar(i-1, j) sii li > j
	min(minvar(i-1, j-li) +  1, sePuede(i-1, j)) sii li <= j
}

casos base:
	minvar(i, 0) = 0
	minvar(0, j) = +inifinito sii j> 0
*/
int minVar(std::vector<tVarilla>& v, int& N, int& L) {
	Matriz<int> varillas(N + 1, L + 1, INF);

	for (int i = 0; i <= N; i++) {
		varillas[i][0] = 0;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= L; j++) {
			if (v[i - 1].longitud > j) {
				varillas[i][j] = varillas[i - 1][j];
			}
			else {
				varillas[i][j] = std::min(
					varillas[i - 1][j], 
					varillas[i - 1][j - v[i - 1].longitud] + 1);
			}
		}
	}

	return varillas[N][L];
}

/*
ci = coste de la varilla i

mincost = {
	mincost(i-1, j) sii li > j
	min(mincost(i-1, j-li) + ci, mincost(i-1, j)) sii li <= j
}

casos base:
	mincost(i, 0) = 0
	mincost(0, j) = +infinitos sii j> 0
*/
int minCost(std::vector<tVarilla>& v, int& N, int& L) {
	Matriz<int> varillas(N + 1, L + 1, INF);

	for (int i = 0; i <= N; i++) {
		varillas[i][0] = 0;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= L; j++) {
			if (v[i - 1].longitud > j) {
				varillas[i][j] = varillas[i - 1][j];
			}
			else {
				varillas[i][j] = std::min(
					varillas[i - 1][j], 
					varillas[i - 1][j - v[i - 1].longitud] + v[i - 1].precio
				);
			}
		}
	}

	return varillas[N][L];
}

bool resuelveCaso() {
	int N, L;

	std::cin >> N >> L;

	if (!std::cin) {
		return false;
	}

	int longitud, precio;
	std::vector<tVarilla> v;

	for (int i = 0; i < N; i++) {
		std::cin >> longitud >> precio;
		v.push_back({longitud, precio});
	}

	if (sePuede(v, N, L)) {
		std::cout 
			<< "SI " 
			<< formas(v, N, L) << " "
			<< minVar(v, N, L) << " "
			<< minCost(v, N, L) << " "
			<< "\n";
	}
	else {
		std::cout << "NO" << "\n";
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