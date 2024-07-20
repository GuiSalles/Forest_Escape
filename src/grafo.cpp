#include "grafo.hpp"

Grafo::Grafo(int numVertices) {
    nVertices = numVertices;
    nArestas = 0;
    listaAdj = new No*[nVertices];
    coordenadas = new Coordenada[nVertices];

    for (int i = 0; i < nVertices; i++) {
        listaAdj[i] = nullptr;
    }
}

Grafo::~Grafo() {
    for (int i = 0; i < nVertices; i++) {
        No* atual = listaAdj[i];
        while (atual != nullptr) {
            No* aux = atual;
            atual = atual->prox;
            delete aux;
        }
    }
    delete[] listaAdj;
    delete[] coordenadas;
}

void Grafo::insereAresta(int u, int v, int peso) {
    No* newNo = new No{v, peso, listaAdj[u]};
    listaAdj[u] = newNo;
    nArestas++;
}

void Grafo::insereVertice(int vertice, int x, int y) {
    coordenadas[vertice] = Coordenada{x, y};
}

void Grafo::inserePortal(int v1, int v2) {
    insereAresta(v1, v2, 0);
    insereAresta(v2, v1, 0);
}

double Grafo::calculaDistancia(int u, int v) const {
    int x1 = coordenadas[u].x;
    int y1 = coordenadas[u].y;
    int x2 = coordenadas[v].x;
    int y2 = coordenadas[v].y;
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

int Grafo::quantidadeVertices() const {
    return nVertices;
}
