//PABLO AGUDO BRUN

#include "PriorityQueue.h"

#include <fstream>
#include <iostream>

using namespace std;


struct tCaja{
	int id;
	int tiempo;
};

bool operator < (tCaja const& a, tCaja const& b) {
	if (a.tiempo < b.tiempo) {
		return true;
	}
	else if(a.tiempo > b.tiempo){
		return false;
	}
	else{
		if (a.id < b.id) {
			return true;
		}
		else {
			return false;
		}
	}
}

void resolver(PriorityQueue<tCaja>& colap, int& C) {
	int tiempo;

	while (C != 0) {
		std::cin >> tiempo;

		tCaja caja = colap.top();
		colap.pop();
		caja.tiempo += tiempo;
		colap.push(caja);
		C--;
	}

	std::cout << colap.top().id << "\n";
}

bool resuelveCaso() {
	int N, C;

	std::cin >> N >> C;

	if (N == 0 && C == 0) {
		return false;
	}
	
	PriorityQueue<tCaja> colap;
	tCaja caja;

	for (int i = 1; i <= N; i++) {
		caja.id = i;
		caja.tiempo = 0;
		colap.push(caja);
	}

	resolver(colap, C);

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