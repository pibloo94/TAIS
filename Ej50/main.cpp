//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int calcularParches(int& L, std::vector<int>& agujeros) {
	int parches = 1;
	int aux = agujeros[0];

	for (int i = 1; i < agujeros.size(); i++) {
		if (agujeros[i] > L + aux) {
			parches++;
			aux = agujeros[i];
		}
	}

	return parches;
}

bool resuelveCaso() {
	int N, L;

	std::cin >> N >> L;

	if (!std::cin) {
		return false;
	}

	std::vector<int> agujeros(N);

	for (int i = 0; i < N; i++) {
		std::cin >> agujeros[i];
	}

	std::cout << calcularParches(L, agujeros) << "\n";

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