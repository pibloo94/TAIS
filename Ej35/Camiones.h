//PABLO AGUDO BRUN

#include"GrafoValorado.h"

#include <iostream>
#include <fstream>
#include <vector>

class Camion {
private:
	std::vector<bool> marked;

	void dfs(GrafoValorado<int> const& g, int& origen, int& anchura) {
		marked[origen] = true; //marco el origen de donde parte el camion

		for (auto w : g.ady(origen)) {
			int aux = w.otro(origen);

			if (!marked[aux]) { //me devuelve otro adyacente si no esta marcado
				if (anchura <= w.valor()) { //si la calle permite la anchura del camion
					dfs(g, aux, anchura);
				}
			}
		}
	}


public:
	Camion(GrafoValorado<int> const& grafo, int origen, int anchura) : marked(grafo.V(), false) {
		dfs(grafo, origen, anchura);
	}

	bool dest(int destino) {
		return marked[destino];
	}
};


