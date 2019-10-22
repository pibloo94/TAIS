//PABLO AGUDO BRUN

#include "Parcelas.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


bool resuelveCaso() {
	int F, C;
	char p;

	std::cin >> F >> C;

	if (!std::cin) {
		return false;
	}

	std::vector<string> terreno;
	std::string line;

	std::cin.get();

	for (int i = 0; i < F; i++) {
		std::getline(std::cin, line);
		terreno.push_back(line);
	}

	Parcelas parcelas(terreno);

	std::cout << parcelas.maxParcela() << "\n";
	

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