//PABLO AGUDO BRUN

#include "bintree_eda.h"

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct tSolucion {
	int altura = 0;
	bool equilibrado = true;
};

tSolucion resolver(bintree<char> arbol) {
	tSolucion solucion, der, izq;

	if (!arbol.empty()) {
		der.altura++;
		der = resolver(arbol.right());
		izq.altura++;
		izq = resolver(arbol.left());

		if (abs(der.altura - izq.altura) <= 1 && (der.equilibrado && izq.equilibrado)) {
			solucion.equilibrado = true;
		}
		else {
			solucion.equilibrado = false;
		}

		solucion.altura = 1 + std::max(der.altura, izq.altura);
	}

	return solucion;
}

void resuelveCaso() {
	tSolucion solucion;

	char vacio = '.';
	bintree<char> arbol = leerArbol(vacio);

	solucion = resolver(arbol);

	if (solucion.equilibrado) {
		std::cout << "SI\n";
	}
	else {
		std::cout << "NO\n";
	}
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
}