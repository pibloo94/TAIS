//PABLO AGUDO BRUN

#include "bintree_eda.h"

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct tSolucion {
	int altura;
	bool equilibrado;
};

template <class T>
tSolucion resolver(bintree<T> arbol) {
	tSolucion izq, der, sol;

	if (arbol.right().empty() && arbol.left().empty()) {
		sol.equilibrado = true;
	}
	else if (!arbol.right().empty()) {
		der = resolver(arbol.right());
		der.altura++;
	}
	else if (!arbol.left().empty()) {
		izq = resolver(arbol.left());
		izq.altura++;
	}
	else {
		der = resolver(arbol.right());
		der.altura++;
		izq = resolver(arbol.left());
		izq.altura++;
	}
}

void resuelveCaso() {
	tSolucion solucion;

	char vacio = '.';
	bintree<char> arbol = leerArbol(vacio);

	solucion = resolver(arbol);
	
	if (solucion.equilibrado) {
		std::cout << "SI";
	}
	else {
		std::cout << "NO";
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
