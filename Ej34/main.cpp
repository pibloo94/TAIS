//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

#include "Petrolero.h"

using namespace std;

bool resuelveCaso() {
	int F, C;

	std::cin >> F >> C;

	if (!std::cin) {
		return false;
	}

	std::vector<std::string> foto(F);
	std::cin.get();

	for (int i = 0; i < F; i++) {
		std::getline(std::cin, foto[i]);
	}

	Petrolero petrolero(foto, F, C );
	
	std::cout << petrolero.getMancha();

	int nuevas_fotos, nueva_F, nueva_C;
	std::cin >> nuevas_fotos;

	for (int i = 0; i < nuevas_fotos; i++) {
		std::cin >> nueva_F >> nueva_C;
		foto[nueva_F - 1][nueva_C - 1] = '#';
		petrolero.nuevaFoto(foto, nueva_F - 1, nueva_C - 1);
		
		std::cout << " " << petrolero.getMancha();
	}

	std::cout << "\n";

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
