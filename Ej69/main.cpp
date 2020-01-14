//PABLO AGUDO BRUN

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Matriz.h"
#include "PriorityQueue.h"

using namespace std;

struct tPelicula{
	int ini;
	int duracion;
	int fin;
};

bool operator < (const tPelicula& a, const tPelicula& b) {
	return (a.ini < b.ini) || (a.ini == b.ini && a.duracion > b.duracion);
}

int maxMin(std::vector<tPelicula>& peliculas) {
	std::vector<bool> maraton(peliculas[peliculas.size() - 1].fin + 11, false);
	int cont = 0;

	for (int i = 0; i < peliculas.size(); i++) {
		if (!maraton[peliculas[i].ini]) {
			cont += peliculas[i].duracion;
			
			for (int j = 0; j < peliculas[peliculas.size() - 1].fin; j++) {
				if (j >= peliculas[i].ini && j < peliculas[i].fin) {
					maraton[j] = true;
				}
				else {
					maraton[j] = false;
				}
			}
		}
	}

	return cont;
}

bool resuelveCaso(){
	int n;
	std::cin >> n;

	if (n == 0) {
		return false;
	}

	std::vector<tPelicula> peliculas;
	int hh, mm, duracion;
	char c;

	while (n--) {
		std::cin >> hh >> c >> mm >> duracion;
		peliculas.push_back({hh*60+mm, duracion, hh*60+mm+10+duracion});
	}

	std::sort(peliculas.begin(), peliculas.end());

	int solucion = maxMin(peliculas);

	std::cout << solucion << "\n";

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