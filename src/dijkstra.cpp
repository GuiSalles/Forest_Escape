#include "dijkstra.hpp"
#include "fila_de_prioridade.hpp"
#include "grafo.hpp"
#include <limits>
#include <cmath>

bool dijkstra(const Grafo &grafo, int origem, int destino, double energia, int maxPortaisUsaveis) {
    int n = grafo.quantidadeVertices();
    int numEstados = n * (maxPortaisUsaveis + 1);
    
    double* distancias = new double[numEstados];
    int* portaisUsados = new int[numEstados];

    for (int i = 0; i < numEstados; ++i) {
        distancias[i] = std::numeric_limits<double>::infinity();
        portaisUsados[i] = maxPortaisUsaveis + 1;
    }

    fila_de_prioridade<std::pair<double, std::pair<int, int>>> fila(numEstados);
    distancias[origem * (maxPortaisUsaveis + 1)] = 0.0;
    portaisUsados[origem * (maxPortaisUsaveis + 1)] = 0;
    fila.inserir({0.0, {origem, 0}});

    while (!fila.vazia()) {
        auto item = fila.remover();
        double custoAtual = item.first;
        int u = item.second.first;
        int portaisUsadosAtual = item.second.second;

        if (u == destino) {
            delete[] distancias;
            delete[] portaisUsados;
            return custoAtual <= energia;
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
                portaisUsados[v * (maxPortaisUsaveis + 1) + proximoPortaisUsados] = proximoPortaisUsados;
                fila.inserir({distancias[v * (maxPortaisUsaveis + 1) + proximoPortaisUsados], {v, proximoPortaisUsados}});
            }

            adj = adj->prox;
        }
    }

    delete[] distancias;
    delete[] portaisUsados;
    return false;
}
