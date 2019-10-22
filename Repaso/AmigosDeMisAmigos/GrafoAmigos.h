//PABLO AGUDO BRUN

#include "Grafo.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


class GrafoAmigos {
public:

	GrafoAmigos(Grafo const &g) : marked(g.V(), false), x(0){
		int tam;
		for (int i = 0; i < g.V(); i++) {
			if (!marked[i]) {
				tam = 0;
				maxConexa(g, i, tam);
				x = std::max(tam, x);
			}
		}
	}

	int maximo() {
		return x;
	}

private:
	int x;
	std::vector <bool> marked;

	//coste de la solucion O(V+E)
	void maxConexa(Grafo const &g, int& v, int& tam) {
		marked[v] = true;
		tam++;

		for (int w : g.ady(v)) {
			if (!marked[w]) {
				maxConexa(g, w, tam);
			}
		}
	}
};