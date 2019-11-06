//PABLO AGUDO BRUN

#include "GrafoValorado.h"
#include "PriorityQueue.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>

//Aplicamos PRIM 
class Camino {
private:
	std::vector<int> marked;
	std::queue<Arista<int>> mst;
	PriorityQueue<Arista<int>> pq;
	int coste;
	bool esPosible;

	void lazyPrimMST(GrafoValorado<int> const& g) {
		visit(g, 0);

		while (!pq.empty() && mst.size() < g.V() - 1) {
			Arista<int> e = pq.top();
			pq.pop();

			int v = e.uno();
			int w = e.otro(v);

			if (marked[v] && marked[w]) {
				continue;
			}

			mst.push(e);
			coste += e.valor();

			if (!marked[v]) {
				visit(g, v);
			}

			if (!marked[w]) {
				visit(g, w);
			}
		}
	}


	void visit(GrafoValorado<int> const& g, int v) {
		marked[v] = true;

		for (auto e : g.ady(v)) {
			if (!marked[e.otro(v)]) {
				pq.push(e);
			}
		}
	}

public:

	Camino(GrafoValorado<int> const& g) : marked(g.V(), false), coste(0), esPosible(true) {
		int cont = 0;

		for (int i = 0; i < g.V() && esPosible; i++) {
			if (!marked[i]) {
				cont++;

				if (cont > 1) {
					esPosible = false;
				}

				lazyPrimMST(g);
			}
		}
	}

	int getCoste() {
		return coste;
	}

	bool getEsPosible() {
		return esPosible;
	}
};
