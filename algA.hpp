#ifndef ALGA_HPP
#define ALGA_HPP

#include "grafo.hpp"
#include "fila_prioridade.hpp"

class AStar {
public:
    AStar(const Grafo& g);
    ~AStar();
    void calculaCaminho(int origem, int destino);
    int getDistancia(int destino) const;
    void getCaminho(int destino, int* caminho, int& tamCaminho) const;

private:
    const Grafo& grafo;
    int* dist;
    int* prev;
    bool* visitado;
    int nVertices;
    static const int INFINITO = 1000000;
    FilaPrioridade fila;

    double heuristica(int v, int destino) const;
    void inicializa(int origem);
};

#endif ALGA_HPP
