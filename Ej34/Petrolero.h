//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#include "ConjuntosDisjuntos.h"

using namespace std;

const std::vector<std::pair<int, int>> direcciones = {
	{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};

class Petrolero {
public:
	Petrolero(std::vector<std::string> foto, int F, int C) :
		filas(F), columnas(C), conjunto (F*C), mancha(0), marked (F, std::vector<bool> (C, false)){

		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnas; j++) {
				if (foto[i][j] == '#' && !marked[i][j]) {
					int nueva_mancha = 0;
					dfs(foto, i, j, nueva_mancha);
					mancha = std::max(mancha, nueva_mancha);
				}
			}
		}
	}

	void nuevaFoto(std::vector<std::string> foto, int i, int j) {
		int v = i * columnas + j;
		bool hayNueva = false;

		for (auto direccion : direcciones) {
			int ni = i + direccion.first;
			int nj = j + direccion.second;

			if (posicionCorrecta(ni, nj) && foto[ni][nj] == '#') {
				int w = ni * columnas + nj;
				hayNueva = true;
				conjunto.unir(v, w);
				mancha = std::max(conjunto.tam(v), mancha);
			}
		}

		if (!hayNueva) {
			mancha = std::max(conjunto.tam(v), mancha);
		}
	}

	int getMancha() {
		return mancha;
	}

private:
	std::vector <std::vector<bool>> marked;
	ConjuntosDisjuntos conjunto;
	int mancha, filas, columnas;

	bool posicionCorrecta(int i, int j) {
		return (i >= 0 && j >= 0 && i < filas && j < columnas);
	}

	void dfs(std::vector<std::string> foto, int& i, int& j, int& nueva_mancha) {
		marked[i][j] = true;
		nueva_mancha++;

		for (auto direccion : direcciones) {
			int v = i * columnas + j;
			int ni = i + direccion.first;
			int nj = j + direccion.second;

			if (posicionCorrecta(ni, nj) && foto[ni][nj] == '#' && !marked[ni][nj]) {
				int w = ni * columnas + nj;
				conjunto.unir(v, w);
				dfs(foto, ni, nj, nueva_mancha);
			}
		}

	}
};