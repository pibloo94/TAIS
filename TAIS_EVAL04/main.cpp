
// PABLO AGUDO BRUN

// comentario sobre la solución, incluyendo el análisis del coste

/*
En el ejercicio creamos un vector para guardar todos los pesos y a continuacion aplicamos a este el algoritmo sort
para ordenar los pesos de manera creciente. Una vez con el vector ordenado pasamos a calcular el numero minimo de sillas,
para ello vamos comprobando el peso soportado por las sillas junto con los pesos de los esquiadores.

Insertando los datos en el vector tenemos una complejidad de O(N)
Usando el algoritmo sort para ordenar los diferentes pesos tenemos una complejidad de O(NlogN)
La funcion encargada de resolver el problema tiene un coste constante, por lo tanto su complejidad es de O(N)
El coste total del algoritmo es por lo tanto de O(NlogN)
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


int resolver(std::vector<int>& v, int& peso_maximo) {
	int min = 0;
	int actual ;
	int ini = 0, end = v.size() - 1;
	bool medio = true;

	while (ini <= end) {
		if (v[ini] + v[end] <= peso_maximo) {
			min++;
			ini++;
			end--;
		}
		else if (v[ini] == v[end]) {
			min++;
			ini++;
		}
		else{
			min++;
			end--;
		}
	}

	return min;
}

bool resuelveCaso() {
   
   int peso_maximo, N;
   cin >> peso_maximo >> N;
   
   if (!cin) {
	   return false;
   }

   // leer el resto de datos
   std::vector<int> v(N);
   int peso;

   for (int i = 0; i < N; i++) {
	   std::cin >> peso;
	   v[i] = peso;
   }

   std::sort(v.begin(), v.end());

   // resolver el problema (posiblemente utilizando otras funciones o clases)
   int sol = resolver(v, peso_maximo);

   // escribir la respuesta
   std::cout << sol << "\n";

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
