#include "algA.hpp"
#include "fila_de_prioridade.hpp"
#include "grafo.hpp"
#include <limits>
#include <cmath>

bool algA(const Grafo &grafo, int origem, int destino, double energia, int maxPortaisUsaveis) {
    int n = grafo.quantidadeVertices();
    int numEstados = n * (maxPortaisUsaveis + 1);

    double* distancias = new double[numEstados];
    double* heuristicas = new double[numEstados];
    int* portaisUsados = new int[numEstados];

    for (int i = 0; i < numEstados; ++i) {
        distancias[i] = std::numeric_limits<double>::infinity();
        heuristicas[i] = std::numeric_limits<double>::infinity();
        portaisUsados[i] = maxPortaisUsaveis + 1;
    }

    fila_de_prioridade<std::pair<double, std::pair<int, int>>> fila(numEstados);
    distancias[origem * (maxPortaisUsaveis + 1)] = 0.0;
    heuristicas[origem * (maxPortaisUsaveis + 1)] = grafo.calculaDistancia(origem, destino);
    portaisUsados[origem * (maxPortaisUsaveis + 1)] = 0;
    fila.inserir({0.0 + heuristicas[origem * (maxPortaisUsaveis + 1)], {origem, 0}});

    while (!fila.vazia()) {
        auto item = fila.remover();
        int u = item.second.first;
        int portaisUsadosAtual = item.second.second;

        if (u == destino) {
            delete[] distancias;
            delete[] heuristicas;
            delete[] portaisUsados;
            return distancias[destino * (maxPortaisUsaveis + 1) + portaisUsadosAtual] <= energia;
        }

        No* adj = grafo.obterListaAdj(u);
        while (adj) {
            int v = adj->rotulo;
            double peso = adj->peso;
            bool ehPortal = adj->ehPortal;
            int proximoPortaisUsados = portaisUsadosAtual + (ehPortal ? 1 : 0);

            if (proximoPortaisUsados <= maxPortaisUsaveis &&
                distancias[u * (maxPortaisUsaveis + 1) + portaisUsadosAtual] + peso < distancias[v * (maxPortaisUsaveis + 1) + proximoPortaisUsados]) {
                distancias[v * (maxPortaisUsaveis + 1) + proximoPortaisUsados] = distancias[u * (maxPortaisUsaveis + 1) + portaisUsadosAtual] + peso;
                heuristicas[v * (maxPortaisUsaveis + 1)] = grafo.calculaDistancia(v, destino);
                portaisUsados[v * (maxPortaisUsaveis + 1) + proximoPortaisUsados] = proximoPortaisUsados;
                fila.inserir({distancias[v * (maxPortaisUsaveis + 1) + proximoPortaisUsados] + heuristicas[v * (maxPortaisUsaveis + 1)], {v, proximoPortaisUsados}});
            }

            adj = adj->prox;
        }
    }

    delete[] distancias;
    delete[] heuristicas;
    delete[] portaisUsados;
    return false;
}
