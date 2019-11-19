//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct tPelicula {
	int hora;
	int duracion;
};

bool operator<(tPelicula const& a, tPelicula const& b) {
	return (a.duracion < b.duracion) || (a.duracion == b.duracion && a.hora < b.hora);
}

int resolver(std::vector<tPelicula>& v) {
	int npeliculas = 0;
	int actual = 0;
	
	for (int i = 0; i < v.size(); i++) {
		if (actual < v[i].hora) {
			npeliculas++;
			actual = v[i].duracion;
		}
	}
	
	return npeliculas;
}

bool resuelveCaso() {
	int N;

	std::cin >> N;

	if (N == 0) {
		return false;
	}

	int HH, MM, duracion;
	char separador;
	std::vector<tPelicula> v;
	for (int i = 0; i < N; i++) {
		std::cin >> HH >> separador >> MM;
		std::cin >> duracion;

		v.push_back({(HH*60) + MM, duracion + 10});
	}

	//std::sort(v.begin(), v.end(), std::less<tPelicula>());

	int sol = resolver(v);

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