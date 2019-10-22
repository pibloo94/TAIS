//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class MatrizOvejas {
private:
	int ancho, alto;
	int blancas, negras;
	std::vector<std::vector<bool>> marked;
	std::vector<std::pair<int, int>> adyacentes = { {0, 1}, {1, -1}, {1, 0}, {-1, -1}, {0, -1}, {-1, 1}, {1, 0}, {1, 1} };

	bool correcta(int i, int j) {
		return 0 <= i && i < ancho && 0 <= j && j < alto;
	}

	void contarBlanca(std::vector<std::vector<char>> imagen, int& tam, int& i, int& j) {
		marked[i][j] = true;
		tam++;

		for (auto y: adyacentes) {
			int auxi = i + y.first, auxj = j + y.second;

			if (correcta(auxi, auxj) && (imagen[auxi][auxj] == 'X' && !marked[auxi][auxj])) {
				contarBlanca(imagen, tam, auxi, auxj);
			}
		}
	}

public:

	MatrizOvejas(std::vector<std::vector<char>> const& imagen) : marked(ancho, std::vector<bool>(alto, false)), blancas(0), negras(0), ancho(imagen.size()), alto(imagen[0].size()) {
		for (int i = 0; i < ancho; i++) {
			for (int j = 0; j < alto; j++) {
				if (imagen[i][j] == 'X' && !marked[i][j]) {
					int tam = 0;
					contarBlanca(imagen, tam, i, j);

					if (tam == 22) {
						blancas++;
					}
				}
			}
		}
	}

	int contBlancas() {
		return blancas;
	}

	int contNegras() {
		return negras;
	}

};

