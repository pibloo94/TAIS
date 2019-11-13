//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


int resolver(std::vector<int>& rivales, std::vector<int>& broncos) {
	int _max = 0;

	for (int i = 0; i < rivales.size(); i++) {
		if (broncos[i] - rivales[i] > 0) {
			_max += broncos[i] - rivales[i];
		}
	}

	return _max;
}

bool resuelveCaso() {
	int n;

	std::cin >> n;

	if (n == 0) {
		return false;
	}

	std::vector<int> rivales(n);
	std::vector<int> broncos(n);

	for (int i = 0; i < n; i++) {
		std::cin >> rivales[i];
	}

	for (int i = 0; i < n; i++) {
		std::cin >> broncos[i];
	}

	std::sort(rivales.begin(), rivales.end());
	std::sort(broncos.begin(), broncos.end(), std::greater<int>());

	int sol = resolver(rivales, broncos);

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