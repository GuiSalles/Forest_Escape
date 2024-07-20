#include "dijkstra.hpp"

Dijkstra::Dijkstra(const Grafo& g) : grafo(g), fila(g.quantidadeVertices()) {
    nVertices = grafo.quantidadeVertices();
    dist = new int[nVertices];
    prev = new int[nVertices];
    visitado = new bool[nVertices];
}

Dijkstra::~Dijkstra() {
    delete[] dist;
    delete[] prev;
    delete[] visitado;
}

void Dijkstra::inicializa(int origem) {
    for (int i = 0; i < nVertices; i++) {
        dist[i] = INFINITO;
        prev[i] = -1;
        visitado[i] = false;
    }
    dist[origem] = 0;
    fila.inserir(origem, 0);
}

void Dijkstra::calculaCaminho(int origem, int destino) {
    inicializa(origem);

    while (!fila.vazia()) {
        int u = fila.extrairMin();
        if (u == destino) break;

        visitado[u] = true;
        No* adj = grafo.listaAdj[u];
        while (adj != nullptr) {
            int v = adj->rotulo;
            int peso = adj->peso;

            if (!visitado[v] && dist[u] != INFINITO && dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
                prev[v] = u;
                fila.atualizarPrioridade(v, dist[v]);
            }
            adj = adj->prox;
        }
    }
}

int Dijkstra::getDistancia(int destino) const {
    return dist[destino];
}

void Dijkstra::getCaminho(int destino, int* caminho, int& tamCaminho) const {
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
