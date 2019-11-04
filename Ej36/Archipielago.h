//PABLO AGUDO BRUN

#include "GrafoValorado.h"
#include "PriorityQueue.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;


//Aplicamos el algoritmo de PRIM
class Archipielago {
private:
	std::vector<bool> marked; //MST vertices
	std::queue<Arista<int>> mst; //MST edges (Minimum Spanning Tree)
	PriorityQueue<Arista<int>> pq; //PQ of edges
	int coste;
	bool esConexo;

	void LazyPrimMST(GrafoValorado<int> const& g) {
		visit(g, 0);

		while (!pq.empty() && mst.size() < g.V() - 1){
			Arista<int> e = pq.top();
			pq.pop();
			int v = e.uno(), w = e.otro(v);

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

	void visit(GrafoValorado<int> const& g, int v){
		marked[v] = true; //add v to T

		for (auto e : g.ady(v)) { //for each edge e = v–w, add to PQ if w not already in T
			if (!marked[e.otro(v)]) {
				pq.push(e);
			}
		}
	}

public:

	Archipielago(GrafoValorado<int> const& g) : marked(g.V(), false), coste(0), esConexo(true){
		int conexo = 0; //solo debe de existir una componente conexa ya que buscamos el arbol de recubrimiento minimo

		for (int i = 0; i < g.V() && esConexo; i++) {
			if (!marked[i]) {
				conexo++;

				if (conexo > 1) { //en el momento que sea mayor que 1 nuestro arbol deja de ser conexo
					esConexo = false;
				}

				LazyPrimMST(g);
			}
		}
	}

	int costeTotal() {
		return coste;
	}

	bool esArbolConexo() {
		return esConexo;
	}

};