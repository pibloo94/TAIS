//PABLO AGUDO BRUN

#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>

const int max = INT_MAX;

//Aplicamos Dijsktra ya que es un grafo dirigido
class Laberinto {
private:
	std::vector<int> distTo;
	IndexPQ<int> pq;
	int cont;

	void relax(AristaDirigida<int> const& e) {
		int v = e.from();
		int w = e.to();

		if (distTo[w] > distTo[v] + e.valor()) {
			distTo[w] = distTo[v] + e.valor();
			pq.update(w, distTo[w]);
		}

		//hacer update es equivalente a...
		/*
		if (pq.contains(w)) pq.decreaseKey(w, distTo[w]);
		else pq.insert (w, distTo[w]);
		*/
	}

	void ratones(int S, int T) {
		for (int i = 0; i < distTo.size(); i++) {
			if (i != S && distTo[i] <= T) {
				cont++;
			}
		}
	}

public:

	Laberinto(GrafoDirigidoValorado<int> const& g, int S, int T) : distTo(g.V(), max), pq(g.V()), cont(0) {
		GrafoDirigidoValorado<int> gInv = g.inverso();
		distTo[S] = 0;
		pq.push(S, 0);

		while (!pq.empty()) {
			int v = pq.top().elem;
			pq.pop();

			for (auto e : gInv.ady(v)) {
				relax(e);
			}
		}

		ratones(S, T);
	}

	int getCont() {
		return cont;
	}
};