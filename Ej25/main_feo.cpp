//PABLO AGUDO BRUN

#include "PriorityQueue.h"

#include <iostream>
#include <fstream>
#include <algorithm> 
#include <vector>

using namespace std;


struct tSolucion {
	int edad = 0;
};

bool operator <(tSolucion const& a, tSolucion const& b) {
	return (a.edad < b.edad);
}

void resover(vector<int>& vsol, vector<int>& pajaros) {

	int i = 0, cont = 0, pos, totalPajaros = 2;

	//mientras haya pajaros que van llegando
	while (i < (pajaros.size() / 2)) {

		//para controlar que se unen en parejas
		while (cont < totalPajaros) {
			vsol.push_back(pajaros[cont]);
			cont++;
		}

		totalPajaros += 2;
		std::sort(vsol.begin(), vsol.end());

		pos = vsol.size() / 2;
		std::cout << vsol[pos] << " ";

		i++;
	}
}

bool resuelveCaso() {
	int cabeza, n, edad;

	std::cin >> cabeza >> n;

	if (cabeza == 0 && n == 0) {
		return false;
	}

	vector<int> vsol;
	vector<int> pajaros;

	//vector de pajaros que van uniendose
	n = n * 2;
	for (int i = 0; i < n; i++) {
		std::cin >> edad;
		pajaros.push_back(edad);
	}

	vsol.push_back(cabeza);

	resover(vsol, pajaros);

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