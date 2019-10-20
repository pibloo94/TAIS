//PABLO AGUDO  BRUN

#include "GrafoDirigido.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;


class GrafoJuego {
private:
	std::vector<bool>marked;
	std::vector<int> distancia;
	std::vector<int> SoE;
	std::queue<int> q;

	void bfs(GrafoDirigido &g, int n) {
		marked[n] = true;
		distancia[n] = 0;
		q.push(n);

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for(int y : g.ady(x)) {
				if(!marked[y]){
					marked[y] = true;
					distancia[y] = distancia[x] + 1;
					q.push(y);
				}
			}
		}
	}

	void crearTablero(GrafoDirigido& g, int K, int S, int E) {
		int x, y;

		for (int i = 0; i < S; i++) {
			std::cin >> x >> y;
			SoE[x - 1] = y - 1;
		}

		for (int i = 0; i < E; i++) {
			std::cin >> x >> y;
			SoE[x - 1] = y - 1;
		}

		for (int i = 0; i < g.V(); i++) {
			for (int j = i + 1; j <= i + K && j <= g.V() - 1; j++) {
				if (SoE[j] != -1) {
					g.ponArista(i, SoE[j]);
				}
				else {
					g.ponArista(i, j);
				}
			}
		}
	}

public:
	GrafoJuego(GrafoDirigido &g, int N, int K, int S, int E) : marked(g.V(), false), SoE(g.V(), - 1), distancia(g.V()) {
		crearTablero(g, K , S, E);
		bfs(g, N);
	}

	int movimientos(int n) {
		return distancia[n];
	}
};