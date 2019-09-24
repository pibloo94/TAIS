//PABLO AGUDO BRUN

#include "PriorityQueue.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;


struct tPaciente {
	std::string nombre;
	int gravedad;
	int tiempo;
};

bool operator < (tPaciente const& a, tPaciente const& b) {
	return a.gravedad > b.gravedad || (a.gravedad == b.gravedad && a.tiempo < b.tiempo);
}

void resolver(PriorityQueue<tPaciente>& colap, int& eventos) {
	char tipo;
	int cont = 0;
	tPaciente paciente;

	while (eventos != 0) {
		std::cin >> tipo;

		if (tipo =='I') {
			std::cin >> paciente.nombre;
			std::cin >> paciente.gravedad;
			paciente.tiempo = cont;
			colap.push(paciente);
			eventos--;
			cont++;
		}
		else {
			std::cout << colap.top().nombre << "\n";
			colap.pop();
		}
	}
}

bool resuelveCaso() {
	int eventos;

	std::cin >> eventos;

	if (!eventos) {
		return false;
	}

	PriorityQueue<tPaciente> colap;

	resolver(colap, eventos);

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