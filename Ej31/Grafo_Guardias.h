//PABLO AGUDO BRUN

#include "Grafo.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Grafo_Guardias {
private:
	int nGuardias;
	int rojos, azules;
	bool esBipartito;
	std::vector<bool> marked;
	std::vector<char> color;

	void ponerGuardias(Grafo const& g, int v) {
		char rojo = 'R', azul = 'A', neutro = 'N';

		marked[v] = true;

		for (int w : g.ady(v)) {
			if (color[w] == neutro) {
				//si el color del vertice padre es rojo pongo a su adyacente de azul
				if (color[v] == rojo) {
					color[w] = azul;
					azules++;
				}
				//si el color del vertice padre es azul pongo a su adyacente de rojo
				else if (color[v] == azul) {
					color[w] = rojo;
					rojos++;
				}

				if (!marked[w] && esBipartito) {
					ponerGuardias(g, w);
				}		
			}
			//si ambos guardias con una misma calle son del mismo color se devuelve false
			else if (color[w] == color[v]) {
				nGuardias = 0;
				esBipartito = false;
			}
		}
	}

public:

	Grafo_Guardias(Grafo const& g) : marked(g.V(), false), color(g.V(), 'N'), nGuardias(0), esBipartito(true), rojos(0), azules(0){
		for (int i = 0; i < g.V(); i++) {
			if (!marked[i]) {
				color[i] = 'R';
				rojos++;
				ponerGuardias(g, i);

				if (esBipartito) {
					nGuardias += std::min(rojos, azules);
				}

				rojos = 0;
				azules = 0;
			}
		}
	}

	int numGuardias() {
		return nGuardias;
	}

	bool bipartito() {
		return esBipartito;
	}

};