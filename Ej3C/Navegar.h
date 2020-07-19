//PABLO AGUDO BRUN

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

#include"GrafoDirigidoValorado.h"
#include "IndexPQ.h"

const int INF = 100000000;
/*
Coste del algoritmo:
	Al aplicar Dijsktra el coste de la solucion es O(ElogV)
*/

class Navegar {
public:
	Navegar(const GrafoDirigidoValorado<int>& grafo, std::vector<int>& dist) :
		marked(dist.size(), false),
		distTo(dist.size(), INF),
		pq(grafo.V()) {

		distTo[0] = 0;
		pq.push(0, 0);

		while (!pq.empty()) {
			auto v = pq.top().elem;
			pq.pop();

			for (auto e : grafo.ady(v)) {
				relax(e);
			}
		}
	}

	bool hayCamino() {
		bool existe = true;

		if (distTo[distTo.size() - 1] == INF) {
			existe = false;
		}

		return existe;
	}

	int camino() {
		return distTo[distTo.size() - 1];
	}

private:
	IndexPQ<int> pq;
	std::vector<bool>marked;
	std::vector<int>distTo;

	void relax(AristaDirigida<int>& e) {
		int v = e.from();
		int w = e.to();

		if (distTo[w] > distTo[v] + e.valor()) {
			distTo[w] = distTo[v] + e.valor();
			pq.update(w, distTo[w]);
		}
	}
};