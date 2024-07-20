#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "grafo.hpp"
#include "fila_prioridade.hpp"

class Dijkstra {
public:
    Dijkstra(const Grafo& g);
    ~Dijkstra();
    void calculaCaminho(int origem, int destino);
    int getDistancia(int destino) const;
    void getCaminho(int destino, int* caminho, int& tamCaminho) const;

private:
    const Grafo& grafo;
    int* dist;
    int* prev;
    bool* visitado;
    int nVertices;
    FilaPrioridade fila;
    static const int INFINITO;

    void inicializa(int origem);
};

#endif // DIJKSTRA_HPP
