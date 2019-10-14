//PABLO AGUDO BRUN

#include "ConjuntosDisjuntos.h"

#include <iostream>
#include <fstream>

using namespace std;


bool resuelveCaso() {
	int N, M;

	std::cin >> N >> M;

	if (!std::cin) {
		return false;
	}

	int nUsurarios, idUsuario;

	ConjuntosDisjuntos conjunto(N);

	while (M--) {
		std::cin >> nUsurarios;

		if (nUsurarios > 0) {
			int prim, otro;
			cin >> prim;
			--prim;

			for (int i = 1; i < nUsurarios; i++) {
				cin >> otro;
				--otro;
				conjunto.unir(prim, otro);
			}
		}
	}

	cout << conjunto.tam(0);

	for (int i = 1; i < N; i++) {
		cout << " " << conjunto.tam(i);
	}

	cout << "\n";

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