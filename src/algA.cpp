#include "algA.hpp"
#include <cmath>

const double AStar::INFINITO = 1e10;

AStar::AStar(const Grafo& g, int maxPortais) : grafo(g), maxPortais(maxPortais), fila(g.quantidadeVertices()) { // Inicializando a fila
    nVertices = grafo.quantidadeVertices();
    dist = new int[nVertices];
    prev = new int[nVertices];
    visitado = new bool[nVertices];
}

AStar::~AStar() {
    delete[] dist;
    delete[] prev;
    delete[] visitado;
}

void AStar::inicializa(int origem) {
    for (int i = 0; i < nVertices; i++) {
        dist[i] = static_cast<int>(INFINITO);
        prev[i] = -1;
        visitado[i] = false;
    }
    dist[origem] = 0;
    fila.inserir(origem, 0);
}

void AStar::calculaCaminho(int origem, int destino) {
    inicializa(origem);

    while (!fila.vazia()) {
        int u = fila.extrairMin();
        if (u == destino) break;

        visitado[u] = true;
        No* adj = grafo.listaAdj[u];
        while (adj != nullptr) {
            int v = adj->rotulo;
            int peso = adj->peso;

            if (!visitado[v] && dist[u] != static_cast<int>(INFINITO) && dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
                prev[v] = u;
                fila.atualizarPrioridade(v, dist[v] + heuristica(v, destino));
            }
            adj = adj->prox;
        }
    }
}

double AStar::heuristica(int v, int destino) const {
    int x1 = grafo.coordenadas[v].x;
    int y1 = grafo.coordenadas[v].y;
    int x2 = grafo.coordenadas[destino].x;
    int y2 = grafo.coordenadas[destino].y;
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

int AStar::getDistancia(int destino) const {
    return dist[destino];
}

void AStar::getCaminho(int destino, int* caminho, int& tamCaminho) const {
    tamCaminho = 0;
    for (int v = destino; v != -1; v = prev[v]) {
        caminho[tamCaminho++] = v;
    }

    for (int i = 0; i < tamCaminho / 2; i++) {
        int temp = caminho[i];
        caminho[i] = caminho[tamCaminho - 1 - i];
        caminho[tamCaminho - 1 - i] = temp;
    }
}
