//Pablo Agudo Brun / Raúl Benavente Romero TAIS13


//Creamos una estructura llamada tarea en donde guardamos los datos de cada tarea: su inicio, su fin y, en caso de tener periodo, sera distinto de 0.
//Definimos el operator < en funcion de los tiempos de inicio de cada tarea
//En resolver usamos el periodo y la cola para ir comprobando con una frecuencia T si el final de una tarea entra en conflicto con el inicio de la siguiente
//En caso de que una tarea sea periodica, actualizamos el inicio y final, y la reinsertamos en la cola

//Coste: O(N*log n)

#include "PriorityQueue.h"

#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;

struct tarea {
	int inicio;
	int final;
	int periodo;
};

bool operator<(tarea const& a, tarea const& b) {
	return a.inicio < b.inicio;
}

bool resolver(int &T, PriorityQueue<tarea> &cola) {
	bool esConflicto = false;
	tarea aux;
	int iniSig = 0;

	while (!esConflicto && !cola.empty() && cola.top().inicio < T) {
		aux = cola.top(); 
		cola.pop();

		if (iniSig > aux.inicio) {
			esConflicto = true;
		}

		iniSig = aux.final;

		if (aux.periodo > 0) {
			aux.inicio += aux.periodo;
			aux.final += aux.periodo;
			cola.push(aux);
		}

	}

	return esConflicto;
}

bool resuelveCaso() {
   
   // leemos la entrada
   int N, M, T;
   cin >> N >> M >> T;
   if (!cin)
       return false;
	
   PriorityQueue<tarea> cola;
   int ini, fin,per;

   for (int i = 0; i < N; i++) {
	   cin >> ini >> fin;
	   cola.push({ ini,fin,0 });
   }
   for (int i = 0; i < M; i++) {
	   cin >> ini >> fin >> per;
	   cola.push({ ini,fin,per });
   }

   bool conflicto = resolver(T, cola);

   if (conflicto)
	   cout << "SI\n";
   else
	   cout << "NO\n";
   // leer el resto del caso y resolverlo
   

   return true;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   // Resolvemos
   while (resuelveCaso());
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
