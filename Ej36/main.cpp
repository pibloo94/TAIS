//PABLO AGUDO BRUN

#include "GrafoValorado.h"
#include "Archipielago.h"

#include <iostream>
#include <fstream>

using namespace std;


bool resuelveCaso() {
	int I, P;

	std::cin >> I;

	if (!std::cin) {
		return false;
	}

	//Creo el grafo valorado con I vertices
	GrafoValorado<int> grafo(I); 

	std::cin >> P;
	int v, w, valor;

	//Pongo las aristas con sus valores correspondientes
	for (int i = 0; i < P; i++) {
		std::cin >> v >> w >> valor;
		grafo.ponArista({v-1,w-1,valor});
	}

	Archipielago archipielago(grafo);

	if(archipielago.esArbolConexo()){
		std::cout << archipielago.costeTotal() << "\n";
	}
	else {
		std::cout << "No hay puentes suficientes\n";
	}


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