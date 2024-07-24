#include "grafo.hpp"

Grafo::Grafo(int nVertices) : nVertices(nVertices) {
    listaAdj = new No*[nVertices];
    coordenadas = new Coordenada[nVertices];
    for (int i = 0; i < nVertices; ++i) {
        listaAdj[i] = nullptr;
    }
}

Grafo::~Grafo() {
    for (int i = 0; i < nVertices; ++i) {
        No* atual = listaAdj[i];
        while (atual) {
            No* temp = atual;
            atual = atual->prox;
            delete temp;
        }
    }
    delete[] listaAdj;
    delete[] coordenadas;
}

void Grafo::insereAresta(int u, int v, double peso, bool ehPortal) {
    No* novaAresta = new No{v, peso, listaAdj[u], ehPortal};
    listaAdj[u] = novaAresta;
}

void Grafo::inserePortal(int u, int v) {
    insereAresta(u, v, 0.0, true);
}

void Grafo::insereCoordenada(int u, double x, double y) {
    coordenadas[u] = Coordenada{x, y};
}

double Grafo::calculaDistancia(int u, int v) const {
    double dx = coordenadas[u].x - coordenadas[v].x;
    double dy = coordenadas[u].y - coordenadas[v].y;
    return std::sqrt(dx * dx + dy * dy);
}

int Grafo::quantidadeVertices() const {
    return nVertices;
}

No* Grafo::obterListaAdj(int u) const {
    return listaAdj[u];
}

Coordenada Grafo::obterCoordenada(int v) const {
    return coordenadas[v];
}