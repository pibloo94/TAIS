//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


int resolver(std::vector<int>& esquiadores, std::vector<int>& esquies) {
	int dif = 0;
	
	for (int i = 0; i < esquiadores.size(); i++) {
		dif += abs(esquiadores[i] - esquies[i]);
	}

	return dif;
}

bool resuelveCaso() {
	int N;

	std::cin >> N;

	if (N == 0) {
		return false;
	}

	std::vector<int> esquiadores(N);
	std::vector<int> esquies(N);

	for (int i = 0; i < N; i++) {
		std::cin >> esquiadores[i];
	}

	for (int i = 0; i < N; i++) {
		std::cin >> esquies[i];
	}

	std::sort(esquiadores.begin(), esquiadores.end());
	std::sort(esquies.begin(), esquies.end());

	int sol = resolver(esquiadores, esquies);

	std::cout << sol << "\n";

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