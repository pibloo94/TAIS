//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#include "Grafo.h"
#include "PriorityQueue.h"

struct tNodo {
	int nodo;
	int dist;
};

bool operator < (tNodo const& a, tNodo const& b){
	return (a.dist < b.dist);
}

class NodoLejano {
public:
	NodoLejano(Grafo const& g, int& origen, int& ttl) : 
	marked(g.V(), false), distTo(g.V()), nodosVisitados(0) {
		marked[origen] = true;
		nodosVisitados++;
		tNodo nodo = {origen, 0};
		bfs(g, nodo, ttl);
	}

	int inalcanzables() {
		return marked.size() - nodosVisitados;
	}

private:
	std::vector<bool> marked;
	std::vector<int> distTo;
	int nodosVisitados;

	void bfs(Grafo const& g, tNodo& origen, int& ttl){
		PriorityQueue<tNodo> colap;
		tNodo nodo;
		colap.push(origen);

		while (!colap.empty()) {
			nodo = colap.top();
			colap.pop();

			for (auto w : g.ady(nodo.nodo)) {
				if (!marked[w] && nodo.dist < ttl) {
					marked[w] = true;
					nodosVisitados++;
					colap.push({ w, nodo.dist + 1 });
				}
			}
		}
	}
};