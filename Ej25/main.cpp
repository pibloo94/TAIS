//PABLO AGUDO BRUN

#include "PriorityQueue.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


struct tSolucion {
	int edad = 0;
};

bool operator <(tSolucion const& a, tSolucion const& b) {
	return (a.edad < b.edad);
}

void resover(PriorityQueue<tSolucion>& colap, vector<int>& pajaros) {

	int i = 0, cont = 0, primero;
	vector<int> vsol;

	//mientras haya pajaros que van llegando
	while (i < (pajaros.size()/2)) {

		//para controlar que se unen en parejas
		while (cont != 0 || cont%2 != 0) {
			colap.push({ pajaros.at(cont) });
			cont++;
		}

		while (!colap.empty()) {
			vsol.push_back(colap.top().edad);
			colap.pop();
		}

		primero = vsol.size() / 2;
		colap.push({ vsol[primero] });

		std::cout << vsol[primero] << " ";

		i++;
	}
}

bool resuelveCaso() {
	int cabeza, n, edad;

	std::cin >> cabeza >> n;

	if (cabeza == 0 && n == 0) {
		return false;
	}

	//cola de prioridad inicial (solo con el pajaro de cabeza)
	PriorityQueue<tSolucion> colap;
	colap.push({ cabeza });

	//vector de pajaros que van uniendose
	n = n * 2;
	vector<int> pajaros;
	for (int i = 0; i < n; i++) {
		std::cin >> edad;
		pajaros.push_back(edad);
	}

	resover(colap, pajaros);

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