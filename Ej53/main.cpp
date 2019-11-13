//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


int resolver(int const& V, std::vector<int>& voltajes_pilas) {
	int coches = 0, i = 0, j = voltajes_pilas.size() - 1;

	while (i < j) {
		if (voltajes_pilas[i] + voltajes_pilas[j] >= V) {
			coches++;
			i++;
			j--;
		}
		else {
			i++;
		}
	}

	return coches;
}

void resuelveCaso() {
	int N, V;
	std::cin >> N >> V;

	std::vector<int> voltajes_pilas(N);

	for (int i = 0; i < N; i++) {
		std::cin >> voltajes_pilas[i];
	}

	std::sort(voltajes_pilas.begin(), voltajes_pilas.end());

	int sol = resolver(V, voltajes_pilas);

	std::cout << sol << "\n";
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	std::cin >> numCasos;

	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
