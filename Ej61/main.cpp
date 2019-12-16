//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#include "Matriz.h"

using namespace std;

const int INF = 1000000000;

struct tCofre {
	int profundidad;
	int oro;
};

/*
Problema de la mochila (elegimos si rescatamos el cofre o no), se crea matriz con:
- Filas = N (el numero de cofres)
- Columnas = T (el tiempo de la botella)

casos base:
	- tesoros(0, j) = 0
	- tesoros(i, 0) = 0

casos recursivos:
	- tesoros(i, j) = tesoros(i - 1, j)
	- tesoros(i, j) = max(tesoros(i- 1, j) , tesoros(i-1, j-cofres[i].profundidad) + cofres[i].oro)
*/

int cofresRescatados(std::vector<tCofre>& cofres, Matriz<int>& tabla, const int& T, std::vector<bool>& rescatados) {
	int aux = T;
	int n = cofres.size() - 1;
	int nCofres = 0;

	for (int i = n; i >= 1; i--) {
		if (tabla[i][aux] != tabla[i-1][aux]) {
			rescatados[i] = true;
			aux -= cofres[i].profundidad;
			nCofres++;
		}
	}

	return nCofres;
}

int cantMax(std::vector<tCofre>& cofres, Matriz<int>& tabla, const int& T){
	int n = cofres.size() - 1;

	//recorremos la tabla y la vamos rellenando
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= T; j++) {
			if (cofres[i].profundidad > j) {
				tabla[i][j] = tabla[i - 1][j];
			}
			else {
				tabla[i][j] = std::max(tabla[i-1][j], tabla[i-1][j-cofres[i].profundidad] + cofres[i].oro);
			}
		}
	}

	return tabla[n][T];
}

bool resuelveCaso() {
	int N, T, profundidad, oro;

	std::cin >> T;

	if (!std::cin) {
		return false;
	}

	std::cin >> N;

	//vector de cofres con el oro y el tiempo (profundidad) que se tarda en cada uno
	std::vector<tCofre> cofres;
	cofres.push_back({ 0, 0 });

	//relleno el vector de cofres
	for (int i = 1; i <= N; i++) {
		std::cin >> profundidad >> oro;
		cofres.push_back({ profundidad * 3, oro }); // profundidad = p (bajar) + 2p (subir) = 3 * profundidad
	}

	//vector de rescatados que contiene aquellos cofres seleccionados
	std::vector<bool> rescatados(N+1, false);
	Matriz<int> tabla(N+1, T+1, 0);

	int oroMax =cantMax(cofres, tabla, T);
	int totalRescatados = cofresRescatados(cofres, tabla, T, rescatados);

	if(totalRescatados == 0){
		std::cout << "0\n0\n";
	}
	else {
		std::cout << oroMax << "\n";
		std::cout << totalRescatados << "\n";

		for (int i = 0; i < rescatados.size(); i++) {
			if (rescatados[i]) {
				std::cout << cofres[i].profundidad / 3 << " " << cofres[i].oro << "\n";
			}
		}
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