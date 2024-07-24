#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP


#include "fila_de_prioridade.hpp"
#include "grafo.hpp"

bool dijkstra(const Grafo &grafo, int origem, int destino, double energia, int maxPortaisUsaveis);

#endif // DIJKSTRA_HPP
