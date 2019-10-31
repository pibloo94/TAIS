//PABLO AGUDO BRUN

#include<iostream>
#include<fstream>
#include <vector>
#include <queue>

using namespace std;


const std::vector<std::pair<int, int>> direcciones = { {1, 0}, {0, 1}, {-1, 0}, {0, - 1} };

struct tSensor {
	int x;
	int y;
	int valor;
};

bool posicionCorrecta(int const& i, int const& j, int alto, int ancho) {
	return i >= 0 && j >= 0 && i < alto && j < ancho;
}

void resolver(
	std::vector<std::vector<char>>& laberinto,
	std::vector<std::vector<bool>>& marked,
	std::pair<int, int>& ini,
	std::pair<int, int>& fin,
	int const& alto, int const& ancho){

	std::vector<std::vector<int>> distTo (alto, std::vector<int>(ancho));
	std::queue<std::pair<int, int>> cola;
	std::pair<int, int > pos;
	
	cola.push(ini);
	marked[ini.first][ini.second] = true;
	distTo[ini.first][ini.second] = 0;

	while (!cola.empty()) {
		pos = cola.front();
		cola.pop();

		for (auto direccion : direcciones) {
			int ni = pos.first + direccion.first;
			int nj = pos.second + direccion.second;

			if (posicionCorrecta(ni, nj, alto, ancho) && !marked[ni][nj]) {
				marked[ni][nj] = true;
				distTo[ni][nj] = 1 + distTo[pos.first][pos.second];
				cola.push({ ni, nj });
			}
		}
	}

	if (laberinto[ini.first][ini.second] == 'X' || laberinto[fin.first][fin.second] == 'X' || !marked[fin.first][fin.second]) { //marco con X si el sensor vigila esa casilla
		std::cout << "NO\n";
	}
	else {
		std::cout << distTo[fin.first][fin.second] << "\n";
	}	
}

void ponerSensor(
	std::vector<std::vector<char>>& laberinto,
	std::vector<std::vector<bool>>& marked,
	std::vector<tSensor>& sensores,
	int& ancho, int& alto) {

	for (int i = 0; i < sensores.size(); i++) {
		tSensor sensor = sensores[i];

		marked[sensor.x][sensor.y] = true;

		for (auto direccion : direcciones) {
			int cont = 0;
			int ni, nj;

			if (direccion.first == 1) {
				ni = sensor.x + direccion.first;
				nj = sensor.y;

				while (posicionCorrecta(ni, nj, alto, ancho) && laberinto[ni][nj] != '#' && cont < sensor.valor) {
					marked[ni][nj] = true;
					laberinto[ni][nj] = 'X'; 
					cont++;
					ni++;
				}
			}
			else if (direccion.second == 1) {
				ni = sensor.x;
				nj = sensor.y + direccion.second;

				while (posicionCorrecta(ni, nj, alto, ancho) && laberinto[ni][nj] != '#' && cont < sensor.valor) {
					marked[ni][nj] = true;
					laberinto[ni][nj] = 'X';
					cont++;
					nj++;
				}
			}
			else if (direccion.first == -1) {
				ni = sensor.x + direccion.first;
				nj = sensor.y;

				while (posicionCorrecta(ni, nj, alto, ancho) && laberinto[ni][nj] != '#' && cont < sensor.valor) {
					marked[ni][nj] = true;
					laberinto[ni][nj] = 'X';
					cont++;
					ni--;
				}
			}
			else if (direccion.second == -1) {
				ni = sensor.x;
				nj = sensor.y + direccion.second;

				while (posicionCorrecta(ni, nj, alto, ancho) && laberinto[ni][nj] != '#' && cont < sensor.valor) {
					marked[ni][nj] = true;
					laberinto[ni][nj] = 'X';
					cont++;
					nj--;
				}
			}
		}
	}
}

void resuelveCaso() {
	int ancho, alto;
	char c;

	std::cin >> ancho >> alto;

	std::pair<int, int> ini, fin;
	std::vector<std::vector<char>> laberinto (ancho, std::vector<char>(alto));
	std::vector<std::vector<bool>> marked (ancho, std::vector<bool>(alto));
	std::vector<tSensor> sensores;
	
	for (int i = 0; i < ancho; i++) {
		for (int j = 0; j < alto; j++) {
			std::cin >> c;

			if (c == 'E') {
				ini.first = i;
				ini.second = j;
				laberinto[i][j] = 'E';
			}
			else if (c == 'P') {
				ini.first = i;
				ini.second = j;
				laberinto[i][j] = 'P';
			}
			else if (c == '#') {
				marked[i][j] = true;
				laberinto[i][j] = '#';
			}
			else if (c == '.') {
				laberinto[i][j] = '.';
			}
			else {
				int valor = c - 48;
				tSensor sensor = { i, j, valor };
				sensores.push_back(sensor); 
				laberinto[i][j] = 'S'; //marco si hay sensor con una S
			}
		}
	}

	ponerSensor(laberinto, marked, sensores, ancho, alto);
	resolver(laberinto, marked, ini, fin, ancho, alto);

}


int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;

	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}