//PABLO AGUDO BRUN

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "PriorityQueue.h"

using namespace std;


struct registro {
	int momento;
	int id;
	int periodo; 
};

bool operator<(registro const& a, registro const& b) {
	return a.momento < b.momento ||
		(a.momento == b.momento && a.id < b.id);
}

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0) {
		return false;
	}

	PriorityQueue<registro> cola;

	for (int i = 0; i < N; ++i) {
		int id_usu, periodo;

		std::cin >> id_usu >> periodo;
		cola.push({ periodo, id_usu, periodo });
	}

	int envios;
	std::cin >> envios;

	while (envios--) {
		registro e = cola.top();
		cola.pop();
		cout << e.id << "\n";
		e.momento += e.periodo;
		cola.push(e);
	}

	std::cout << "---\n";

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