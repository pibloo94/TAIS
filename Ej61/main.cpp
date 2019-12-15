//PABLO AGUDO BRUN

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

struct tCofre {
	int profundidad;
	int oro;
};

/*
tesoro(i, j) = {
			tesoro(i-1, j) sii cofre[i].profundidad*3 > j
			max(tesoro(i-1, j), tesoro(i-1, j-cofre[i].profundidad + cofre[i].oro) sii cofre[i].profundidad*3 <= j
			}
*/
int maxOro(
	std::vector <std::vector<int>>& matriz,
	std::vector <tCofre>& cofres,
	int const& T) {

	int N = cofres.size() - 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= T; j++) {
			int coste = cofres[i].profundidad * 3;

			if (coste > j) {
				matriz[i][j] = matriz[i - 1][j];
			}
			else {
				matriz[i][j] = std::max(matriz[i - 1][j], matriz[i - 1][j - coste] + cofres[i].oro);
			}
		}
	}

	return matriz[N][T];
}

std::vector<bool> recuperados(
	std::vector <std::vector<int>>& matriz,
	std::vector <tCofre>& cofres,
	const int& T,
	int& recoger) {

	std::vector<bool> v(matriz.size(), false);
	int tiempo = T;

	for (int i = matriz.size() - 1; i >= 1; i--) {
		if (matriz[i][tiempo] != matriz[i - 1][tiempo]) {
			v[i] = true;
			tiempo -= cofres[i].profundidad * 3;
		}
	}

	return v;
}

bool resuelveCaso() {
	int T, N, profundidad, oro;

	std::cin >> T;

	if (!std::cin) {
		return false;
	}

	std::cin >> N;

	std::vector<tCofre> cofres(N + 1);

	for (int i = 1; i <= N; i++) {
		std::cin >> profundidad >> oro;
		cofres.push_back({ profundidad, oro });
	}
	
	std::vector <std::vector<int>> matriz(N + 1, std::vector<int>(T + 1, 0)); //Matriz

	for (int i = 0; i <= N; i++) {
		matriz[i][0] = 0;
	}

	for (int j = 1; j <= T; j++) {
		matriz[0][j] = 0;
	}

	std::cout << maxOro(matriz, cofres, T) << "\n";

	int recoger = 0;
	std::vector<bool> cofresRecuperados = recuperados(matriz, cofres, T, recoger);

	for (int i = 1; i < cofresRecuperados.size(); i++) {
		if (cofresRecuperados[i]) {
			std::cout << cofres[i].profundidad << " " << cofres[i].oro << "\n";
		}
	}

	std::cout << "----\n";

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}