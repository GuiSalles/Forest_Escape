#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <cmath>

struct No {
    int rotulo;
    double peso;
    No* prox;
    bool ehPortal;
};

struct Coordenada {
    double x;
    double y;
};

class Grafo {
public:
    Grafo(int nVertices);
    ~Grafo();
    void insereAresta(int u, int v, double peso, bool ehPortal);
    void inserePortal(int u, int v);
    void insereCoordenada(int u, double x, double y);
    double calculaDistancia(int u, int v) const;
    int quantidadeVertices() const;
    int tamanho() const;
    No* obterListaAdj(int u) const;
    Coordenada obterCoordenada(int v) const;

private:
    int nVertices;
    No** listaAdj;
    Coordenada* coordenadas;
};

#endif // GRAFO_HPP