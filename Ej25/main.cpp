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

void resolver(int& cabeza, int& n) {
	PriorityQueue<int, std::greater<int>> cola_menores;
	PriorityQueue<int, std::less<int>> cola_mayores;

	int p, cont;

	for (int i = 0; i < n; i++) {
		cont = 0;

		//leo de dos en dos pajaros
		while (cont < 2) {
			std::cin >> p;

			if (p < cabeza) {
				cola_menores.push(p);
			}
			else {
				cola_mayores.push(p);
			}

			cont++;
		}

		if (cola_mayores.size() > cola_menores.size()) {
			cola_menores.push(cabeza);
			cabeza = cola_mayores.top();
			cola_mayores.pop();
		}
		else if(cola_mayores.size() < cola_menores.size()) {
			cola_mayores.push(cabeza);
			cabeza = cola_menores.top();
			cola_menores.pop();
		}

		std::cout << cabeza << " ";
	}
}

bool resuelveCaso() {
	int cabeza, n;

	std::cin >> cabeza >> n;

	if (cabeza == 0 && n == 0) {
		return false;
	}

	resolver(cabeza, n);

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