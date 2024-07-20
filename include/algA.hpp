#ifndef ALGA_HPP
#define ALGA_HPP

#include "grafo.hpp"
#include "fila_prioridade.hpp"

class AStar {
public:
    AStar(const Grafo& g, int maxPortais); // Adicione o parâmetro maxPortais
    ~AStar();
    void calculaCaminho(int origem, int destino);
    int getDistancia(int destino) const;
    void getCaminho(int destino, int* caminho, int& tamCaminho) const;
    void inicializa(int origem);

private:
    const Grafo& grafo;
    int* dist;
    int* prev;
    bool* visitado;
    int nVertices;
    int maxPortais;
    FilaPrioridade fila;
    static const double INFINITO;
    double heuristica(int v, int destino) const;
};

#endif // ALGA_HPP
