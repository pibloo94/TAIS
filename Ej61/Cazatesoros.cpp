// Manuel Monforte
// TAIS62

/*
El ejercicio se plante como el problema de la mochila. Por tanto se crea una matriz donde las 
filas serán el cofre N, y las columnas el tiempo transcurrido. Al terminar debemos recorrer el resultado 
obtenido para saber que cofre hemos cogido exactamente.

Funcion--> cazateoros[i][j] = cazatesoros[i - 1][j] si el tiempo de ese cofre es mayor del que estamos actualmente
		   cazatesoros[i][j] = std::max(cazatesoros[i - 1][j], cazatesoros[i - 1][j - cofres[i].tiempo] + cofres[i].oro)
				sino, podemos coger u nuevo cofre, y obtenemos el maximo entre el anterior y el valor de este sumado

Coste de la solcuion--> O(N*T) siendo n el numero de cofres y T el tiempo de la botella


*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Matriz.h"

struct tCofre{
	int tiempo;
	int oro;

	tCofre(){};
	tCofre(int o, int t) : oro(o), tiempo(t){};
};


void recogeCofres(const std::vector<tCofre> & cofres, int T, int & oroMax, std::vector<bool> & selccionados, int & numCofres){
	int n = cofres.size() - 1;
	Matriz<int> cazatesoros(n + 1, T + 1, 0);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= T; j++){
			if (cofres[i].tiempo > j) cazatesoros[i][j] = cazatesoros[i - 1][j];
			else cazatesoros[i][j] = std::max(cazatesoros[i - 1][j], cazatesoros[i - 1][j - cofres[i].tiempo] + cofres[i].oro);
		}
	}

	oroMax = cazatesoros[n][T];

	//obtenemos cofres seleccionados
	int resto = T;

	for (int i = n; i >= 1; i--){
		if (cazatesoros[i][resto] == cazatesoros[i - 1][resto]){
			selccionados[i] = false;
		}
		else{
			selccionados[i] = true;
			resto -= cofres[i].tiempo;
			numCofres++;
		}
	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int T, N, p, o;
	std::cin >> T >> N;
	if (!std::cin)
		return false;
	std::vector<tCofre> listaCofres;
	listaCofres.push_back({ 0, 0 });

	for (int i = 1; i <= N; i++){
		std::cin >> p >> o;
		listaCofres.push_back({ o, 3*p });
	}
	//--------------------
	std::vector<bool> seleccionados((N + 1),false);
	int oro = 0;
	int cofresRecogidos = 0;

	recogeCofres(listaCofres, T, oro, seleccionados, cofresRecogidos);
	
	//si no hay oro
	if (oro == 0){
		std::cout << "0\n";
		std::cout << "0\n";
		std::cout << "----\n";
	}
	// hay oro, por tanto se ha recogido algun cofre
	else{
		std::cout << oro << "\n";
		std::cout << cofresRecogidos << "\n";
		for (int i = 0; i < seleccionados.size(); i++){
			if (seleccionados[i])
				std::cout << listaCofres[i].tiempo / 3 << " " << listaCofres[i].oro << "\n";
		}
		std::cout << "----\n";
	}


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}