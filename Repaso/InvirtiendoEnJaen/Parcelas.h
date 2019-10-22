//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const std::vector<std::pair<int, int>> adyacentes = { {0, 1}, {1, 0}, {0,-1}, {-1, 0} };

class Parcelas {
private:
	std::vector<std::vector<bool>> marked;
	int maximo, F, C;

	bool cumple(int i, int j) {
		return i >= 0 && j >= 0 && i < F && j < C;
	}

	void dfs(std::vector<string> terreno, int tam, int i, int j) {
		marked[i][j] = true;
		tam++;

		for (auto x : adyacentes) {
			int auxi = i + x.first;
			int auxj = j + x.second;

			if (cumple(auxi, auxj) && !marked[auxi][auxj] && terreno[auxi][auxj] == '#') {
				dfs(terreno, tam, auxi, auxj);
			}
		}
	}

public:

	Parcelas(std::vector<string> terreno) : maximo(0), F(terreno.size()) , C(terreno[0].size()), marked(terreno.size(), std::vector<bool>(terreno[0].size(), false)){
		for (int i = 0; i < F; i++) {
			for (int j = 0; j < C; j++) {
				if (!marked[i][j] && terreno[i][j] == '#') {
					int tam = 0;
					dfs(terreno, tam, i, j);
					maximo = std::max(tam, maximo);
				}
			}
		}
	}

	int maxParcela() {
		return maximo;
	}
};