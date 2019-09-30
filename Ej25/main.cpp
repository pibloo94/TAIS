//PABLO AGUDO BRUN

#include "PriorityQueue.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


struct tSolucion {
	int edad = 0;
};

bool operator <(tSolucion const& a, tSolucion const&b) {
	return (a.edad < b.edad);
}

void resover(PriorityQueue<tSolucion>& colap, vector<int>& pajaros) {

	int cont, primero;

	//mientras haya pajaros que van llegando
	while (pajaros.size() != 0) {
		cont = 0;

		//para controlar que se unen en parejas
		while (cont != 2) {
			colap.push({ pajaros.at(cont) });
			pajaros.pop_back();
			cont++;
		}

		primero = colap.size() / 2;

		std::cout << primero << " ";
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
	colap.push({cabeza});

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