#include <iostream>
#include "algA.hpp"
#include "dijkstra.hpp"
#include "grafo.hpp"

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    Grafo grafo(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        grafo.insereVertice(i, x, y);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        grafo.insereAresta(u, v, 1);
    }

    for (int i = 0; i < k; i++) {
        int u, v;
        std::cin >> u >> v;
        grafo.inserePortal(u, v);
    }

    double s;
    int q;
    std::cin >> s >> q;

    AStar aStar(grafo, q);
    Dijkstra dijkstra(grafo);

    bool caminhoDijkstra = false;
    bool caminhoAStar = false;

    int origem = 0;
    int destino = n - 1;
    dijkstra.calculaCaminho(origem, destino);
    if (dijkstra.getDistancia(destino) <= s) {
        caminhoDijkstra = true;
    }

    aStar.inicializa(origem);
    if (aStar.getDistancia(destino) <= s) {
        caminhoAStar = true;
    }

    std::cout << (caminhoDijkstra ? 1 : 0) << " " << (caminhoAStar ? 1 : 0) << std::endl;

    return 0;
}
