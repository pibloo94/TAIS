//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Matriz.h"

using namespace std;

struct tSolucion {
	int puntuacion;
	int columna = 1;
};

/*
casos recursivos:
	- puntuaciones(i, j) = tablero(i, j) sii puntuaciones(i-1, j) == -1 , es decir, esta fuera del tablero.
	- puntuaciones(i, j) = max(puntuaciones(i-1, j-1), puntuaciones(i-1, j), puntuaciones(i-1, j+1)) + tablero(i, j) en otro caso.

El coste del algoritmo es O(N*N) con N igual al numero de filas y columnas del tablero.
*/
tSolucion maxPuntuacion(Matriz<int> tablero, int const& N) {
	tSolucion solucion;
	Matriz<int> puntuaciones(N+1, N+2, -1);

	//rellenamos la tabla de puntuaciones
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (puntuaciones[i-1][j] == -1 ) { //si esta fuera del tablero
				puntuaciones[i][j] = tablero[i][j];
			}
			else {//en caso contrario calculamos el maximo entre las tres posibles posiciones
				int maxValor = std::max(puntuaciones[i - 1][j - 1], std::max(puntuaciones[i-1][j+1], puntuaciones[i-1][j]));
				puntuaciones[i][j] = maxValor + tablero[i][j];
			}
		}
	}

	//comprobamos la columna por la que empezar
	for (int j = 1; j <= N; j++) {
		if (puntuaciones[N][j] > puntuaciones[N][solucion.columna]) {
			solucion.columna = j;
		}
	}

	solucion.puntuacion = puntuaciones[N][solucion.columna];

	return solucion;
}

bool resuelveCaso() {
	int N;

	std::cin >> N;

	if (!std::cin) {
		return false;
	}

	//creamos la matriz y la inizializamos a -1 con dimensiones N+1 y N+2 para saber cuando
	//nos encontramos fuera del tablero
	Matriz<int> tablero(N+1, N+2, -1);

	//rellenamos el tablero
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			std::cin >> tablero[i][j];
		}
	}

	tSolucion solucion = maxPuntuacion(tablero, N);

	std::cout << solucion.puntuacion << " " << solucion.columna << "\n";

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