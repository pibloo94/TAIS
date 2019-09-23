//PABLO AGUDO BRUN

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "PriorityQueue.h"

using namespace std;


long long int resolver(PriorityQueue<long long int>& cola) {
	long long int x, y;
	long long int esfuerzo = 0;

	if (cola.size() != 0) {
		while (cola.size() > 1) {
			x = cola.top();
			cola.pop();

			y = cola.top();
			cola.pop();

			esfuerzo += x + y;
			cola.push(x + y);
		}
	}

	return esfuerzo;
}

bool resuelveCaso() {
	long long int n;
	std::cin >> n;

	if (!n) {
		return false;
	}

	PriorityQueue<long long int> cola;
	long long int sumando;

	for (long long int i = 0; i < n; i++) {
		std::cin >> sumando;
		cola.push(sumando);
	}

	std::cout << resolver(cola) << "\n";

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