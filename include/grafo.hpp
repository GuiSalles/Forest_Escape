#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <cmath>

struct No {
    int rotulo;
    int peso;
    No* prox;
};

class Grafo {
public:
    Grafo(int numVertices);
    ~Grafo();
    void insereAresta(int u, int v, int peso);
    void insereVertice(int vertice, int x, int y);
    void inserePortal(int v1, int v2);
    double calculaDistancia(int u, int v) const;
    int quantidadeVertices() const;

    friend class Dijkstra;
    friend class AStar;

private:
    int nVertices;
    int nArestas;
    No** listaAdj;
    struct Coordenada {
        int x;
        int y;
    }* coordenadas;
};

#endif // GRAFO_HPP
