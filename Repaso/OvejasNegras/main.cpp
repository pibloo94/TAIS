//PABLO AGUDO BRUN

#include "MatrizOvejas.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


bool resuelveCaso() {
	int ancho, alto;
	char pixel;

	std::cin >> ancho >> alto;

	if (!std::cin) {
		return false;
	}

	std::vector<std::vector<char>> matriz(ancho, std::vector<char> (alto));

	for (int i = 0; i < ancho; i++) {
		for (int j = 0; j < alto; j++) {
			std::cin >> matriz[i][j];
		}
	}

	MatrizOvejas imagen(matriz);

	std::cout << imagen.contBlancas() << "\n";

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
