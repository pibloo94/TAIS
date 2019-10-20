//PABLO AGUDO BRUN

#include "GrafoDirigido.h"
#include "GrafoJuego.h"

#include <fstream>
#include <iostream>

using namespace std;


bool resuelveCaso() {
	int N, K, S, E;

	std::cin >> N >> K >> S >> E;

	if (N == 0 && K == 0 && S == 0 && E == 0) {
		return false;
	}
	
	int dimensiones = N * N;

	GrafoDirigido tablero(dimensiones);

	GrafoJuego partida(tablero, 0, K, S, E);

	std::cout << partida.movimientos(tablero.V() - 1) << "\n";

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