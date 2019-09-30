//PABLO AGUDO BRUN

#include "PriorityQueue.h"

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


struct tSolucion {
	int tiempo = 0;
};


bool operator <(tSolucion const& a, tSolucion const& b) {
	return (a.tiempo > b.tiempo);
}

void resolver(int& N,
	tSolucion& sol,
	PriorityQueue<tSolucion>& colap9,
	PriorityQueue<tSolucion>& colap1_5) {

	int aux = 0, t9 = 0, t1_5 = 0, t = 0, J; //para calcular la diferencia
	std::vector<int> usadas9; //pilas usadas de 9V
	std::vector<int> usadas1_5; //pilas usadas de 1.5V

	//mientras tenga pilas en la caja
	while (!colap9.empty() && !colap1_5.empty()) {
		J = 0;
		t = 0;

		//mientras que tenga pilas y tenga drones que volar
		while (!colap9.empty() && !colap1_5.empty() && J < N) {
			t9 = colap9.top().tiempo;
			t1_5 = colap1_5.top().tiempo;

			colap9.pop();
			colap1_5.pop();

			//si tiene mayor tiempo de duracion la pila de 9V que la de 1.5V
			if (t9 > t1_5) {
				aux = t9 - t1_5;
				t += t1_5;
				usadas9.push_back(aux);
			}
			//si tiene mayor tiempo de duracion la pila de 1.5V que la de 9V
			else if (t9 < t1_5) {
				aux = t1_5 - t9;
				t += t9;
				usadas1_5.push_back(aux);
			}
			//si ambas tienene la misma duracion
			else {
				t += t9;
			}

			J++;
		}

		//volvemos a meter las pilas con carga en las cajas
		for (int i = 0; i < usadas9.size(); i++) {
			colap9.push({usadas9.at(i)});
		}

		for (int i = 0; i < usadas1_5.size(); i ++) {
			colap1_5.push({usadas1_5.at(i)});
		}

		//vaciamos los arrays de usadas
		usadas9.clear();
		usadas1_5.clear();

		std::cout << t << " ";
	}
}

bool resuelveCaso() {
	int N, pilasA, pilasB;
	int hora;
	tSolucion sol;
	
	std::cin >> N >> pilasA >> pilasB;

	if (!std::cin) {
		return false;
	}

	//rellenamos cola pilas 9V
	PriorityQueue<tSolucion> colap9;

	for (int i = 0; i < pilasA; i++) {
		std::cin >> hora;
		sol.tiempo = hora;
		colap9.push(sol);
	}

	//rellenamos cola pilas de 1.5V
	PriorityQueue<tSolucion> colap1_5;

	for (int i = 0; i < pilasB; i++) {
		std::cin >> hora;
		sol.tiempo = hora;
		colap1_5.push(sol);
	}

	//llamamos a resolver el problema
	resolver(N, sol, colap9, colap1_5);
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