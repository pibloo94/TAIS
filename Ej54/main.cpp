//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

//El coste del algoritmo es de O(N logN) donde N es el numero de iteraciones realizadas sobre el vector y logN son los accesos que se realizan

struct tExtremos {
	int occidental;
	int oriental;
};

bool operator<(const tExtremos& a, const tExtremos& b) {
	return (a.oriental < b.oriental) || (a.occidental < b.occidental && a.oriental == b.oriental);
}

int resolver(std::vector<tExtremos>& v) {
	int pasadizos = 0;
	int min = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v[i].occidental >= min) {
			min = v[i].oriental;
			pasadizos++;
		}
	}

	return pasadizos;
}

bool resuelveCaso() {
	int N, W, E;

	std::cin >> N;

	if (N == 0) {
		return false;
	}

	std::vector<tExtremos> v;

	for (int i = 0; i < N; i++) {
		std::cin >> W >> E;
		v.push_back({ W, E });
	}

	std::sort(v.begin(), v.end());

	int sol = resolver(v);

	std::cout << sol << "\n";

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while(resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
	