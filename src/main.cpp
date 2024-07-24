#include <iostream>
#include <sstream>
#include "dijkstra.hpp"
#include "algA.hpp"
#include "grafo.hpp"

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    Grafo grafo(n);

    for (int i = 0; i < n; ++i) {
        double x, y;
        std::cin >> x >> y;
        grafo.insereCoordenada(i, x, y);
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        double peso = grafo.calculaDistancia(u, v);
        grafo.insereAresta(u, v, peso, false);
    }

    for (int i = 0; i < k; ++i) {
        int u, v;
        std::cin >> u >> v;
        grafo.inserePortal(u, v);
    }

    int s, q;
    std::cin >> s >> q;

    bool resultadoDijkstra = dijkstra(grafo, 0, n - 1, s, q);
    std::cout << (resultadoDijkstra ? 1 : 0) << " ";

    bool resultadoAStar = algA(grafo, 0, n - 1, s, q);
    std::cout << (resultadoAStar ? 1 : 0);

    return 0;
}