
// PABLO AGUDO BRUN

// comentario sobre la solución, incluyendo el análisis del coste

/*
Al tratarse de un grafo no dirigido podemos aplicar PRIM ya que aplicando este algoritmo obtenemos el
arbol de recorrido minimo (mst) que en este ejercicio viene a ser el coste de pavimentar las minimas calles
posibles.
Para ir calculando el coste minimo para pavimentar la calle o no, partimos desde cualquiera de los vertices,
ya que no nos dan uno de partida, y a continuacion evaluamos los costes de sus aristas eligiendo y marcando
la arista minima a traves de nuestra "pq".
Hablando del coste, este algoritmo tiene un coste de ElogV siendo:
	E -> numero de aristas del grafo
	logV -> las operaciones que se hacen sobre cada una de esas aristas
*/

#include "GrafoValorado.h"
#include "Camino.h"

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


bool resuelveCaso() {
   
   int V, E;
   std::cin >> V;

   if (!std::cin)
      return false;
   
   // leer grafo
   GrafoValorado<int> grafo(V);
   std::cin >> E;

   int v, w, valor;

   for (int i = 0; i < E; i++) {
	   std::cin >> v >> w >> valor;
	   grafo.ponArista({v-1, w-1, valor});
   }

   // resolver el problema (utilizando otras funciones o clases)
   Camino camino(grafo);

   // escribir la respuesta
   if (camino.getEsPosible()) {
	   std::cout << camino.getCoste() << "\n";
   }
   else {
	   std::cout << "Imposible\n";
   }

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
