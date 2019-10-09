//PABLO AGUDO BRUN

#include "Grafo.h"

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class GrafoBipartito {
public:
	GrafoBipartito(Grafo const& g) : marked(g.V(), false), color(g.V()), esBipartito(true) {
		for (int i = 0; i < g.V() && esBipartito; i++) {
			if (!marked[i]) {
				color[i] = true;
				esBipartito = dfs(g, i);
			}
		}
	}

	bool esGrafoBipartito() {
		return esBipartito;
	}

private:
	bool esBipartito;
	vector<bool> marked;
	vector<bool> color;

	bool dfs(Grafo const& g, int v) {
		marked[v] = true;

		for (int w : g.ady(v)) {
			if (!marked[w]) {
				color[w] = !color[v];

				if (!dfs(g, w)) {
					return false;
				}
			}
			else if (color[w] == color[v]) {
				return false;
			}
		}

		return true;
	}
};